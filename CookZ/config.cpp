class CfgPatches
{
    class CookZ
    {
        requiredAddons[] =
        {
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
            "World"
        };
        class defs
        {
            class worldScriptModule
            {
                value = "";
                files[] = { "CookZ/Scripts/4_World" };
            };
        };
    };
};

class CfgVehicles
{
    class SpaghettiCan;
    class SpaghettiCan_Opened;
    class Marmalade;

    class Recipes
    {
        class FriedPotatoesCan
        {
            allowPot = false;
            allowCauldron = false;
            allowPan = true;
            needsWater = false;
            ingredients[] = {
				"Potato,4",
                "Lard,1"
            };
        };
        class StirFryCan
        {
            allowPot = false;
            allowCauldron = false;
            allowPan = true;
            needsWater = false;
            ingredients[] = {
                "Potato,1",
                "Tomato,1",
                "Zucchini,1",
                "GreenBellPepper,1",
                "Lard,1"
            };
        };
        class FishAndChipsCan
        {
            allowPot = false;
            allowCauldron = false;
            allowPan = true;
            needsWater = false;
            ingredients[] = {
                "Potato,2",
                "AnyFishFillet,1",
                "Lard,1"
            };
        };
        class GoulashCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            ingredients[] = {
                "Potato,2",
                "GreenBellPepper,1",
                "AnyMeat,1"
            };
        };
        class PumpkinSoupCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            ingredients[] = {
                "SlicedPumpkin,2"
            };
        };
        class FishSoupCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            ingredients[] = {
                "AnyFish,2",
                "Potato,1",
                "Tomato,1"
            };
        };
        class AppleMarmalade
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = false;
            ingredients[] = {
                "Apple,6"
            };
        };
        class PlumMarmalade
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = false;
            ingredients[] = {
                "Plum,6"
            };
        };
        class PearMarmalade
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = false;
            ingredients[] = {
                "Pear,4"
            };
        };
    }

    class FriedPotatoesCan: SpaghettiCan
    {
        displayName="Canned Fried Potatoes";
        descriptionShort="A nutritious and long-lasting can of fried potatoes that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_fried_potatoes_co.paa"
        };
    };
    class FriedPotatoesCan_Opened: SpaghettiCan_Opened
    {
        displayName="Canned Fried Potatoes";
        descriptionShort="A nutritious can of fried potatoes. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_fried_potatoes_co.paa"
        };
    };

    class GoulashCan: SpaghettiCan
    {
        displayName="Canned Goulash";
        descriptionShort="A nutritious and long-lasting can of goulash that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_goulash_co.paa"
        };
    };
    class GoulashCan_Opened: SpaghettiCan_Opened
    {
        displayName="Canned Goulash";
        descriptionShort="A nutritious can of goulash. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_goulash_co.paa"
        };
        varQuantityInit=800;
        varQuantityMax=800;
        class Nutrition
        {
            fullnessIndex=2;
            energy=215.625;
            water=70.8125;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class StirFryCan: SpaghettiCan
    {
        displayName="Canned Stir Fry";
        descriptionShort="A nutritious and long-lasting can of stir fry that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_stir_fry_co.paa"
        };
    };
    class StirFryCan_Opened: SpaghettiCan_Opened
    {
        displayName="Canned Stir Fry";
        descriptionShort="A nutritious can of stir fry. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_stir_fry_co.paa"
        };
    };

    class PumpkinSoupCan: SpaghettiCan
    {
        displayName="Pumpkin Soup";
        descriptionShort="A nutritious and long-lasting can of pumpkin soup that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_pumpkin_soup_co.paa"
        };
    };
    class PumpkinSoupCan_Opened: SpaghettiCan_Opened
    {
        displayName="Pumpkin Soup";
        descriptionShort="A nutritious can of pumpkin soup. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_pumpkin_soup_co.paa"
        };
    };

    class FishSoupCan: SpaghettiCan
    {
        displayName="Fish Soup";
        descriptionShort="A nutritious and long-lasting can of fish soup that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_fish_soup_co.paa"
        };
    };
    class FishSoupCan_Opened: SpaghettiCan_Opened
    {
        displayName="Fish Soup";
        descriptionShort="A nutritious can of fish soup. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_fish_soup_co.paa"
        };
    };

    class FishAndChipsCan: SpaghettiCan
    {
        displayName="Fish And Chips";
        descriptionShort="A nutritious and long-lasting can of fish and chips that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_fish_and_chips_co.paa"
        };
    };
    class FishAndChipsCan_Opened: SpaghettiCan_Opened
    {
        displayName="Fish And Chips";
        descriptionShort="A nutritious can of fish and chips. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_fish_and_chips_co.paa"
        };
    };

    class AppleMarmalade: Marmalade
    {
        displayName="Apple Marmalade";
        descriptionShort="A nutritious and long-lasting jar of apple marmalade. Will last two to five years depending on storage conditions.";
    };

    class PlumMarmalade: Marmalade
    {
        displayName="Plum Marmalade";
        descriptionShort="A nutritious and long-lasting jar of plum marmalade. Will last two to five years depending on storage conditions.";
    };

    class PearMarmalade: Marmalade
    {
        displayName="Pear Marmalade";
        descriptionShort="A nutritious and long-lasting jar of pear marmalade. Will last two to five years depending on storage conditions.";
    };
}