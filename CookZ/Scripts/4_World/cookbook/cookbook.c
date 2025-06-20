ref CookZ_Cookbook cookz_cookbook;
CookZ_Cookbook CookZ_GetCookbook()
{
    if (!cookz_cookbook)
    {
        cookz_cookbook = new CookZ_Cookbook();
    }

    return cookz_cookbook;
}

class CookZ_IngredientInEquipment
{
    int quantity;
    int numItems;
}

class CookZ_Cookbook
{
    typename COOKING_EQUIPMENT_POT                            = Pot;
    typename COOKING_EQUIPMENT_FRYINGPAN                      = FryingPan;
    typename COOKING_EQUIPMENT_CAULDRON                       = Cauldron;

    static const string COOKING_INGREDIENT_POTATO                    = "Potato";
    static const string COOKING_INGREDIENT_GREEN_BELL_PEPPER         = "GreenBellPepper";
    static const string COOKING_INGREDIENT_ZUCCHINI                  = "Zucchini";
    static const string COOKING_INGREDIENT_TOMATO                    = "Tomato";
    static const string COOKING_INGREDIENT_PUMPKIN                   = "Pumpkin";
    static const string COOKING_INGREDIENT_SLICED_PUMPKIN            = "SlicedPumpkin";

    static const string COOKING_INGREDIENT_PLUM                      = "Plum";
    static const string COOKING_INGREDIENT_PEAR                      = "Pear";
    static const string COOKING_INGREDIENT_APPLE                     = "Apple";
    static const string COOKING_INGREDIENT_BANANA                    = "Banana";
    static const string COOKING_INGREDIENT_ORANGE                    = "Orange";
    static const string COOKING_INGREDIENT_KIWI                      = "Kiwi";

    static const string COOKING_INGREDIENT_PIG_STEAK_MEAT            = "PigSteakMeat";
    static const string COOKING_INGREDIENT_WOLF_STEAK_MEAT           = "WolfSteakMeat";
    static const string COOKING_INGREDIENT_GOAT_STEAK_MEAT           = "GoatSteakMeat";
    static const string COOKING_INGREDIENT_BEAR_STEAK_MEAT           = "BearSteakMeat";
    static const string COOKING_INGREDIENT_SHEEP_STEAK_MEAT          = "SheepSteakMeat";
    static const string COOKING_INGREDIENT_BOAR_STEAK_MEAT           = "BoarSteakMeat";
    static const string COOKING_INGREDIENT_COW_STEAK_MEAT            = "CowSteakMeat";
    static const string COOKING_INGREDIENT_HUMAN_STEAK_MEAT          = "HumanSteakMeat";
    static const string COOKING_INGREDIENT_DEER_STEAK_MEAT           = "DeerSteakMeat";
    static const string COOKING_INGREDIENT_RABBIT_LEG_MEAT           = "RabbitLegMeat";
    static const string COOKING_INGREDIENT_CHICKEN_BREAST_MEAT       = "ChickenBreastMeat";
    static const string COOKING_INGREDIENT_REINDEER_STEAK_MEAT       = "ReindeerSteakMeat";
    static const string COOKING_INGREDIENT_FOX_STEAK_MEAT            = "FoxSteakMeat";

    static const string COOKING_INGREDIENT_CARP_FILLET_MEAT            = "CarpFilletMeat";
    static const string COOKING_INGREDIENT_MACKEREL_FILLET_MEAT        = "MackerelFilletMeat";
    static const string COOKING_INGREDIENT_SARDINES                    = "Sardines";
    static const string COOKING_INGREDIENT_BITTERLINGS                 = "Bitterlings";
    static const string COOKING_INGREDIENT_WALLEYE_POLLOCK_FILLET_MEAT = "WalleyePollockFilletMeat";
    static const string COOKING_INGREDIENT_STEELHEAD_TROUT_FILLET_MEAT = "SteelheadTroutFilletMeat";

