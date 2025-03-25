modded class PluginRecipesManager
{
    override void RegisterRecipies()
    {
        super.RegisterRecipies();
        RegisterRecipe(new CookZ_CraftEmptyCan);
        RegisterRecipe(new CookZ_CraftEmptyBoxFromPaper);
        RegisterRecipe(new CookZ_CraftEmptyBoxFromBark);
        RegisterRecipe(new CookZ_CraftCookbook);
    }
}

class CookZ_CraftEmptyCan extends RecipeBase	
{	
    override void Init()
    {
        m_Name = "#Craft #STR_CookZ_EmptyCan_DN";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check

        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check

        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check

        m_MinQuantityIngredient[1] = -1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------

        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"MetalPlate");

        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = -1;// 0 = do nothing
        m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

        //ingredient 2
        InsertIngredient(1,"Hacksaw");//you can insert multiple ingredients this way

        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = 0;// 0 = do nothing
        m_IngredientDestroy[1] = false;// false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------

        //result1
        AddResult("CookZ_EmptyCan");//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 10;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo( ItemBase ingredients[], PlayerBase player )
    {
        CookZ_Config config = GetDayZGame().GetCookZ_Config();
		if (config)
		{
			return config.CanCraftEmptyCans;
		}
        return true;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        super.Do(ingredients, player, results, specialty_weight);
    }
};

class CookZ_CraftEmptyBoxFromPaper extends RecipeBase	
{	
    override void Init()
    {
        m_Name = "#Craft #STR_CookZ_EmptyBox_DN";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check

        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check

        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check

        m_MinQuantityIngredient[1] = -1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------

        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"Paper");

        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = 0;// 0 = do nothing
        m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

        //ingredient 2
        InsertIngredient(1,"Paper");//you can insert multiple ingredients this way

        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = 0;// 0 = do nothing
        m_IngredientDestroy[1] = true;// false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------

        //result1
        AddResult("CookZ_EmptyBox");//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 1;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo( ItemBase ingredients[], PlayerBase player )
    {
        CookZ_Config config = GetDayZGame().GetCookZ_Config();
		if (config)
		{
			return config.CanCraftEmptyBoxes;
		}
        return true;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        super.Do(ingredients, player, results, specialty_weight);
    }
};

class CookZ_CraftEmptyBoxFromBark extends RecipeBase	
{	
    override void Init()
    {
        m_Name = "#Craft #STR_CookZ_EmptyBox_DN";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check

        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check

        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check

        m_MinQuantityIngredient[1] = 1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------

        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"Bark_Oak");

        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = -1;// 0 = do nothing
        m_IngredientDestroy[0] = false;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

        //ingredient 2
        InsertIngredient(1,"Cleaver");//you can insert multiple ingredients this way
        InsertIngredient(1,"StoneKnife");
        InsertIngredient(1,"BoneKnife");
        InsertIngredient(1,"SteakKnife");
        InsertIngredient(1,"CombatKnife");
        InsertIngredient(1,"OrientalMachete");
        InsertIngredient(1,"CrudeMachete");
        InsertIngredient(1,"FangeKnife");
        InsertIngredient(1,"Machete");
        InsertIngredient(1,"KukriKnife");
        InsertIngredient(1,"HuntingKnife");
        InsertIngredient(1,"KitchenKnife");
        InsertIngredient(1,"Sickle");
        InsertIngredient(1,"FirefighterAxe");
        InsertIngredient(1,"FirefighterAxe_Black");
        InsertIngredient(1,"FirefighterAxe_Green");
        InsertIngredient(1,"Hatchet");
        InsertIngredient(1,"WoodAxe");

        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = 0;// 0 = do nothing
        m_IngredientDestroy[1] = false;// false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------

        //result1
        AddResult("CookZ_EmptyBox");//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 1;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo( ItemBase ingredients[], PlayerBase player )
    {
        CookZ_Config config = GetDayZGame().GetCookZ_Config();
		if (config)
		{
			return config.CanCraftEmptyBoxes;
		}
        return true;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        super.Do(ingredients, player, results, specialty_weight);
    }
};

