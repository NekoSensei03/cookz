class CookZ_Cheese: Edible_Base
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
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatMeat);
	}
}
