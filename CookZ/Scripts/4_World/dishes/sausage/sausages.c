class CookZ_Sausage_Base: Edible_Base
{
	override bool CanDecay()
	{
		return GetDayZGame().GetCookZ_Config().EnableSausageDecay;
	}

	override bool CanProcessDecay()
    {
        return !GetIsFrozen() && !(GetAgents() & eAgents.FOOD_POISON);
    }
	
	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionForceFeed);
		AddAction(ActionEatMeat);
	}
}

class CookZ_Beef_Sausage: CookZ_Sausage_Base {}
class CookZ_Chicken_Sausage: CookZ_Sausage_Base {}
class CookZ_Pig_Sausage: CookZ_Sausage_Base {}
class CookZ_Goat_Sausage: CookZ_Sausage_Base {}
class CookZ_Bear_Sausage: CookZ_Sausage_Base {}
class CookZ_Sheep_Sausage: CookZ_Sausage_Base {}
class CookZ_Boar_Sausage: CookZ_Sausage_Base {}
class CookZ_Deer_Sausage: CookZ_Sausage_Base {}
class CookZ_Hare_Sausage: CookZ_Sausage_Base {}
class CookZ_Wolf_Sausage: CookZ_Sausage_Base {}
class CookZ_Human_Sausage: CookZ_Sausage_Base {}
class CookZ_Fox_Sausage: CookZ_Sausage_Base {}
class CookZ_Reindeer_Sausage: CookZ_Sausage_Base {}
class CookZ_Blood_Sausage: CookZ_Sausage_Base {}