class CookZ_CraftCookbook extends RecipeBase	
{	
    override void Init()
    {
        m_Name = "#Craft #STR_CookZ_Cookbook";
        m_IsInstaRecipe = false;//should this recipe be performed instantly without animation
        m_AnimationLength = 0.5;//animation length in relative time units
        m_Specialty = 0.02;// value > 0 for roughness, value < 0 for precision

        //conditions
        m_MinDamageIngredient[0] = -1;//-1 = disable check
        m_MaxDamageIngredient[0] = 3;//-1 = disable check

        m_MinQuantityIngredient[0] = 1;//-1 = disable check
        m_MaxQuantityIngredient[0] = -1;//-1 = disable check

        m_MinDamageIngredient[1] = -1;//-1 = disable check
        m_MaxDamageIngredient[1] = 3;//-1 = disable check

        m_MinQuantityIngredient[1] = 1;//-1 = disable check
        m_MaxQuantityIngredient[1] = -1;//-1 = disable check
        //----------------------------------------------------------------------------------------------------------------------

        //INGREDIENTS
        //ingredient 1
        InsertIngredient(0,"Paper");
        InsertIngredient(0,"CookZ_EmptyBox");

        m_IngredientAddHealth[0] = 0;// 0 = do nothing
        m_IngredientSetHealth[0] = -1; // -1 = do nothing
        m_IngredientAddQuantity[0] = 0;// 0 = do nothing
        m_IngredientDestroy[0] = true;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this ingredient

        //ingredient 2
        InsertIngredient(1,"Paper");
        InsertIngredient(1,"CookZ_EmptyBox");

        m_IngredientAddHealth[1] = 0;// 0 = do nothing
        m_IngredientSetHealth[1] = -1; // -1 = do nothing
        m_IngredientAddQuantity[1] = 0;// 0 = do nothing
        m_IngredientDestroy[1] = true;//true = destroy, false = do nothing
        m_IngredientUseSoftSkills[1] = false;// set 'true' to allow modification of the values by softskills on this ingredient
        //----------------------------------------------------------------------------------------------------------------------

        //result1
        AddResult("CookZ_Cookbook_Item");//add results here

        m_ResultSetFullQuantity[0] = false;//true = set full quantity, false = do nothing
        m_ResultSetQuantity[0] = 1;//-1 = do nothing
        m_ResultSetHealth[0] = -1;//-1 = do nothing
        m_ResultInheritsHealth[0] = 1;// (value) == -1 means do nothing; a (value) >= 0 means this result will inherit health from ingredient number (value);(value) == -2 means this result will inherit health from all ingredients averaged(result_health = combined_health_of_ingredients / number_of_ingredients)
        m_ResultInheritsColor[0] = -1;// (value) == -1 means do nothing; a (value) >= 0 means this result classname will be a composite of the name provided in AddResult method and config value "color" of ingredient (value)
        m_ResultToInventory[0] = -1;//(value) == -2 spawn result on the ground;(value) == -1 place anywhere in the players inventory, (value) >= 0 means switch position with ingredient number(value)
        m_ResultUseSoftSkills[0] = false;// set 'true' to allow modification of the values by softskills on this result
        m_ResultReplacesIngredient[0] = -1;// value == -1 means do nothing; a value >= 0 means this result will transfer item propertiesvariables, attachments etc.. from an ingredient value
    }

    override bool CanDo( ItemBase ingredients[], PlayerBase player )
    {
        CookZ_Config config = GetDayZGame().GetCookZ_Config();
		if (config)
		{
			return config.CanCraftCookBook;
		}
        return true;
    }

    // ToDo PP without this dayz throws an error when closing the client ... why?!
    override void Do(ItemBase ingredients[], PlayerBase player, array<ItemBase> results, float specialty_weight)
    {
        super.Do(ingredients, player, results, specialty_weight);
    }
};
