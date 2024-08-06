modded class Cooking
{
	ref CookZ_Cookbook cookbook;

	void Cooking()
	{
		cookbook = new CookZ_Cookbook();
	}

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
				string dish = cookbook.GetDishForIngredients(cooking_equipment);
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
}