    static const string COOKING_INGREDIENT_AGARICUS_MUSHROOM         = "AgaricusMushroom";
    static const string COOKING_INGREDIENT_AURICULARIA_MUSHROOM      = "AuriculariaMushroom";
    static const string COOKING_INGREDIENT_BOLETUS_MUSHROOM          = "BoletusMushroom";
    static const string COOKING_INGREDIENT_LACTARIUS_MUSHROOM        = "LactariusMushroom";
    static const string COOKING_INGREDIENT_MACROLEPIOTA_MUSHROOM     = "MacrolepiotaMushroom";
    static const string COOKING_INGREDIENT_PLEUROTUS_MUSHROOM        = "PleurotusMushroom";
    static const string COOKING_INGREDIENT_AMANITA_MUSHROOM          = "AmanitaMushroom";
    static const string COOKING_INGREDIENT_PSILOCYBE_MUSHROOM        = "PsilocybeMushroom";
    static const string COOKING_INGREDIENT_CRATERELLUS_MUSHROOM      = "CraterellusMushroom";

    static const string COOKING_INGREDIENT_BEEF_SAUSAGE              = "CookZ_Beef_Sausage";
    static const string COOKING_INGREDIENT_CHICKEN_SAUSAGE           = "CookZ_Chicken_Sausage";
    static const string COOKING_INGREDIENT_PIG_SAUSAGE               = "CookZ_Pig_Sausage";
    static const string COOKING_INGREDIENT_GOAT_SAUSAGE              = "CookZ_Goat_Sausage";
    static const string COOKING_INGREDIENT_BEAR_SAUSAGE              = "CookZ_Bear_Sausage";
    static const string COOKING_INGREDIENT_SHEEP_SAUSAGE             = "CookZ_Sheep_Sausage";
    static const string COOKING_INGREDIENT_BOAR_SAUSAGE              = "CookZ_Boar_Sausage";
    static const string COOKING_INGREDIENT_DEER_SAUSAGE              = "CookZ_Deer_Sausage";
    static const string COOKING_INGREDIENT_HARE_SAUSAGE              = "CookZ_Hare_Sausage";
    static const string COOKING_INGREDIENT_WOLF_SAUSAGE              = "CookZ_Wolf_Sausage";
    static const string COOKING_INGREDIENT_HUMAN_SAUSAGE             = "CookZ_Human_Sausage";
    static const string COOKING_INGREDIENT_FOX_SAUSAGE               = "CookZ_Fox_Sausage";
    static const string COOKING_INGREDIENT_REINDEER_SAUSAGE          = "CookZ_Reindeer_Sausage";
    
    static const string COOKING_INGREDIENT_CRACKERS                  = "Crackers";
    static const string COOKING_INGREDIENT_SALTY_STICKS              = "SaltySticks";

    static const string COOKING_INGREDIENT_RAG                       = "Rag";
    static const string COOKING_INGREDIENT_BANDAGE_DRESSING          = "BandageDressing";

    static const string COOKING_INGREDIENT_BLOOD_BAG_FULL            = "BloodBagFull";
    static const string COOKING_INGREDIENT_BLOOD_BAG_IV              = "BloodBagIV";

    static const string COOKING_INGREDIENT_ANY_MEAT           = "AnyMeat";
    static const string COOKING_INGREDIENT_ANY_FRUIT          = "AnyFruit";
    static const string COOKING_INGREDIENT_ANY_VEG            = "AnyVeg";
    static const string COOKING_INGREDIENT_ANY_FISH           = "AnyFish";
    static const string COOKING_INGREDIENT_ANY_FISH_FILLET    = "AnyFishFillet";
    static const string COOKING_INGREDIENT_ANY_MUSHROOM       = "AnyMushroom";
    static const string COOKING_INGREDIENT_ANY_SAUSAGE        = "AnySausage";
    static const string COOKING_INGREDIENT_ANY_DISINFECT      = "AnyDisinfect";
    static const string COOKING_INGREDIENT_ANY_BREADCRUMB     = "AnyBreadcrumb";
    static const string COOKING_INGREDIENT_ANY_BLOOD          = "AnyBlood";

