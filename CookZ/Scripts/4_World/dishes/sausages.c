class CookZ_Sausage_Base: Edible_Base
{
	override bool CanBeCooked()
	{
		return true;
	}		
	
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