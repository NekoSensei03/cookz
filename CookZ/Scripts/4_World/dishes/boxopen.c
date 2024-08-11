class CookZ_FriedPotatoesBox_Opened : CookZ_BoxOpened_Base {}
class CookZ_StirFryBox_Opened : CookZ_BoxOpened_Base {}
class CookZ_FishAndChipsBox_Opened : CookZ_BoxOpened_Base {}
class CookZ_RicePuddingBox_Opened : CookZ_BoxOpened_Base {}

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
