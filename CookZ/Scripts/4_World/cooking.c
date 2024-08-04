modded class Cooking
{
	typename COOKING_INGREDIENT_POTATO 					= Potato;
	typename COOKING_INGREDIENT_GREEN_BELL_PEPPER		= GreenBellPepper;
	typename COOKING_INGREDIENT_ZUCCHINI				= Zucchini;
	typename COOKING_INGREDIENT_TOMATO 					= Tomato;
	typename COOKING_INGREDIENT_SLICED_PUMPKIN			= SlicedPumpkin;

	typename COOKING_INGREDIENT_PLUM					= Plum;
	typename COOKING_INGREDIENT_PEAR					= Pear;
	typename COOKING_INGREDIENT_APPLE					= Apple;

	typename COOKING_INGREDIENT_PIG_STEAK_MEAT			= PigSteakMeat;
	typename COOKING_INGREDIENT_WOLF_STEAK_MEAT			= WolfSteakMeat;
	typename COOKING_INGREDIENT_GOAT_STEAK_MEAT			= GoatSteakMeat;
	typename COOKING_INGREDIENT_BEAR_STEAK_MEAT			= BearSteakMeat;
	typename COOKING_INGREDIENT_SHEEP_STEAK_MEAT		= SheepSteakMeat;
	typename COOKING_INGREDIENT_BOAR_STEAK_MEAT			= BoarSteakMeat;
	typename COOKING_INGREDIENT_COW_STEAK_MEAT			= CowSteakMeat;
	typename COOKING_INGREDIENT_HUMAN_STEAK_MEAT		= HumanSteakMeat;
	typename COOKING_INGREDIENT_DEER_STEAK_MEAT			= DeerSteakMeat;
	typename COOKING_INGREDIENT_RABBIT_LEG_MEAT			= RabbitLegMeat;

	string COOKING_RESULT_FRIED_POTATOES				= "FriedPotatoesCan";
	string COOKING_RESULT_GOULASH						= "GoulashCan";
	string COOKING_RESULT_STIR_FRY						= "StirFryCan";
	string COOKING_RESULT_PUMPKIN_SOUP					= "PumpkinSoupCan";
	string COOKING_RESULT_APPLE_MARMALADE				= "AppleMarmalade";
	string COOKING_RESULT_PLUM_MARMALADE				= "PlumMarmalade";
	string COOKING_RESULT_PEAR_MARMALADE				= "PearMarmalade";
	
	//COOKING PROCESS
	//--- Cooking with equipment (pot)
	//Returns 1 if the item changed its cooking stage, 0 if not
	override int CookWithEquipment(ItemBase cooking_equipment, float cooking_time_coef = 1)
	{
		bool is_empty;
		
		//check cooking conditions
		if (cooking_equipment == null)
		{
			return 0;
		}
		
		if (cooking_equipment.IsRuined())
		{
			return 0;
		}
		
		//manage items in cooking equipment
		Param2<bool, bool> stateFlags = new Param2<bool, bool>(false, false); // 1st - done; 2nd - burned
		Param2<CookingMethodType, float> cookingMethodWithTime = GetCookingMethodWithTimeOverride(cooking_equipment);
		bool done = false;
		bool burned = false;
		
		//! cooking time coef override
		if (cooking_time_coef != 1)
		{
			cookingMethodWithTime.param2 = cooking_time_coef;
		}
		
		CargoBase cargo = cooking_equipment.GetInventory().GetCargo();
		if (cargo)
		{
			is_empty = cargo.GetItemCount() == 0;
			
			//process items
			for (int i = 0; i < cargo.GetItemCount(); i++)
			{
				ProcessItemToCook(ItemBase.Cast(cargo.GetItem(i)), cooking_equipment, cookingMethodWithTime, stateFlags);
				done = done || stateFlags.param1;
				burned = burned || stateFlags.param2;
			}

			if (done && !burned)
			{
				string dish = GetDishForIngredients(cooking_equipment);
				if (dish != "")
				{
					// clear all items from cooking equipment (bottom to top for index safety)
					int itemCount = cargo.GetItemCount();
					for (int j = itemCount - 1; j >= 0; j--)
					{
						cooking_equipment.GetInventory().LocalDestroyEntity(ItemBase.Cast(cargo.GetItem(j)));
					}
					// remove ALL liquid for now so that spawned items will not get wet
					cooking_equipment.AddQuantity(-cooking_equipment.GetQuantity());
					// add dish to cooking equipment
					cooking_equipment.GetInventory().CreateInInventory(dish);
				}
			}
		}
		else
		{
			ProcessItemToCook(cooking_equipment, cooking_equipment, cookingMethodWithTime, stateFlags);
			done = stateFlags.param1;
			burned = stateFlags.param2;
		}
		
		//manage cooking equipment
		Bottle_Base bottle_base = Bottle_Base.Cast(cooking_equipment);
		if (bottle_base)
		{
			float cookingEquipmentTemp = cooking_equipment.GetTemperature();
			
			//handle water boiling
			if (cookingEquipmentTemp >= LIQUID_BOILING_POINT)
			{
				//remove agents
				cooking_equipment.RemoveAllAgents();
				
				if (cooking_equipment.GetQuantity() > 0)
				{
					//vaporize liquid
					cooking_equipment.AddQuantity(-LIQUID_VAPOR_QUANTITY);
				}
			}
			
			//handle audio visuals
			bottle_base.RefreshAudioVisualsOnClient(cookingMethodWithTime.param1, done, is_empty, burned);
		}

		FryingPan frying_pan = FryingPan.Cast(cooking_equipment);
		if (frying_pan && !bottle_base)
		{
			//handle audio visuals
			frying_pan.RefreshAudioVisualsOnClient(cookingMethodWithTime.param1, done, is_empty, burned);
		}
		
		return 1;
	}

	// returns a dish string or "" if no valid recipe detected
	string GetDishForIngredients(ItemBase cooking_equipment)
	{
		CargoBase cargo = cooking_equipment.GetInventory().GetCargo();
		if (!cargo)
		{
			return "";
		}

		// count ingredients in cooking equipment
		int numLard = 0;

		int numPotato = 0;
		int numGreenBellPepper = 0;
		int numZucchini = 0;
		int numTomato = 0;
		int numSlicedPumpkin = 0;

		int numPlum = 0;
		int numPear = 0;
		int numApple = 0;

		int numPigSteakMeat = 0;
		int numWolfSteakMeat = 0;
		int numGoatSteakMeat = 0;
		int numBearSteakMeat = 0;
		int numSheepSteakMeat = 0;
		int numBoarSteakMeat = 0;
		int numCowSteakMeat = 0;
		int numHumanSteakMeat = 0;
		int numDeerSteakMeat = 0;
		int numRabbitLegMeat = 0;

		for (int i = 0; i < cargo.GetItemCount(); i++)
		{
			switch(cargo.GetItem(i).Type())
			{
				case COOKING_INGREDIENT_LARD:
					numLard++;
					break;

				case COOKING_INGREDIENT_POTATO:
					numPotato++;
					break;
				case COOKING_INGREDIENT_GREEN_BELL_PEPPER:
					numGreenBellPepper++;
					break;
				case COOKING_INGREDIENT_ZUCCHINI:
					numZucchini++;
					break;
				case COOKING_INGREDIENT_TOMATO:
					numTomato++;
					break;
				case COOKING_INGREDIENT_SLICED_PUMPKIN:
					numSlicedPumpkin++;
					break;

				case COOKING_INGREDIENT_PLUM:
					numPlum++;
					break;
				case COOKING_INGREDIENT_PEAR:
					numPear++;
					break;
				case COOKING_INGREDIENT_APPLE:
					numApple++;
					break;

				case COOKING_INGREDIENT_PIG_STEAK_MEAT:
					numPigSteakMeat++;
					break;
				case COOKING_INGREDIENT_WOLF_STEAK_MEAT:
					numWolfSteakMeat++;
					break;
				case COOKING_INGREDIENT_GOAT_STEAK_MEAT:
					numGoatSteakMeat++;
					break;
				case COOKING_INGREDIENT_BEAR_STEAK_MEAT:
					numBearSteakMeat++;
					break;
				case COOKING_INGREDIENT_SHEEP_STEAK_MEAT:
					numSheepSteakMeat++;
					break;
				case COOKING_INGREDIENT_BOAR_STEAK_MEAT:
					numBoarSteakMeat++;
					break;
				case COOKING_INGREDIENT_COW_STEAK_MEAT:
					numCowSteakMeat++;
					break;
				case COOKING_INGREDIENT_HUMAN_STEAK_MEAT:
					numHumanSteakMeat++;
					break;
				case COOKING_INGREDIENT_DEER_STEAK_MEAT:
					numDeerSteakMeat++;
					break;
				case COOKING_INGREDIENT_RABBIT_LEG_MEAT:
					numRabbitLegMeat++;
					break;

				default:
					// no valid recipe if there is a non supported ingredient in the cooking equipment
					return "";
			}
		}
		int numMeat = numPigSteakMeat + numWolfSteakMeat + numGoatSteakMeat + numBearSteakMeat + numSheepSteakMeat + numBoarSteakMeat + numCowSteakMeat + numHumanSteakMeat + numDeerSteakMeat + numRabbitLegMeat;

		// handle frying pan recipes
		if (cooking_equipment.Type() == COOKING_EQUIPMENT_FRYINGPAN)
		{
			if (numPotato == 4 && numLard == 1 && cargo.GetItemCount() == 5)
			{
				return COOKING_RESULT_FRIED_POTATOES;
			}
			if (numPotato == 1 && numGreenBellPepper == 1 && numTomato == 1 && numZucchini == 1 && numLard == 1 && cargo.GetItemCount() == 5)
			{
				return COOKING_RESULT_STIR_FRY;
			}
		}

		// handle pot/cauldron recipes
		if (cooking_equipment.Type() == COOKING_EQUIPMENT_POT || cooking_equipment.Type() == COOKING_EQUIPMENT_CAULDRON)
		{
			// with water
			if (cooking_equipment.GetQuantity() >= 500)
			{
				if (numPotato == 2 && numGreenBellPepper == 1 && numMeat == 1 && cargo.GetItemCount() == 4)
				{
					return COOKING_RESULT_GOULASH;
				}
				if (numSlicedPumpkin == 2 && cargo.GetItemCount() == 2)
				{
					return COOKING_RESULT_PUMPKIN_SOUP;
				}
			}
			// without water
			else
			{
				if (numPlum == 6 && cargo.GetItemCount() == 6)
				{
					return COOKING_RESULT_PLUM_MARMALADE;
				}
				if (numApple == 6 && cargo.GetItemCount() == 6)
				{
					return COOKING_RESULT_APPLE_MARMALADE;
				}
				if (numPear == 4 && cargo.GetItemCount() == 4)
				{
					return COOKING_RESULT_PEAR_MARMALADE;
				}
			}
		}
		return "";
	}
}