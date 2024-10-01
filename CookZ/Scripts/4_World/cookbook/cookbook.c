ref CookZ_Cookbook cookz_cookbook;
CookZ_Cookbook CookZ_GetCookbook()
{
    if (!cookz_cookbook)
    {
        cookz_cookbook = new CookZ_Cookbook();
    }

    return cookz_cookbook;
}

class CookZ_Cookbook
{
    typename COOKING_EQUIPMENT_POT                            = Pot;
    typename COOKING_EQUIPMENT_FRYINGPAN                      = FryingPan;
    typename COOKING_EQUIPMENT_CAULDRON                       = Cauldron;

    const string COOKING_INGREDIENT_POTATO                    = "Potato";
    const string COOKING_INGREDIENT_GREEN_BELL_PEPPER         = "GreenBellPepper";
    const string COOKING_INGREDIENT_ZUCCHINI                  = "Zucchini";
    const string COOKING_INGREDIENT_TOMATO                    = "Tomato";
    const string COOKING_INGREDIENT_PUMPKIN                   = "Pumpkin";
    const string COOKING_INGREDIENT_SLICED_PUMPKIN            = "SlicedPumpkin";

    const string COOKING_INGREDIENT_PLUM                      = "Plum";
    const string COOKING_INGREDIENT_PEAR                      = "Pear";
    const string COOKING_INGREDIENT_APPLE                     = "Apple";

    const string COOKING_INGREDIENT_PIG_STEAK_MEAT            = "PigSteakMeat";
    const string COOKING_INGREDIENT_WOLF_STEAK_MEAT           = "WolfSteakMeat";
    const string COOKING_INGREDIENT_GOAT_STEAK_MEAT           = "GoatSteakMeat";
    const string COOKING_INGREDIENT_BEAR_STEAK_MEAT           = "BearSteakMeat";
    const string COOKING_INGREDIENT_SHEEP_STEAK_MEAT          = "SheepSteakMeat";
    const string COOKING_INGREDIENT_BOAR_STEAK_MEAT           = "BoarSteakMeat";
    const string COOKING_INGREDIENT_COW_STEAK_MEAT            = "CowSteakMeat";
    const string COOKING_INGREDIENT_HUMAN_STEAK_MEAT          = "HumanSteakMeat";
    const string COOKING_INGREDIENT_DEER_STEAK_MEAT           = "DeerSteakMeat";
    const string COOKING_INGREDIENT_RABBIT_LEG_MEAT           = "RabbitLegMeat";
    const string COOKING_INGREDIENT_CHICKEN_BREAST_MEAT       = "ChickenBreastMeat";

    const string COOKING_INGREDIENT_CARP_FILLET_MEAT          = "CarpFilletMeat";
    const string COOKING_INGREDIENT_MACKEREL_FILLET_MEAT      = "MackerelFilletMeat";
    const string COOKING_INGREDIENT_SARDINES                  = "Sardines";
    const string COOKING_INGREDIENT_BITTERLINGS               = "Bitterlings";

    const string COOKING_INGREDIENT_AGARICUS_MUSHROOM         = "AgaricusMushroom";
    const string COOKING_INGREDIENT_AURICULARIA_MUSHROOM      = "AuriculariaMushroom";
    const string COOKING_INGREDIENT_BOLETUS_MUSHROOM          = "BoletusMushroom";
    const string COOKING_INGREDIENT_LACTARIUS_MUSHROOM        = "LactariusMushroom";
    const string COOKING_INGREDIENT_MACROLEPIOTA_MUSHROOM     = "MacrolepiotaMushroom";
    const string COOKING_INGREDIENT_PLEUROTUS_MUSHROOM        = "PleurotusMushroom";

    const string COOKING_INGREDIENT_BEEF_SAUSAGE              = "CookZ_Beef_Sausage";
    const string COOKING_INGREDIENT_CHICKEN_SAUSAGE           = "CookZ_Chicken_Sausage";
    const string COOKING_INGREDIENT_PIG_SAUSAGE               = "CookZ_Pig_Sausage";
    const string COOKING_INGREDIENT_GOAT_SAUSAGE              = "CookZ_Goat_Sausage";
    const string COOKING_INGREDIENT_BEAR_SAUSAGE              = "CookZ_Bear_Sausage";
    const string COOKING_INGREDIENT_SHEEP_SAUSAGE             = "CookZ_Sheep_Sausage";
    const string COOKING_INGREDIENT_BOAR_SAUSAGE              = "CookZ_Boar_Sausage";
    const string COOKING_INGREDIENT_DEER_SAUSAGE              = "CookZ_Deer_Sausage";
    const string COOKING_INGREDIENT_HARE_SAUSAGE              = "CookZ_Hare_Sausage";
    const string COOKING_INGREDIENT_WOLF_SAUSAGE              = "CookZ_Wolf_Sausage";
    const string COOKING_INGREDIENT_HUMAN_SAUSAGE             = "CookZ_Human_Sausage";

