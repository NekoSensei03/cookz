// mod reasons:
//  set quantity of CookZ closed can calculated during cooking to opened can
modded class OpenCan extends RecipeBase
{
    // override complete Do, as called static methods cannot be modded with calling super
    override void Do(ItemBase ingredients[], PlayerBase player,array<ItemBase> results, float specialty_weight)
	{
        CookZ_ClosedDish closedDish = CookZ_ClosedDish.Cast(ingredients[0]);
        if (!closedDish)
        {
            super.Do(ingredients, player,results, specialty_weight);
            return;
        }
         
        ItemBase tool;
        Class.CastTo(tool, ingredients[1]);
        PlayerBase playerPB;
        Class.CastTo(playerPB, player);

        // see OpenItem.OpenAndSwitch
        array<int> spill_range = new array<int>;
        
        if( tool.ConfigIsExisting("OpenItemSpillRange") )
        {
            tool.ConfigGetIntArray("OpenItemSpillRange", spill_range );
        }
        else
        {
            Debug.LogError("OpenItemSpillRange config parameter missing, default values used ! ");
            Error("OpenItemSpillRange config parameter missing, default values used !");
            spill_range.Insert(0);
            spill_range.Insert(100);
        }
        float spill_modificator = Math.RandomIntInclusive( spill_range.Get(0),spill_range.Get(1) ) / 100;
        
        // see OpenItem.SwitchItems - modded here for adding quantity from closed can
        string new_name = string.Format("%1_Opened", closedDish.Type().ToString());
        OpenAndSwitchLambda lambda = new OpenAndSwitchLambda(closedDish, new_name, playerPB, spill_modificator, specialty_weight);
        int transferQuantity = closedDish.CookZ_GetQuantity();
        if (transferQuantity <= 0)
        {
            transferQuantity = -1; // -1 for do not transfer
        }
        lambda.SetTransferParams(true, true, true, true, transferQuantity);
        MiscGameplayFunctions.TurnItemIntoItemEx(playerPB, lambda);
	}
}
