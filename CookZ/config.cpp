class CfgPatches
{
    class CookZ
    {
        requiredAddons[] =
        {
            "DZ_Data", "DZ_Gear_Medical", "DZ_Gear_Cooking", "DZ_Gear_Consumables", "DZ_Gear_Food", "DZ_Gear_Cultivation", "DZ_Gear_Drinks"
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
        displayName = "$STR_CookZ_Slot_EmptyCans";
        ghostIcon = "set:empty_can_icon image:empty_can_icon";
    };
    class Slot_CookZ_EmptyBoxes
    {
        name = "CookZ_EmptyBoxes";
        displayName = "$STR_CookZ_Slot_EmptyBoxes";
        ghostIcon = "set:empty_box_icon image:empty_box_icon";
    };
};

class CfgVehicles
{
    // imports

    class Edible_Base;
    class Inventory_Base;
    class Snack_ColorBase;
    class SodaCan_ColorBase;
    class Bottle_Base;
    class SeedBase;

    // define crafting materials ----------------------------------------

    class CookZ_EmptyCan: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZ_EmptyCan_DN";
        descriptionShort="$STR_CookZ_EmptyCan_DS";
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
        displayName="$STR_CookZ_EmptyBox_DN";
        descriptionShort="$STR_CookZ_EmptyBox_DS";
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
        attachments[] +=
        {
            "CookZ_EmptyCans",
            "CookZ_EmptyBoxes"
        };
        class InventoryEquipment
        {
            playerSlots[] +=
            {
                "Slot_CookZ_EmptyCans",
                "Slot_CookZ_EmptyBoxes"
            };
        };
    };
    class Cauldron: Bottle_Base
    {
        attachments[] +=
        {
            "CookZ_EmptyCans",
            "CookZ_EmptyBoxes"
        };
        class InventoryEquipment
        {
            playerSlots[] +=
            {
                "Slot_CookZ_EmptyCans",
                "Slot_CookZ_EmptyBoxes"
            };
        };
    };
    class FryingPan: Inventory_Base
    {
        attachments[] +=
        {
            "CookZ_EmptyCans",
            "CookZ_EmptyBoxes"
        };
        class InventoryEquipment
        {
            playerSlots[] +=
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
        title = "$STR_CookZ_Cookbook_Title";
        author = "$STR_CookZ_Cookbook_Author";
        chapters[] = {
            "CookZ\data\cookbook\01_introdcution.html",
            "CookZ\data\cookbook\02_boxed.html",
            "CookZ\data\cookbook\03_canned.html",
            "CookZ\data\cookbook\04_sausage.html",
            "CookZ\data\cookbook\05_misc.html"
        };
        chapterIcons[] = {
            "CookZ/data/cookbook/icon_read.edds",
            "CookZ/data/cookbook/icon_box.edds",
            "CookZ/data/cookbook/icon_can.edds",
            "CookZ/data/cookbook/icon_sausage.edds",
            "CookZ/data/cookbook/icon_cheese.edds"
        };
        displayName = "$STR_CookZ_Cookbook_DN";
        descriptionShort = "$STR_CookZ_Cookbook_DS";
        scope = 2;
        hiddenSelectionsTextures[] = {"CookZ\data\cookbook\cookbook.paa"};
    };

    // make some items able to get hot ----------------------------------------

    class Rag: Inventory_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    };

    class BandageDressing: Inventory_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    };

    class DisinfectantAlcohol: Edible_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    };

    class Rice: Edible_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    };

    class Worm: Edible_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
        // give a static quantity for calculating quantity of dishes
        cookz_staticQuantity=100;
    };

    class PotatoSeed: SeedBase
    {
        cookz_staticQuantity=250;
    };
    
    class PowderedMilk: Edible_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    };

    class Bone: Inventory_Base
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
        cookz_staticQuantity=40;
    };

    class Crackers: Snack_ColorBase
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    };

    class SaltySticks: Snack_ColorBase
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    };

    class SodaCan_Kvass: SodaCan_ColorBase
    {
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=100;
    };
};