    static ref map<string, ref array<string>> anyIngredientMap = InitAnyIngredientMap();
    static map<string, ref array<string>> InitAnyIngredientMap()
    {
        map<string, ref array<string>> tempMap = new map<string, ref array<string>>;
        tempMap.Insert(COOKING_INGREDIENT_ANY_MEAT, {
            COOKING_INGREDIENT_PIG_STEAK_MEAT,
            COOKING_INGREDIENT_WOLF_STEAK_MEAT,
            COOKING_INGREDIENT_GOAT_STEAK_MEAT,
            COOKING_INGREDIENT_BEAR_STEAK_MEAT,
            COOKING_INGREDIENT_SHEEP_STEAK_MEAT,
            COOKING_INGREDIENT_BOAR_STEAK_MEAT,
            COOKING_INGREDIENT_COW_STEAK_MEAT,
            COOKING_INGREDIENT_HUMAN_STEAK_MEAT,
            COOKING_INGREDIENT_DEER_STEAK_MEAT,
            COOKING_INGREDIENT_RABBIT_LEG_MEAT,
            COOKING_INGREDIENT_CHICKEN_BREAST_MEAT,
            COOKING_INGREDIENT_REINDEER_STEAK_MEAT,
            COOKING_INGREDIENT_FOX_STEAK_MEAT
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_FRUIT, {
            COOKING_INGREDIENT_PLUM,
            COOKING_INGREDIENT_PEAR,
            COOKING_INGREDIENT_APPLE,
            COOKING_INGREDIENT_BANANA,
            COOKING_INGREDIENT_ORANGE,
            COOKING_INGREDIENT_KIWI
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_VEG, {
            COOKING_INGREDIENT_POTATO,
            COOKING_INGREDIENT_GREEN_BELL_PEPPER,
            COOKING_INGREDIENT_ZUCCHINI,
            COOKING_INGREDIENT_TOMATO,
            COOKING_INGREDIENT_PUMPKIN,
            COOKING_INGREDIENT_SLICED_PUMPKIN
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_FISH, {
            COOKING_INGREDIENT_CARP_FILLET_MEAT,
            COOKING_INGREDIENT_MACKEREL_FILLET_MEAT,
            COOKING_INGREDIENT_SARDINES,
            COOKING_INGREDIENT_BITTERLINGS,
            COOKING_INGREDIENT_WALLEYE_POLLOCK_FILLET_MEAT,
            COOKING_INGREDIENT_STEELHEAD_TROUT_FILLET_MEAT
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_FISH_FILLET, {
            COOKING_INGREDIENT_CARP_FILLET_MEAT,
            COOKING_INGREDIENT_MACKEREL_FILLET_MEAT,
            COOKING_INGREDIENT_WALLEYE_POLLOCK_FILLET_MEAT,
            COOKING_INGREDIENT_STEELHEAD_TROUT_FILLET_MEAT
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_MUSHROOM, {
            COOKING_INGREDIENT_AGARICUS_MUSHROOM,
            COOKING_INGREDIENT_AURICULARIA_MUSHROOM,
            COOKING_INGREDIENT_BOLETUS_MUSHROOM,
            COOKING_INGREDIENT_LACTARIUS_MUSHROOM,
            COOKING_INGREDIENT_MACROLEPIOTA_MUSHROOM,
            COOKING_INGREDIENT_PLEUROTUS_MUSHROOM,
            COOKING_INGREDIENT_AMANITA_MUSHROOM,
            COOKING_INGREDIENT_PSILOCYBE_MUSHROOM,
            COOKING_INGREDIENT_CRATERELLUS_MUSHROOM
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_SAUSAGE, {
            COOKING_INGREDIENT_BEEF_SAUSAGE,
            COOKING_INGREDIENT_CHICKEN_SAUSAGE,
            COOKING_INGREDIENT_PIG_SAUSAGE,
            COOKING_INGREDIENT_GOAT_SAUSAGE,
            COOKING_INGREDIENT_BEAR_SAUSAGE,
            COOKING_INGREDIENT_SHEEP_SAUSAGE,
            COOKING_INGREDIENT_BOAR_SAUSAGE,
            COOKING_INGREDIENT_DEER_SAUSAGE,
            COOKING_INGREDIENT_HARE_SAUSAGE,
            COOKING_INGREDIENT_WOLF_SAUSAGE,
            COOKING_INGREDIENT_HUMAN_SAUSAGE,
            COOKING_INGREDIENT_FOX_SAUSAGE,
            COOKING_INGREDIENT_REINDEER_SAUSAGE
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_DISINFECT, {
            COOKING_INGREDIENT_RAG,
            COOKING_INGREDIENT_BANDAGE_DRESSING
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_BREADCRUMB, {
            COOKING_INGREDIENT_CRACKERS,
            COOKING_INGREDIENT_SALTY_STICKS
        });
        tempMap.Insert(COOKING_INGREDIENT_ANY_BLOOD, {
            COOKING_INGREDIENT_BLOOD_BAG_FULL,
            COOKING_INGREDIENT_BLOOD_BAG_IV
        });
        return tempMap;
    }

    ref array<ref CookZ_Recipe> allRecipes;

    void CookZ_Cookbook()
    {
        allRecipes = new array<ref CookZ_Recipe>();
        LoadRecipesFromConfig();
    }

    void LoadRecipesFromConfig()
    {
        string recipesPath = "CfgVehicles CookZ_Recipes";

        int recipeCount = GetGame().ConfigGetChildrenCount(recipesPath);
        for (int i = 0; i < recipeCount; i++)
        {
            string recipeName;
            GetGame().ConfigGetChildName(recipesPath, i, recipeName);

            string allowPot = "";
            string allowCauldron = "";
            string allowPan = "";
            string needsWater = "";
            string needsEmptyCan = "";
            string needsEmptyBox = "";
            string doNotReplaceIngredients = "";
            string canBeOpened = "";
            GetGame().ConfigGetText(string.Format("%1 %2 allowPot", recipesPath, recipeName), allowPot);
            GetGame().ConfigGetText(string.Format("%1 %2 allowCauldron", recipesPath, recipeName), allowCauldron);
            GetGame().ConfigGetText(string.Format("%1 %2 allowPan", recipesPath, recipeName), allowPan);
            GetGame().ConfigGetText(string.Format("%1 %2 needsWater", recipesPath, recipeName), needsWater);
            GetGame().ConfigGetText(string.Format("%1 %2 needsEmptyCan", recipesPath, recipeName), needsEmptyCan);
            GetGame().ConfigGetText(string.Format("%1 %2 needsEmptyBox", recipesPath, recipeName), needsEmptyBox);
            GetGame().ConfigGetText(string.Format("%1 %2 doNotReplaceIngredients", recipesPath, recipeName), doNotReplaceIngredients);
            GetGame().ConfigGetText(string.Format("%1 %2 canBeOpened", recipesPath, recipeName), canBeOpened);
            int numDishes = GetGame().ConfigGetInt(string.Format("%1 %2 numDishes", recipesPath, recipeName));
            if (!numDishes)
            {
                numDishes = 1;
            }

            CookZ_Recipe recipe = new CookZ_Recipe(recipeName, allowPot == "true", allowCauldron == "true", allowPan == "true", needsWater == "true", needsEmptyCan == "true", needsEmptyBox == "true", doNotReplaceIngredients == "true", canBeOpened == "true", numDishes);

            array<string> ingredientsArray = new array<string>;
            GetGame().ConfigGetTextArray(string.Format("%1 %2 ingredients", recipesPath, recipeName), ingredientsArray);

            foreach (string ingredientData : ingredientsArray)
            {
                array<string> parts = new array<string>;
                ingredientData.Split(",", parts);

                if (parts.Count() == 2)
                {
                    string name = parts[0];
                    int quantity = parts[1].ToInt();

                    recipe.AddIngredient(new CookZ_Ingredient(name, quantity));
                }
            }

            allRecipes.Insert(recipe);

            // only for development when new recipes are added to calculate nutrition values
            //CalculateNutritionValues(recipe);
        }
    }

    // returns a recipe or null if no valid recipe detected
    CookZ_Recipe GetDishForIngredients(ItemBase cooking_equipment)
    {
        if (!cooking_equipment)
        {
            return null;
        }
        CargoBase cargo = cooking_equipment.GetInventory().GetCargo();
        if (!cargo)
        {
            return null;
        }

        // get ingredients, attatchments, water from cooking equipment
        map<string, ref CookZ_IngredientInEquipment> ingredientsInEquipment = GetIngredientsInEquipment(cargo);
        if (!ingredientsInEquipment)
        {
            return null;
        }
        ItemBase emptyCans = ItemBase.Cast(cooking_equipment.FindAttachmentBySlotName("CookZ_EmptyCans"));
        ItemBase emptyBoxes = ItemBase.Cast(cooking_equipment.FindAttachmentBySlotName("CookZ_EmptyBoxes"));
        int water = cooking_equipment.GetQuantity();
        int numItemsInEquipment = cargo.GetItemCount();

        // check recipes
        foreach (CookZ_Recipe recipe : allRecipes)
        {
            if (IngredientsFitRecipe(recipe, ingredientsInEquipment, emptyCans, emptyBoxes, cooking_equipment.Type(), water, numItemsInEquipment))
            {
                return recipe;
            }
        }

        return null;
    }

    private bool IngredientsFitRecipe(CookZ_Recipe recipe, map<string, ref CookZ_IngredientInEquipment> ingredientItemsInEquipment, ItemBase emptyCans, ItemBase emptyBoxes, typename equipmentType, int water, int numItemsInEquipment)
    {
        // check cooking equipment
        if (equipmentType == COOKING_EQUIPMENT_FRYINGPAN && !recipe.allowPan)
        {
            return false;
        }
        if (equipmentType == COOKING_EQUIPMENT_POT && !recipe.allowPot)
        {
            return false;
        }
        if (equipmentType == COOKING_EQUIPMENT_CAULDRON && !recipe.allowCauldron)
        {
            return false;
        }

        // check empty cans and boxes
        if (recipe.needsEmptyCan && !emptyCans)
        {
            return false;
        }
        if (recipe.needsEmptyBox && !emptyBoxes)
        {
            return false;
        }

        // check water
        if (recipe.needsWater && water < 500)
        {
            return false;
        }
        if (!recipe.needsWater && water > 0)
        {
            return false;
        }

        // check ingredients
        int numExpectedIngredientsInEquipment = 0;
        foreach (CookZ_Ingredient ingredient : recipe.ingredients)
        {
            int quantityInRecipe = ingredient.quantity;
            CookZ_IngredientInEquipment ingredientInEquipment = ingredientItemsInEquipment.Get(ingredient.name);
            if (!ingredientInEquipment)
            {
                return false;
            }
            int quantityInEquipment = ingredientInEquipment.quantity;
            int itemsInEquipment = ingredientInEquipment.numItems;

            if (quantityInRecipe == -1)
            {
                if (quantityInEquipment < 1)
                {
                    return false;
                }
                else
                {
                    numExpectedIngredientsInEquipment += itemsInEquipment;
                }
            }
            else
            {
                if (quantityInRecipe != quantityInEquipment)
                {
                    return false;
                }
                else
                {
                    numExpectedIngredientsInEquipment += itemsInEquipment;
                }
            }
        }
        // are needed ingredints in equipment and nothing else
        if(numExpectedIngredientsInEquipment == numItemsInEquipment)
        {
            return true;
        }
        return false;
    }

    private map<string, ref CookZ_IngredientInEquipment> GetIngredientsInEquipment(CargoBase cargo)
    {
        map<string, ref CookZ_IngredientInEquipment> ingredientsInEquipment = new map<string, ref CookZ_IngredientInEquipment>();

        int minIngredientQuantityPercent = 50;
        CookZ_Config config = GetDayZGame().GetCookZ_Config();
		if (config)
		{
            int configMinIngredientQuantityPercent = config.MinIngredientQuantityPercent;
            if (0 < configMinIngredientQuantityPercent && configMinIngredientQuantityPercent <= 100)
            {
			    minIngredientQuantityPercent = config.MinIngredientQuantityPercent;
            }
		}
        // -0.5 to circumvent bad UX because dayz displays 54.6% as 55% which then fails if the threshold is set to 55% 
        float minIngredientQuantityDecimal = (minIngredientQuantityPercent - 0.5) / 100.0;

        for (int i = 0; i < cargo.GetItemCount(); i++)
        {
            EntityAI entityInCookingEquipment = cargo.GetItem(i);
            ItemBase itemInCookingEquipment;
            if (!entityInCookingEquipment || !Class.CastTo(itemInCookingEquipment, entityInCookingEquipment))
            {
                return null;
            }
            
            // non splitable items have quantity 1, splitable item their current quantity
            int quantity = 1;
            if (itemInCookingEquipment.IsSplitable())
            {
                quantity = itemInCookingEquipment.GetQuantity();
            }
            else
            {
                if (itemInCookingEquipment.GetQuantityMax() > 0)
                {
                    float ingredientQuantityDecimal = itemInCookingEquipment.GetQuantity() / itemInCookingEquipment.GetQuantityMax();
                    // skip quantity check for BandageDressing - used for disinfecting. Would cause other ingredients to also fail. 
                    if (ingredientQuantityDecimal < minIngredientQuantityDecimal && itemInCookingEquipment.Type() != BandageDressing)
                    {
                        // not enough percent of max quantity
                        return null;
                    }
                }
            }

            Edible_Base edibleItem = Edible_Base.Cast(itemInCookingEquipment);
            if (edibleItem && edibleItem.CanBeCooked() && edibleItem.GetFoodStage() && !(edibleItem.GetFoodStage().IsFoodInStage(FoodStageType.RAW) || edibleItem.GetFoodStage().IsFoodInStage(FoodStageType.NONE)))
            {
                // not raw (or undefined food stage)
                return null;
            }

            // add ingredient by config-type - e.g. SodaCan_Pipsi, while the item-type is SodaCan_ColorBase
            // but in a lot of cases config-type and item-type are identical
            string currentIngredientCfgTypeName = itemInCookingEquipment.GetType();
            CookZ_IngredientInEquipment cfgIngredientInEquipment = ingredientsInEquipment.Get(currentIngredientCfgTypeName);
            if (!cfgIngredientInEquipment)
            {
                cfgIngredientInEquipment = new CookZ_IngredientInEquipment();
                ingredientsInEquipment.Set(currentIngredientCfgTypeName, cfgIngredientInEquipment);
            }
            cfgIngredientInEquipment.quantity = cfgIngredientInEquipment.quantity + quantity;
            cfgIngredientInEquipment.numItems = cfgIngredientInEquipment.numItems + 1;

            // add ingredient by item-type if different from config-type
            string currentIngredientItemTypeName = itemInCookingEquipment.Type().ToString();
            if (currentIngredientItemTypeName != currentIngredientCfgTypeName)
            {
                CookZ_IngredientInEquipment itemIngredientInEquipment = ingredientsInEquipment.Get(currentIngredientItemTypeName);
                if (!itemIngredientInEquipment)
                {
                    itemIngredientInEquipment = new CookZ_IngredientInEquipment();
                    ingredientsInEquipment.Set(currentIngredientItemTypeName, itemIngredientInEquipment);
                }
                itemIngredientInEquipment.quantity = itemIngredientInEquipment.quantity + quantity;
                itemIngredientInEquipment.numItems = itemIngredientInEquipment.numItems + 1;
            }
        }

        // accumulate food groups
        foreach (string group, array<string> ingredients : anyIngredientMap)
        {
            foreach (string ingredient : ingredients)
            {
                CookZ_IngredientInEquipment groupIngredient = ingredientsInEquipment.Get(group);
                if (!groupIngredient)
                {
                    groupIngredient = new CookZ_IngredientInEquipment();
                    ingredientsInEquipment.Set(group, groupIngredient);
                }
                CookZ_IngredientInEquipment specificIngredient = ingredientsInEquipment.Get(ingredient);
                if (specificIngredient)
                {
                    groupIngredient.quantity = groupIngredient.quantity + specificIngredient.quantity;
                    groupIngredient.numItems = groupIngredient.numItems + specificIngredient.numItems;
                }
            }
        }

        return ingredientsInEquipment;
    }

    // ------------------------------------------------------------------------------------------------------------------------------------
    // ONLY FOR LOCAL DEVELOPMENT
    // ------------------------------------------------------------------------------------------------------------------------------------
    
    // static map for calculating nutrition values - use the deputy for nutrition values
    static ref map<string, string> anyIngredientMapToDeputy = InitDeputyMap();
    static map<string, string> InitDeputyMap()
    {
        map<string, string> tempMap = new map<string, string>;
        tempMap.Insert(COOKING_INGREDIENT_ANY_MEAT,         COOKING_INGREDIENT_PIG_STEAK_MEAT);
        tempMap.Insert(COOKING_INGREDIENT_ANY_FRUIT,        COOKING_INGREDIENT_APPLE);
        tempMap.Insert(COOKING_INGREDIENT_ANY_VEG,          COOKING_INGREDIENT_GREEN_BELL_PEPPER);
        tempMap.Insert(COOKING_INGREDIENT_ANY_FISH,         COOKING_INGREDIENT_CARP_FILLET_MEAT);
        tempMap.Insert(COOKING_INGREDIENT_ANY_FISH_FILLET,  COOKING_INGREDIENT_CARP_FILLET_MEAT);
        tempMap.Insert(COOKING_INGREDIENT_ANY_MUSHROOM,     COOKING_INGREDIENT_BOLETUS_MUSHROOM);
        tempMap.Insert(COOKING_INGREDIENT_ANY_SAUSAGE,      COOKING_INGREDIENT_BEEF_SAUSAGE);
        tempMap.Insert(COOKING_INGREDIENT_ANY_BREADCRUMB,   COOKING_INGREDIENT_CRACKERS);
        tempMap.Insert(COOKING_INGREDIENT_ANY_BLOOD,        COOKING_INGREDIENT_BLOOD_BAG_FULL);
        return tempMap;
    }

    // static maps for calculating energy/water/quantityMax value - for ingredients that do not have those (or reasonable values)
    static ref map<string, int> ingredientMapToEnergy = InitEnergyMap();
    static map<string, int> InitEnergyMap()
    {
        map<string, int> tempMap = new map<string, int>;
        tempMap.Insert("Rice",                  100);
        tempMap.Insert("PowderedMilk",          500);
        tempMap.Insert("Worm",                  150);
        tempMap.Insert("Guts",                  250);
        tempMap.Insert("DisinfectantAlcohol",   200);
        tempMap.Insert("PotatoSeed",            275);
        tempMap.Insert("Bone",                  150);
        tempMap.Insert("Rag",                   0);
        tempMap.Insert(COOKING_INGREDIENT_BLOOD_BAG_FULL, 400);
        return tempMap;
    }
    static ref map<string, int> ingredientMapToWater = InitWaterMap();
    static map<string, int> InitWaterMap()
    {
        map<string, int> tempMap = new map<string, int>;
        tempMap.Insert("Rice",                  50);
        tempMap.Insert("PowderedMilk",          50);
        tempMap.Insert("Worm",                  80);
        tempMap.Insert("Guts",                  150);
        tempMap.Insert("DisinfectantAlcohol",   0);
        tempMap.Insert("PotatoSeed",            20);
        tempMap.Insert("Bone",                  20);
        tempMap.Insert("Rag",                   0);
        tempMap.Insert(COOKING_INGREDIENT_BLOOD_BAG_FULL, 100);
        return tempMap;
    }

    void CalculateNutritionValues(CookZ_Recipe recipe)
    {
        int totalEnergy = 0;
        int totalWater = 0;
        int totalQuantityMax = 0;
        FoodStageType foodStageType = FoodStageType.BAKED;
        if (recipe.needsWater)
        {
            foodStageType = FoodStageType.BOILED;
        }
        Print(string.Format("Nutrition Values for %1", recipe.name));
        if (recipe.needsWater)
        {
            // 500ml - 100ml (lost by cooking) times water content
            totalWater += (500 - 100) * 100;
        }
        foreach (CookZ_Ingredient ingredient : recipe.ingredients)
        {
            // map ingredient name to deputy - e.g. AnyMeat to specific meat
            string ingredientName = ingredient.name;
            if (anyIngredientMapToDeputy.Contains(ingredientName))
            {
                ingredientName = anyIngredientMapToDeputy.Get(ingredientName);
            }

            float itemEnergy;
            if (ingredientMapToEnergy.Contains(ingredientName))
            {
                itemEnergy = ingredientMapToEnergy.Get(ingredientName);
            }
            else
            {
                itemEnergy = Edible_Base.GetFoodEnergy(null, ingredientName, foodStageType);
                if (itemEnergy <= 0)
                {
                    itemEnergy = Edible_Base.GetFoodEnergy(null, ingredientName);
                }
            }

            float itemWater;
            if (ingredientMapToWater.Contains(ingredientName))
            {
                itemWater = ingredientMapToWater.Get(ingredientName);
            }
            else
            {
                itemWater = Edible_Base.GetFoodWater(null, ingredientName, foodStageType);
                if (itemWater <= 0)
                {
                    itemWater = Edible_Base.GetFoodWater(null, ingredientName);
                }
            }

            // use static quantity as default
            int itemQuantityMax = GetGame().ConfigGetInt(string.Format("CfgVehicles %1 cookz_staticQuantity", ingredientName));
            if (itemQuantityMax == 0)
            {
                itemQuantityMax = GetGame().ConfigGetInt(string.Format("CfgVehicles %1 varQuantityMax", ingredientName));
            }

            int itemQuantityTotalMax = itemQuantityMax * ingredient.quantity;
            // special cases
            if (recipe.name == "CookZ_BoneBrothCan" && ingredientName == "Bone")
            {
                itemQuantityTotalMax = 20 * 40;
            }

            Print(string.Format("   ingredient: %1, Q:%2, MQ:%3, E:%4, W:%5", ingredientName, ingredient.quantity, itemQuantityTotalMax, itemEnergy, itemWater));
            totalQuantityMax += itemQuantityTotalMax;
            totalEnergy += itemEnergy * itemQuantityTotalMax;
            totalWater += itemWater * itemQuantityTotalMax;
        }

        if (totalQuantityMax > 0)
        {
            float relativeEnergy = totalEnergy / totalQuantityMax;
            float relativeWater = totalWater / totalQuantityMax;
            Print(string.Format("  QuantityMax: %1", totalQuantityMax));
            Print(string.Format("  Energy:      %1", relativeEnergy));
            Print(string.Format("  Water:       %1", relativeWater));
        }
    }
}