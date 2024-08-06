class CookZ_Cookbook
{
    typename COOKING_EQUIPMENT_POT                      = Pot;
    typename COOKING_EQUIPMENT_FRYINGPAN                = FryingPan;
    typename COOKING_EQUIPMENT_CAULDRON                 = Cauldron;

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

    const string COOKING_INGREDIENT_ANY_MEAT                  = "AnyMeat";
    const string COOKING_INGREDIENT_ANY_FISH                  = "AnyFish";
    const string COOKING_INGREDIENT_ANY_FISH_FILLET           = "AnyFishFillet";
    const string COOKING_INGREDIENT_ANY_MUSHROOM              = "AnyMushroom";


    ref array<ref CookZ_Recipe> allRecipes;

    void CookZ_Cookbook()
    {
        allRecipes = new array<ref CookZ_Recipe>();
        LoadRecipesFromConfig();    
    }

    void LoadRecipesFromConfig()
    {
        string recipesPath = "CfgVehicles Recipes";

        int recipeCount = GetGame().ConfigGetChildrenCount(recipesPath);
        for (int i = 0; i < recipeCount; i++)
        {
            string recipeName;
            GetGame().ConfigGetChildName(recipesPath, i, recipeName);

            string allowPot;
            string allowCauldron;
            string allowPan;
            string needsWater;
            GetGame().ConfigGetText(string.Format("%1 %2 allowPot", recipesPath, recipeName), allowPot);
            GetGame().ConfigGetText(string.Format("%1 %2 allowCauldron", recipesPath, recipeName), allowCauldron);
            GetGame().ConfigGetText(string.Format("%1 %2 allowPan", recipesPath, recipeName), allowPan);
            GetGame().ConfigGetText(string.Format("%1 %2 needsWater", recipesPath, recipeName), needsWater);

            CookZ_Recipe recipe = new CookZ_Recipe(recipeName, allowPot == "true", allowCauldron == "true", allowPan == "true", needsWater == "true");

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
        }
    }

    // returns a dish string or "" if no valid recipe detected
    string GetDishForIngredients(ItemBase cooking_equipment)
    {
        CargoBase cargo = cooking_equipment.GetInventory().GetCargo();
        if (!cargo)
        {
            return "";
        }

        ref map<string, int> ingredientTypeInEquipment = new map<string, int>();

        for (int i = 0; i < cargo.GetItemCount(); i++)
        {
            string currentIngredientTypeName = cargo.GetItem(i).Type().ToString();
            ingredientTypeInEquipment.Set(currentIngredientTypeName, ingredientTypeInEquipment.Get(currentIngredientTypeName) + 1);
        }

        // accumulate food groups
        int numMeat = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_PIG_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_WOLF_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_GOAT_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BEAR_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_SHEEP_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BOAR_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_COW_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_HUMAN_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_DEER_STEAK_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_RABBIT_LEG_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_CHICKEN_BREAST_MEAT);
        int numFish = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_CARP_FILLET_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_MACKEREL_FILLET_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_SARDINES) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BITTERLINGS);
        int numFishFillet = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_CARP_FILLET_MEAT) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_MACKEREL_FILLET_MEAT);
        int numMushroom = ingredientTypeInEquipment.Get(COOKING_INGREDIENT_AGARICUS_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_AURICULARIA_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_BOLETUS_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_LACTARIUS_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_MACROLEPIOTA_MUSHROOM) + ingredientTypeInEquipment.Get(COOKING_INGREDIENT_PLEUROTUS_MUSHROOM);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_MEAT, numMeat);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_FISH, numFish);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_FISH_FILLET, numFishFillet);
        ingredientTypeInEquipment.Set(COOKING_INGREDIENT_ANY_MUSHROOM, numMushroom);

        foreach (CookZ_Recipe recipe : allRecipes)
        {
            if (recipe.GetNumIngredients() != cargo.GetItemCount())
            {
                // early check - num ingredients in container does not fit
                continue;
            }
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
            bool areIngredientsValid = true;
            foreach (CookZ_Ingredient ingredient : recipe.ingredients)
            {
                if (ingredient.quantity != ingredientTypeInEquipment.Get(ingredient.name))
                {
                    areIngredientsValid = false;
                    break;
                }
            }
            if(areIngredientsValid)
            {
                return recipe.name;
            }
        }

        return "";
    }
}