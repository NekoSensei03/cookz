modded class Cooking
{
    // non edible items or edible items that have no food stage that should still be processed (based on gained temperature)
    static ref array<typename> NON_EDIBLE_ITEMS = { Rag, BandageDressing, DisinfectantAlcohol, Rice, PowderedMilk, SodaCan_ColorBase, Snack_ColorBase, Bone };

    //COOKING PROCESS
    //--- Cooking with equipment (pot)
    //Returns 1 if the item changed its cooking stage, 0 if not
    override int CookWithEquipment(ItemBase cooking_equipment, float cooking_time_coef = 1)
    {
        //check cooking conditions
        if (cooking_equipment == null)
        {
            return 0;
        }
        
        if (cooking_equipment.IsRuined())
        {
            return 0;
        }

        CookZ_Recipe dish = CookZ_GetCookbook().GetDishForIngredients(cooking_equipment);
        if (!dish)
        {
            return super.CookWithEquipment(cooking_equipment, cooking_time_coef);
        }

        CargoBase cargo = cooking_equipment.GetInventory().GetCargo();
        if (!cargo)
        {
            return 0;
        }
        bool is_empty = cargo.GetItemCount() == 0;

        //manage items in cooking equipment
        Param2<bool, bool> stateFlags = new Param2<bool, bool>(false, false); // 1st - done; 2nd - burned
        Param2<CookingMethodType, float> cookingMethodWithTime = GetCookingMethodWithTimeOverride(cooking_equipment);
        bool done = false;
        bool burned = false;

        //! cooking time coef override
        if (cooking_time_coef != 1)
        {
            cookingMethodWithTime.param2 = cooking_time_coef;
        }

        //process items
        for (int i = 0; i < cargo.GetItemCount(); i++)
        {
            ItemBase itemToCook = ItemBase.Cast(cargo.GetItem(i));
            CookZ_ProcessItemToCook(itemToCook, cooking_equipment, cookingMethodWithTime, stateFlags);
            done = done || stateFlags.param1;
            burned = burned || stateFlags.param2;
        }

        if (!dish.doNotReplaceIngredients && done && !burned)
        {
            // clear all items from cooking equipment (bottom to top for index safety)
            int sumQuantity = 0;
            for (int j = cargo.GetItemCount() - 1; j >= 0; j--)
            {
                ItemBase usedItem = ItemBase.Cast(cargo.GetItem(j));
                if (usedItem)
                {
					int itemQuantity = usedItem.GetQuantity();
                    if (usedItem.IsSplitable())
                    {
                        int perItemQuantity = usedItem.ConfigGetInt("cookz_staticQuantity");
                        if (perItemQuantity == 0)
                        {
                            perItemQuantity = 100;
                        }
                        sumQuantity += (itemQuantity * perItemQuantity);
                    }
                    else
                    {
                        int staticQuantity = usedItem.ConfigGetInt("cookz_staticQuantity");
                        if (staticQuantity > 0)
                        {
                            // use static quantity if defined
                            itemQuantity = staticQuantity;
                        }
                        if (itemQuantity == 0)
                        {
                            // fallback if no quantity found
                            itemQuantity = 100;
                    	}
                        sumQuantity += itemQuantity;
                    }
                    cooking_equipment.GetInventory().LocalDestroyEntity(usedItem);
                }
            }
            // remove ALL liquid for now so that spawned items will not get wet
            cooking_equipment.AddQuantity(-cooking_equipment.GetQuantity());
            // add dish to cooking equipment
            int quantityPerDish = sumQuantity / dish.numDishes;
            for (int k = 0; k < dish.numDishes; k++)
            {
                EntityAI createdDish = cooking_equipment.GetInventory().CreateInInventory(dish.name);
                createdDish.SetTemperature(80);
                CookZ_ClosedDish createdClosedDish = CookZ_ClosedDish.Cast(createdDish);
                if (createdClosedDish)
                {
                    // will be transfered to opened dish
                    createdClosedDish.CookZ_SetQuantity(quantityPerDish);
                    continue;
                }
                ItemBase createdEdibleDish = ItemBase.Cast(createdDish);
                if (createdEdibleDish)
                {
                    createdEdibleDish.SetQuantity(quantityPerDish);
                    continue;
                }
            }
            // update empty can quantity
            if (dish.needsEmptyCan)
            {
                ItemBase emptyCans = ItemBase.Cast(cooking_equipment.FindAttachmentBySlotName("CookZ_EmptyCans"));
                if (emptyCans)
                {
                    emptyCans.SetQuantity(emptyCans.GetQuantity() - 1);
                }
            }
            // update empty box quantity
            if (dish.needsEmptyBox)
            {
                ItemBase emptyBoxes = ItemBase.Cast(cooking_equipment.FindAttachmentBySlotName("CookZ_EmptyBoxes"));
                if (emptyBoxes)
                {
                    emptyBoxes.SetQuantity(emptyBoxes.GetQuantity() - 1);
                }
            }
        }

        //manage cooking equipment
        Bottle_Base bottle_base = Bottle_Base.Cast(cooking_equipment);
        if (bottle_base)
        {
            float cookingEquipmentTemp = cooking_equipment.GetTemperature();

            //handle water boiling
            if (cookingEquipmentTemp >= LIQUID_BOILING_POINT)
            {
                //remove agents
                cooking_equipment.RemoveAllAgents();

                if (cooking_equipment.GetQuantity() > 0)
                {
                    //vaporize liquid
                    cooking_equipment.AddQuantity(-LIQUID_VAPOR_QUANTITY);
                }
            }

            //handle audio visuals
            bottle_base.RefreshAudioVisualsOnClient(cookingMethodWithTime.param1, done, is_empty, burned);
        }

        FryingPan frying_pan = FryingPan.Cast(cooking_equipment);
        if (frying_pan && !bottle_base)
        {
            //handle audio visuals
            frying_pan.RefreshAudioVisualsOnClient(cookingMethodWithTime.param1, done, is_empty, burned);
        }

        return 1;
    }

    void CookZ_ProcessItemToCook(notnull ItemBase pItem, ItemBase cookingEquip, Param2<CookingMethodType, float> pCookingMethod, out Param2<bool, bool> pStateFlags)
    {
        Edible_Base item_to_cook = Edible_Base.Cast(pItem);
        
        //! state flags are in order: is_done, is_burned
        pStateFlags = new Param2<bool, bool>(false, false);
                
        if (item_to_cook && item_to_cook.CanBeCooked())
        {
            //! enable cooking SoundEvent
            item_to_cook.MakeSoundsOnClient(true, pCookingMethod.param1);

            //! update food
            CooKZ_UpdateCookingState(item_to_cook, pCookingMethod.param1, cookingEquip, pCookingMethod.param2);
            
            //check for done state for boiling and drying
            if (item_to_cook.IsFoodBoiled() || item_to_cook.IsFoodDried())
            {
                pStateFlags.param1 = true;
            }
            //! check for done state from baking (exclude Lard from baked items)
            else if (item_to_cook.IsFoodBaked() && item_to_cook.Type() != Lard)
            {
                pStateFlags.param1 = true;
            }
            //! check for burned state
            else if (item_to_cook.IsFoodBurned())
            {
                pStateFlags.param2 = true;
            }
        }
        else if (item_to_cook && item_to_cook.GetFoodStage()) // edible, but not cookable
        {
            if (CookZ_IsNonCookableFinished(item_to_cook, cookingEquip, pCookingMethod.param2))
            {
                pStateFlags.param1 = true;
            }
        }
        else if (NonEdibleItemToProcess(pItem.Type())) // not edible, but flagged to be processed
        {
            if (CookZ_IsNonEdibleFinished(pItem, cookingEquip))
            {
                pStateFlags.param1 = true;
            }
        }
        else // vanilla processing of non edible items
        {
            // this is vanilla - do not do it here so that items will not ruin before cooking finished
            //pItem.DecreaseHealth("", "", PARAM_BURN_DAMAGE_COEF * 100);
            AddTemperatureToItem(pItem, null, 0);
        }
    }

    bool NonEdibleItemToProcess(typename typeToCheck) {
        foreach (typename excludeType : NON_EDIBLE_ITEMS) {
            if (typeToCheck == excludeType) {
                return true;
            }
        }
        return false;
    }

    //This is a dumped down version of Cooking.UpdateCookingState for items that are edible but not cookable (edible_item.CanBeCooked() == false)
    //AND have a food stage (here the cooking time is stored).
    //The cooking is seen as finished after some time passed. But there is no actual state change in the food.
    //Can be used for items like worms
    protected bool CookZ_IsNonCookableFinished(Edible_Base item_to_cook, ItemBase cooking_equipment, float cooking_time_coef)
    {
        float item_temperature = item_to_cook.GetTemperature();
        float item_min_temp     = 100;
        float item_time_to_cook = 40;
        
        //add temperature
        AddTemperatureToItem(item_to_cook, cooking_equipment, 0);
        
        //add cooking time if the food can be cooked by this method
        if (item_temperature >= item_min_temp)
        {
            float new_cooking_time = item_to_cook.GetCookingTime() + COOKING_FOOD_TIME_INC_VALUE * cooking_time_coef;
            item_to_cook.SetCookingTime(new_cooking_time);
            
            if (item_to_cook.GetCookingTime() >= item_time_to_cook)
            {
                item_to_cook.SetCookingTime(0);
                return true;
            }
        }
        
        return false;
    }

    //This is a dumped down version of Cooking.UpdateCookingState for items that are not edible.
    //Slowly add temperature to the item. Item is finished when temp is 100 - basically use the temperature as a timer.
    //Used for non edible items, e.g. rags (disinfect) or edible items without a food stage, e.g. disinfected alcohol, rice, powdered milk.
    protected bool CookZ_IsNonEdibleFinished(ItemBase pItem, ItemBase cooking_equipment)
    {
        if (!pItem || !cooking_equipment)
        {
            return false;
        }

        float item_finished_temperature = 100;
        
        if (pItem.GetTemperatureMax() >= FireplaceBase.PARAM_ITEM_HEAT_MIN_TEMP)
        {
            float item_temperature = pItem.GetTemperature();
            float equipment_cooking_temp = cooking_equipment.GetTemperature();
            
            //add temperature
            if (equipment_cooking_temp > item_temperature)
            {
                item_temperature += 25;
                item_temperature = Math.Clamp( item_temperature, 0, FOOD_MAX_COOKING_TEMPERATURE );
                
                //set new temperature
                if ( GetGame() && GetGame().IsServer() )
                {
                    pItem.SetTemperature( item_temperature );
                }
            }
        }
        
        if (item_temperature >= item_finished_temperature)
        {
            // disinfect rags, bandages
            if (pItem.Type() == Rag || pItem.Type() == BandageDressing)
            {
                pItem.RemoveAllAgentsExcept(eAgents.BRAIN);
                pItem.SetCleanness(1);
            }

            return true;
        }

        return false;
    }

    // edits
    //    do not decrese quantity baking when not using lard
    //    do not decrease lard quantity
    protected int CooKZ_UpdateCookingState(Edible_Base item_to_cook, CookingMethodType cooking_method, ItemBase cooking_equipment, float cooking_time_coef)
    {
        //food properties
        float food_temperature = item_to_cook.GetTemperature();
        
        //{min_temperature, time_to_cook, max_temperature (optional)}
        //get next stage name - if next stage is not defined, next stage name will be empty "" and no cooking properties (food_min_temp, food_time_to_cook, food_max_temp) will be set
        FoodStageType new_stage_type = item_to_cook.GetNextFoodStageType(cooking_method);

        float food_min_temp     = 0;
        float food_time_to_cook = 0;
        float food_max_temp     = -1;
        
        //Set next stage cooking properties if next stage possible
        if (item_to_cook.CanChangeToNewStage(cooking_method)) // new_stage_type != NONE
        {
            array<float> next_stage_cooking_properties = new array<float>();
            next_stage_cooking_properties = FoodStage.GetAllCookingPropertiesForStage(new_stage_type, null, item_to_cook.GetType());
            
            food_min_temp = next_stage_cooking_properties.Get(eCookingPropertyIndices.MIN_TEMP);
            food_time_to_cook = next_stage_cooking_properties.Get(eCookingPropertyIndices.COOK_TIME);
            // The last element is optional and might not exist
            if (next_stage_cooking_properties.Count() > 2)
            {
                food_max_temp = next_stage_cooking_properties.Get(eCookingPropertyIndices.MAX_TEMP);
            }
        }
        
        //add temperature
        AddTemperatureToItem(item_to_cook, cooking_equipment, food_min_temp);
        
        //add cooking time if the food can be cooked by this method
        if (food_min_temp > 0 && food_temperature >= food_min_temp)
        {
            float new_cooking_time = item_to_cook.GetCookingTime() + COOKING_FOOD_TIME_INC_VALUE * cooking_time_coef;
            item_to_cook.SetCookingTime(new_cooking_time);
            
            //progress to next stage
            if (item_to_cook.GetCookingTime() >= food_time_to_cook)
            {
                //if max temp is defined check next food stage
                if (food_max_temp >= 0)
                {
                    if (food_temperature > food_max_temp && item_to_cook.GetFoodStageType() != FoodStageType.BURNED)
                    {
                        new_stage_type = FoodStageType.BURNED;
                    }
                }
                
                //! Change food stage
                item_to_cook.ChangeFoodStage(new_stage_type);
                //! Remove all modifiers
                item_to_cook.RemoveAllAgentsExcept(eAgents.BRAIN);
                //reset cooking time
                item_to_cook.SetCookingTime(0);

                return 1;
            }
        }
        
        return 0;
    }
}
