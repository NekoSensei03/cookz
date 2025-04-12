class CfgPatches
{
    class CookZPlants_BoxedDishes
    {
        requiredAddons[] =
        {
            "DZ_Data"
        };
    };
};

class CfgVehicles
{
    // imports

    class CookZ_Box_Base;
    class CookZ_BoxOpened_Base;

    // items

    class CookZPlants_PierogiBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PierogiBox_DN";
        descriptionShort="$STR_CookZPlants_PierogiBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_pierogi_co.paa"
        };
    };
    class CookZPlants_PierogiBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PierogiBox_DN";
        descriptionShort="$STR_CookZPlants_PierogiBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\boxed\box_pierogi_co.paa",
            "CookZPlants\data\dishes\boxed\box_food_pierogi_co.paa"
        };
        varQuantityInit=770;
        varQuantityMax=770;
        class Nutrition
        {
            energy=300;
            water=98.7013;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};
