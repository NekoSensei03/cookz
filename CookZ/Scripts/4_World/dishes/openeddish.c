class CookZ_OpenedDish: Edible_Base
{
    override bool CanDecay()
    {
        return GetDayZGame().GetCookZ_Config().EnableBoxAndCanDecay;
    }
    
    override bool CanProcessDecay()
    {
        return !GetIsFrozen() && !(GetAgents() & eAgents.FOOD_POISON);
    }
    
    override void SetActions()
    {
        super.SetActions();
        
        AddAction(ActionForceFeedCan);
        AddAction(ActionEatCan);
    }
}
