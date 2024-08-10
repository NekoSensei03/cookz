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
		// add a recipe here
        class FriedPotatoesBox 			// name needs to be name of dish to be created
        {
            allowPot = false;			// can pot be used for recipe?
            allowCauldron = false;		// can cauldron be used for recipe?
            allowPan = true;			// can pan be used for recipe?
            needsWater = false;			// is water needed? only makes sense if pot or cauldron is allowed
            ingredients[] = {
				"Potato,4",				// <NAME>,<QUANITY>, name must be the food item name OR AnyMeat etc
                "Lard,1"
            };
        };
        class StirFryBox
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
        class FishAndChipsBox
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
        class RicePuddingBox
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            ingredients[] = {
                "Rice,1",
                "PowderedMilk,1",
                "AnyFruit,2"
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
		class UkhaCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            ingredients[] = {
                "AnyFish,2",
                "Potato,1",
                "Tomato,1",
				"DisinfectantAlcohol,1"
            };
        };
        class LecsoCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            ingredients[] = {
                "GreenBellPepper,2",
                "Tomato,2",
                "Lard,1"
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

    class Edible_Base;
    class CookZ_Box_Base: Edible_Base
    {
        scope=2;
		debug_ItemCategory=6;
		rotationFlags=32;
		itemSize[]={2,2};
		weight=265;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		isMeleeWeapon=1;
		model="CookZ\data\food_box.p3d";
        hiddenSelections[]=
		{
			"box"
		};
		soundImpactType="metal";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\food\data\tuna.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\food\data\tuna.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\food\data\tuna_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\food\data\tuna_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\food\data\tuna_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
    }
    class CookZ_BoxOpened_Base: Edible_Base
    {
        scope=2;
		debug_ItemCategory=6;
		itemSize[]={2,2};
		weight=15;
		varQuantityMin=0;
		isMeleeWeapon=1;
		model="CookZ\data\food_box_opened.p3d";
        hiddenSelections[]=
		{
			"box_opened",
            "food"
		};
		soundImpactType="metal";
		class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=70;
					healthLevels[]=
					{
						
						{
							1,
							
							{
								"DZ\gear\food\data\tuna.rvmat"
							}
						},
						
						{
							0.69999999,
							
							{
								"DZ\gear\food\data\tuna.rvmat"
							}
						},
						
						{
							0.5,
							
							{
								"DZ\gear\food\data\tuna_damage.rvmat"
							}
						},
						
						{
							0.30000001,
							
							{
								"DZ\gear\food\data\tuna_damage.rvmat"
							}
						},
						
						{
							0,
							
							{
								"DZ\gear\food\data\tuna_destruct.rvmat"
							}
						}
					};
				};
			};
		};
		class AnimEvents
		{
			class SoundWeapon
			{
				class openTunaCan
				{
					soundSet="openTunaCan_SoundSet";
					id=204;
				};
				class Eating_TakeFood
				{
					soundSet="Eating_TakeFood_Soundset";
					id=889;
				};
				class Eating_BoxOpen
				{
					soundSet="Eating_BoxOpen_Soundset";
					id=893;
				};
				class Eating_BoxShake
				{
					soundSet="Eating_BoxShake_Soundset";
					id=894;
				};
				class Eating_BoxEnd
				{
					soundSet="Eating_BoxEnd_Soundset";
					id=895;
				};
			};
		};
    }

    class FriedPotatoesBox: CookZ_Box_Base
    {
        displayName="Fried Potatoes";
        descriptionShort="A nutritious and long-lasting box of fried potatoes. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_fried_potatoes_co.paa"
        };
    };
    class FriedPotatoesBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Fried Potatoes";
        descriptionShort="A nutritious box of fried potatoes. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_fried_potatoes_co.paa",
            "CookZ\data\box_food_fried_potatoes_co.paa"
        };
        varQuantityInit=1000;
        varQuantityMax=1000;
        class Nutrition
        {
            fullnessIndex=3;
            energy=260;
            water=30;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class StirFryBox: CookZ_Box_Base
    {
        displayName="Stir Fry";
        descriptionShort="A nutritious and long-lasting box of stir fry. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_stir_fry_co.paa"
        };
    };
    class StirFryBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Stir Fry";
        descriptionShort="A nutritious box of stir fry. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_stir_fry_co.paa",
            "CookZ\data\box_food_stir_fry_co.paa"
        };
        varQuantityInit=850
        varQuantityMax=850
        class Nutrition
        {
            fullnessIndex=3;
            energy=250.0;
            water=52.94;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class FishAndChipsBox: CookZ_Box_Base
    {
        displayName="Fish And Chips";
        descriptionShort="A nutritious and long-lasting box of fish and chips. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_fish_and_chips_co.paa"
        };
    };
    class FishAndChipsBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Fish And Chips";
        descriptionShort="A nutritious box of fish and chips. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_fish_and_chips_co.paa",
            "CookZ\data\box_food_fish_and_chips_co.paa"
        };
        varQuantityInit=1100
        varQuantityMax=1100
        class Nutrition
        {
            fullnessIndex=3;
            energy=227.27;
            water=45.45;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
    
    class RicePuddingBox: CookZ_Box_Base
    {
        displayName="Rice Pudding";
        descriptionShort="A nutritious and long-lasting box of rice pudding. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_rice_pudding_co.paa"
        };
    };
    class RicePuddingBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Rice Pudding";
        descriptionShort="A nutritious box of rice pudding. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_rice_pudding_co.paa",
            "CookZ\data\box_food_rice_pudding_co.paa"
        };
        varQuantityInit=1000
        varQuantityMax=1000
        class Nutrition
        {
            fullnessIndex=3;
            energy=205.0;
            water=80.0;
            nutritionalIndex=1;
            toxicity=0;
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
            fullnessIndex=3;
            energy=215.625;
            water=70.8125;
            nutritionalIndex=1;
            toxicity=0;
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
        varQuantityInit=500
        varQuantityMax=500
        class Nutrition
        {
            fullnessIndex=3;
            energy=125.0;
            water=100.0;
            nutritionalIndex=1;
            toxicity=0;
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
        varQuantityInit=1300
        varQuantityMax=1300
        class Nutrition
        {
            fullnessIndex=3;
            energy=155.77;
            water=123.23;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

	class UkhaCan: SpaghettiCan
    {
        displayName="Ukha";
        descriptionShort="A nutritious and long-lasting can of Ukha that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_ukha_co.paa"
        };
    };
    class UkhaCan_Opened: SpaghettiCan_Opened
    {
        displayName="Ukha";
        descriptionShort="A nutritious can of Ukha. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_ukha_co.paa"
        };
        varQuantityInit=1500
        varQuantityMax=1500
        class Nutrition
        {
            fullnessIndex=3;
            energy=161.67;
            water=106.8;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class LecsoCan: SpaghettiCan
    {
        displayName="Lecso";
        descriptionShort="A nutritious and long-lasting can of Lecso that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_lecso_co.paa"
        };
    };
    class LecsoCan_Opened: SpaghettiCan_Opened
    {
        displayName="Lecso";
        descriptionShort="A nutritious can of Lecso. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_lecso_co.paa"
        };
        varQuantityInit=700
        varQuantityMax=700
        class Nutrition
        {
            fullnessIndex=3;
            energy=192.86;
            water=110.71;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class AppleMarmalade: Marmalade
    {
        displayName="Apple Marmalade";
        descriptionShort="A nutritious and long-lasting jar of apple marmalade. Will last two to five years depending on storage conditions.";
        varQuantityInit=750
        varQuantityMax=750
        class Nutrition
        {
            fullnessIndex=3;
            energy=250.0;
            water=75.0;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class PlumMarmalade: Marmalade
    {
        displayName="Plum Marmalade";
        descriptionShort="A nutritious and long-lasting jar of plum marmalade. Will last two to five years depending on storage conditions.";
        varQuantityInit=450
        varQuantityMax=450
        class Nutrition
        {
            fullnessIndex=3;
            energy=300.0;
            water=125.0;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class PearMarmalade: Marmalade
    {
        displayName="Pear Marmalade";
        descriptionShort="A nutritious and long-lasting jar of pear marmalade. Will last two to five years depending on storage conditions.";
        varQuantityInit=600
        varQuantityMax=600
        class Nutrition
        {
            fullnessIndex=3;
            energy=300.0;
            water=50.0;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
}