class CfgPatches
{
    class CookZ
    {
        requiredAddons[] =
        {
            "DZ_Data", "DZ_Gear_Medical"
        };
    };
};

class CfgMods
{
    class CookZ
    {
        type = "mod";
        dependencies[] =
        {
            "Game", "World", "Mission"
        };
        class defs
        {
            class gameScriptModule
            {
                value = "";
                files[] = {"CookZ/Scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"CookZ/Scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"CookZ/Scripts/5_Mission"};
            };
            class imageSets
            {
                files[] = {
                    "CookZ\GUI\ImageSets\empty_box_icon.imageset",
                    "CookZ\GUI\ImageSets\empty_can_icon.imageset"
                };
            };
        };
    };
};

class CfgSlots
{
    class Slot_CookZ_EmptyCans
    {
        name = "CookZ_EmptyCans";
        displayName = "Empty Cans";
        ghostIcon = "set:empty_can_icon image:empty_can_icon";
    };
    class Slot_CookZ_EmptyBoxes
    {
        name = "CookZ_EmptyBoxes";
        displayName = "Empty Boxes";
        ghostIcon = "set:empty_box_icon image:empty_box_icon";
    };
};

class CfgVehicles
{
    // imports

    class Edible_Base;
    class Inventory_Base;
    class Bottle_Base;

    // define crafting materials ----------------------------------------

    class CookZ_EmptyCan: Inventory_Base
    {
        scope=2;
        displayName="Empty Can";
        descriptionShort="An empty can. Can be used to put cooked food inside.";
        itemSize[]={1,2};
        model="\dz\gear\food\food_can.p3d";
        hiddenSelections[]=
        {
            "camoGround"
        };
        hiddenSelectionsTextures[]=
        {
            "dz\gear\food\data\UnknownFoodCan_co.paa"
        };
        weight=36.279999;
        soundImpactType="metal";
        canBeSplit=1;
        varQuantityInit=1;
        varQuantityMin=0;
        varQuantityMax=10;
        varQuantityDestroyOnMin=1;
        inventorySlot[] = {"CookZ_EmptyCans"};
    };

    class CookZ_EmptyBox: Inventory_Base
    {
        scope=2;
        displayName="Empty Box";
        descriptionShort="An empty box. Can be used to put cooked food inside.";
        itemSize[]={1,2};
        model="CookZ\data\dishes\boxed\food_box.p3d";
        hiddenSelections[]=
        {
            "box"
        };
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_co.paa"
        };
        weight=36.279999;
        soundImpactType="metal";
        canBeSplit=1;
        varQuantityInit=1;
        varQuantityMin=0;
        varQuantityMax=10;
        varQuantityDestroyOnMin=1;
        inventorySlot[] = {"CookZ_EmptyBoxes"};
    };

    // define equipment slots ----------------------------------------

    class Pot: Bottle_Base
    {
        attachments[]=
        {
            "CookZ_EmptyCans",
            "CookZ_EmptyBoxes"
        };
        class InventoryEquipment
        {
            playerSlots[]=
            {
                "Slot_CookZ_EmptyCans",
                "Slot_CookZ_EmptyBoxes"
            };
        };
    };
    class Cauldron: Bottle_Base
    {
        attachments[]=
        {
            "CookZ_EmptyCans",
            "CookZ_EmptyBoxes"
        };
        class InventoryEquipment
        {
            playerSlots[]=
            {
                "Slot_CookZ_EmptyCans",
                "Slot_CookZ_EmptyBoxes"
            };
        };
    };
    class FryingPan: Inventory_Base
    {
        attachments[]=
        {
            "CookZ_EmptyCans",
            "CookZ_EmptyBoxes"
        };
        class InventoryEquipment
        {
            playerSlots[]=
            {
                "Slot_CookZ_EmptyCans",
                "Slot_CookZ_EmptyBoxes"
            };
        };
    };

    // define readable cookbook ----------------------------------------

    class CookZ_Cookbook_Item: Inventory_Base
    {
        model = "dZ\gear\books\Book_kniga.p3d";
        rotationFlags = 1;
        weight = 150;
        itemSize[] = {2,2};
        hiddenSelections[] = {"zbytek"};
        title = "Cooking for Survivors";
        author = "By a Survivor";
        chapters[] = {
            "CookZ\data\cookbook\01_introdcution.html",
            "CookZ\data\cookbook\02_boxed.html",
            "CookZ\data\cookbook\03_canned.html",
            "CookZ\data\cookbook\04_sausage.html",
            "CookZ\data\cookbook\05_misc.html"
        };
        displayName = "Survivor Cookbook";
        descriptionShort = "A cookbook for survivors.";
        scope = 2;
        hiddenSelectionsTextures[] = {"CookZ\data\cookbook\cookbook.paa"};
    };

    // make some items able to get hot ----------------------------------------

    class Rag: Inventory_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    }

    class BandageDressing: Inventory_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    }

    class DisinfectantAlcohol: Edible_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    }

    class Rice: Edible_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    }

    class Worm: Edible_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    }
    
    class PowderedMilk: Edible_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    }
};
