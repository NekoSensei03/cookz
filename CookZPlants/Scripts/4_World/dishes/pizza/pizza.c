class CookZPlants_Pizza_Base: CookZ_ClosedDish
{
    override void SetActions()
    {
        super.SetActions();
        AddAction(ActionOpen);
    }
}

class CookZPlants_MargheritaPizza : CookZPlants_Pizza_Base {}
class CookZPlants_PepperoniPizza : CookZPlants_Pizza_Base {}
class CookZPlants_SeafoodPizza : CookZPlants_Pizza_Base {}
class CookZPlants_VegetablePizza : CookZPlants_Pizza_Base {}
class CookZPlants_MushroomPizza : CookZPlants_Pizza_Base {}

class CookZPlants_MargheritaPizza_Opened : CookZ_OpenedDish {}
class CookZPlants_PepperoniPizza_Opened : CookZ_OpenedDish {}
class CookZPlants_SeafoodPizza_Opened : CookZ_OpenedDish {}
class CookZPlants_VegetablePizza_Opened : CookZ_OpenedDish {}
class CookZPlants_MushroomPizza_Opened : CookZ_OpenedDish {}