    const string COOKING_INGREDIENT_RAG                       = "Rag";
    const string COOKING_INGREDIENT_BANDAGE_DRESSING          = "BandageDressing";

    static const string COOKING_INGREDIENT_ANY_MEAT           = "AnyMeat";
    static const string COOKING_INGREDIENT_ANY_FRUIT          = "AnyFruit";
    static const string COOKING_INGREDIENT_ANY_VEG            = "AnyVeg";
    static const string COOKING_INGREDIENT_ANY_FISH           = "AnyFish";
    static const string COOKING_INGREDIENT_ANY_FISH_FILLET    = "AnyFishFillet";
    static const string COOKING_INGREDIENT_ANY_MUSHROOM       = "AnyMushroom";
    static const string COOKING_INGREDIENT_ANY_SAUSAGE        = "AnySausage";
    static const string COOKING_INGREDIENT_ANY_DISINFECT      = "AnyDisinfect";

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

    // ONLY FOR LOCAL DEVELOPMENT
    // static map for calculating nutrition values - use the deputy for nutrition values
    static ref map<string, string> anyIngredientMapToDeputy = InitDeputyMap();
    static map<string, string> InitDeputyMap()
    {
        map<string, string> tempMap = new map<string, string>;
        tempMap.Insert(COOKING_INGREDIENT_ANY_MEAT,         "PigSteakMeat");
        tempMap.Insert(COOKING_INGREDIENT_ANY_FRUIT,        "Apple");
        tempMap.Insert(COOKING_INGREDIENT_ANY_VEG,          "GreenBellPepper");
        tempMap.Insert(COOKING_INGREDIENT_ANY_FISH,         "CarpFilletMeat");
        tempMap.Insert(COOKING_INGREDIENT_ANY_FISH_FILLET,  "CarpFilletMeat");
        tempMap.Insert(COOKING_INGREDIENT_ANY_MUSHROOM,     "BoletusMushroom");
        tempMap.Insert(COOKING_INGREDIENT_ANY_SAUSAGE,      "CookZ_Beef_Sausage");
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
        tempMap.Insert("Rag",                   0);
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
        tempMap.Insert("Rag",                   0);
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
        foreach (CookZ_Ingredient ingredient : recipe.ingredients)
        {
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

            int itemQuantityMax = GetGame().ConfigGetInt(string.Format("CfgVehicles %1 varQuantityMax", ingredientName));
            if (itemQuantityMax == 0)
            {
                // fallback to static quantity
                itemQuantityMax = GetGame().ConfigGetInt(string.Format("CfgVehicles %1 cookz_staticQuantity", ingredientName));
            }

            int itemQuantityTotalMax = itemQuantityMax * ingredient.quantity;
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

    // returns a dish string or null if no valid recipe detected
    CookZ_Recipe GetDishForIngredients(ItemBase cooking_equipment)
    {
        // count ingredients in cooking equipment
        CargoBase cargo = cooking_equipment.GetInventory().GetCargo();
        if (!cargo)
        {
            return null;
        }

        ref map<string, int> ingredientTypeInEquipment = new map<string, int>();
        
        ItemBase emptyCans = ItemBase.Cast(cooking_equipment.FindAttachmentBySlotName("CookZ_EmptyCans"));
        ItemBase emptyBoxes = ItemBase.Cast(cooking_equipment.FindAttachmentBySlotName("CookZ_EmptyBoxes"));

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
        float minIngredientQuantityDecimal = minIngredientQuantityPercent / 100.0;

        for (int i = 0; i < cargo.GetItemCount(); i++)
        {
            EntityAI entityInCookingEquipment = cargo.GetItem(i);

            ItemBase itemInCookingEquipment = ItemBase.Cast(entityInCookingEquipment);
            if (itemInCookingEquipment && itemInCookingEquipment.GetQuantityMax() > 0)
            {
                if (itemInCookingEquipment.GetQuantity() / itemInCookingEquipment.GetQuantityMax() < minIngredientQuantityDecimal)
                {
                    // not enough percent of max quantity
                    return null;
                }
            }

            Edible_Base edibleItem = Edible_Base.Cast(itemInCookingEquipment);
            if (edibleItem && edibleItem.CanBeCooked() && !edibleItem.IsFoodRaw())
            {
                // not raw
                return null;
            }

            string currentIngredientTypeName = entityInCookingEquipment.Type().ToString();
            ingredientTypeInEquipment.Set(currentIngredientTypeName, ingredientTypeInEquipment.Get(currentIngredientTypeName) + 1);
        }

        // accumulate food groups
        int numMeat = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_PIG_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_WOLF_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_GOAT_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BEAR_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_SHEEP_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BOAR_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_COW_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_HUMAN_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_DEER_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_RABBIT_LEG_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_CHICKEN_BREAST_MEAT);
        int numFruit = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_PLUM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_PEAR) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_APPLE);
        int numVeg = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_POTATO) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_GREEN_BELL_PEPPER) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_ZUCCHINI) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_TOMATO) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_PUMPKIN) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_SLICED_PUMPKIN);
        int numFish = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_CARP_FILLET_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_MACKEREL_FILLET_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_SARDINES) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BITTERLINGS);
        int numFishFillet = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_CARP_FILLET_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_MACKEREL_FILLET_MEAT);
        int numMushroom = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_AGARICUS_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_AURICULARIA_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BOLETUS_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_LACTARIUS_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_MACROLEPIOTA_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_PLEUROTUS_MUSHROOM);
        int numSausage = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BEEF_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_CHICKEN_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_PIG_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_GOAT_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BEAR_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_SHEEP_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BOAR_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_DEER_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_HARE_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_WOLF_SAUSAGE) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_HUMAN_SAUSAGE);
        int numDisinfect = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_RAG) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BANDAGE_DRESSING);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_MEAT, numMeat);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_FRUIT, numFruit);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_VEG, numVeg);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_FISH, numFish);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_FISH_FILLET, numFishFillet);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_MUSHROOM, numMushroom);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_SAUSAGE, numSausage);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_DISINFECT, numDisinfect);

        // check recipes
        foreach (CookZ_Recipe recipe : allRecipes)
        {
            // check cooking equipment
            if (cooking_equipment.Type() == COOKING_EQUIPMENT_FRYINGPAN && !recipe.allowPan)
            {
                continue;
            }
            if (cooking_equipment.Type() == COOKING_EQUIPMENT_POT && !recipe.allowPot)
            {
                continue;
            }
            if (cooking_equipment.Type() == COOKING_EQUIPMENT_CAULDRON && !recipe.allowCauldron)
            {
                continue;
            }
            // check empty cans and boxes
            if (recipe.needsEmptyCan && !emptyCans)
            {
                continue;
            }
            if (recipe.needsEmptyBox && !emptyBoxes)
            {
                continue;
            }
            // check water
            if (recipe.needsWater && cooking_equipment.GetQuantity() < 500)
            {
                continue;
            }
            if (!recipe.needsWater && cooking_equipment.GetQuantity() > 0)
            {
                continue;
            }
            // check ingredients
            int numExpectedIngredientsInEquipment = 0;
            bool areIngredientsInEquipment = true;
            foreach (CookZ_Ingredient ingredient : recipe.ingredients)
            {
                int quantityInRecipe = ingredient.quantity;
                int quantityInEquipment = ingredientTypeInEquipment.Get(ingredient.name);
                if (quantityInRecipe == -1)
                {
                    if (quantityInEquipment < 1)
                    {
                        areIngredientsInEquipment = false;
                        break;
                    }
                    else
                    {
                        numExpectedIngredientsInEquipment += quantityInEquipment;
                    }
                }
                else
                {
                    if (quantityInRecipe != quantityInEquipment)
                    {
                        areIngredientsInEquipment = false;
                        break;
                    }
                    else
                    {
                        numExpectedIngredientsInEquipment += quantityInEquipment;
                    }
                }
            }
            // are needed ingredints in equipment and nothing else
            if(areIngredientsInEquipment && numExpectedIngredientsInEquipment == cargo.GetItemCount())
            {
                return recipe;
            }
        }

        return null;
    }
}