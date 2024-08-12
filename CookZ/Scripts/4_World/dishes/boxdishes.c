class CookZ_FriedPotatoesBox : CookZ_Box_Base {}
class CookZ_StirFryBox : CookZ_Box_Base {}
class CookZ_FishAndChipsBox : CookZ_Box_Base {}
class CookZ_RicePuddingBox : CookZ_Box_Base {}
class CookZ_MushroomRisottoBox : CookZ_Box_Base {}
class CookZ_PilafBox : CookZ_Box_Base {}

class CookZ_Box_Base: Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew(string.Format("%1_Opened", this.Type().ToString()));
    }

    override bool IsOpen()
    {
        return false;
    }

    override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionOpen);
	}
}

class CookZ_FriedPotatoesBox_Opened : CookZ_BoxOpened_Base {}
class CookZ_StirFryBox_Opened : CookZ_BoxOpened_Base {}
class CookZ_FishAndChipsBox_Opened : CookZ_BoxOpened_Base {}
class CookZ_RicePuddingBox_Opened : CookZ_BoxOpened_Base {}
class CookZ_MushroomRisottoBox_Opened : CookZ_BoxOpened_Base {}
class CookZ_PilafBox_Opened : CookZ_BoxOpened_Base {}

class CookZ_BoxOpened_Base: Edible_Base
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