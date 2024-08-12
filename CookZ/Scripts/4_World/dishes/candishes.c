class CookZ_FishSoupCan : CookZ_Can_Base {}
class CookZ_GoulashCan : CookZ_Can_Base {}
class CookZ_LecsoCan : CookZ_Can_Base {}
class CookZ_PumpkinSoupCan : CookZ_Can_Base {}
class CookZ_UkhaCan : CookZ_Can_Base {}
class CookZ_MysteryMeatCan : CookZ_Can_Base {}
class CookZ_ZucchiniCaviarCan : CookZ_Can_Base {}

class CookZ_Can_Base: Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew(string.Format("%1_Opened", this.Type().ToString()));
    }

    override bool IsOpen()
    {
        return false;
    }
}

class CookZ_FishSoupCan_Opened: CookZ_CanOpened_Base {}
class CookZ_GoulashCan_Opened: CookZ_CanOpened_Base {}
class CookZ_LecsoCan_Opened: CookZ_CanOpened_Base {}
class CookZ_PumpkinSoupCan_Opened: CookZ_CanOpened_Base {}
class CookZ_UkhaCan_Opened: CookZ_CanOpened_Base {}
class CookZ_MysteryMeatCan_Opened: CookZ_CanOpened_Base {}
class CookZ_ZucchiniCaviarCan_Opened: CookZ_CanOpened_Base {}

class CookZ_CanOpened_Base: Edible_Base
{
    override bool CanDecay()
    {
        return true;
    }
    
    override bool CanProcessDecay()
    {
        return !(GetAgents() & eAgents.FOOD_POISON);
    }
    
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionForceFeedCan);
        AddAction(ActionEatCan);
    }
}
