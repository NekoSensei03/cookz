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
            class worldScriptModule
            {
                value = "";
                files[] = { "CookZ/Scripts/4_World" };
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
    // define recipes ----------------------------------------

    class CookZ_Recipes
    {
		// add a recipe here
        class CookZ_FriedPotatoesBox 	// name needs to be name of dish to be created
        {
            allowPot = false;			// can pot be used for recipe?
            allowCauldron = false;		// can cauldron be used for recipe?
            allowPan = true;			// can pan be used for recipe?
            needsWater = false;			// is water needed? only makes sense if pot or cauldron is allowed
            needsEmptyCan = false;      // is an empty can needed
            needsEmptyBox = true;       // is an empty box needed
            ingredients[] = {
				"Potato,4",				// <NAME>,<QUANITY>, name must be the food item name OR AnyMeat etc
                "Lard,1"
            };
        };
        class CookZ_StirFryBox
        {
            allowPot = false;
            allowCauldron = false;
            allowPan = true;
            needsWater = false;
            needsEmptyCan = false;
            needsEmptyBox = true;
            ingredients[] = {
                "Potato,1",
                "Tomato,1",
                "Zucchini,1",
                "GreenBellPepper,1",
                "Lard,1"
            };
        };
        class CookZ_FishAndChipsBox
        {
            allowPot = false;
            allowCauldron = false;
            allowPan = true;
            needsWater = false;
            needsEmptyCan = false;
            needsEmptyBox = true;
            ingredients[] = {
                "Potato,2",
                "AnyFishFillet,1",
                "Lard,1"
            };
        };
        class CookZ_RicePuddingBox
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = false;
            needsEmptyBox = true;
            ingredients[] = {
                "Rice,1",
                "PowderedMilk,1",
                "AnyFruit,2"
            };
        };
        class CookZ_MushroomRisottoBox
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = false;
            needsEmptyBox = true;
            ingredients[] = {
                "Rice,1",
                "AnyMushroom,2"
            };
        };
        class CookZ_StuffedPeppersBox
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = false;
            needsEmptyCan = false;
            needsEmptyBox = true;
            ingredients[] = {
                "GreenBellPepper,3",
                "AnyMeat,2"
            };
        };
        class CookZ_PilafBox
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = false;
            needsEmptyBox = true;
            ingredients[] = {
                "Rice,1",
                "GreenBellPepper,2",
                "Tomato,2"
            };
        };
        class CookZ_GaghBox
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = false;
            needsEmptyBox = true;
            ingredients[] = {
                "Worm,8"
            };
        };
        class CookZ_HaggisBox
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = false;
            needsEmptyBox = true;
            ingredients[] = {
                "Guts,1",
                "Potato,2"
            };
        };
        class CookZ_GoulashCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "Potato,2",
                "GreenBellPepper,1",
                "AnyMeat,1"
            };
        };
        class CookZ_PumpkinSoupCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "SlicedPumpkin,2"
            };
        };
        class CookZ_FishSoupCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "AnyFish,2",
                "Potato,1",
                "Tomato,1"
            };
        };
		class CookZ_UkhaCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "AnyFish,2",
                "Potato,1",
                "Tomato,1",
				"DisinfectantAlcohol,1"
            };
        };
        class CookZ_LecsoCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "GreenBellPepper,2",
                "Tomato,2",
                "Lard,1"
            };
        };
        class TacticalBaconCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = true;
            needsWater = false;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "PigSteakMeat,2",
                "Lard,1"
            };
        }
        class CookZ_MysteryMeatCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = true;
            needsWater = false;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "AnyMeat,3",
                "Lard,1"
            };
        }
        class CookZ_ZucchiniCaviarCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "Zucchini,3",
                "GreenBellPepper,1",
                "Tomato,1"
            };
        }
        class CookZ_AppleMarmaladeCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = false;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "Apple,6"
            };
        };
        class CookZ_PlumMarmaladeCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = false;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "Plum,6"
            };
        };
        class CookZ_PearMarmaladeCan
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = false;
            needsEmptyCan = true;
            needsEmptyBox = false;
            ingredients[] = {
                "Pear,4"
            };
        };
        class CookZ_DisinfectRags
        {
            allowPot = true;
            allowCauldron = true;
            allowPan = false;
            needsWater = true;
            needsEmptyCan = false;
            needsEmptyBox = false;
            doNotReplaceIngredients = true;
            ingredients[] = {
                "Rag,-1"    // -1 any number of rag stacks > 0
            };
        };
    }

    // define dishes - closed and opened ----------------------------------------

    class Edible_Base;
    class SpaghettiCan;
    class SpaghettiCan_Opened;
    class Marmalade;
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
					soundSet="ammoboxUnpack_SoundSet";
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
					soundSet="ammoboxUnpack_SoundSet";
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

    class CookZ_FriedPotatoesBox: CookZ_Box_Base
    {
        displayName="Fried Potatoes";
        descriptionShort="A nutritious and long-lasting box of fried potatoes. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_fried_potatoes_co.paa"
        };
    };
    class CookZ_FriedPotatoesBox_Opened: CookZ_BoxOpened_Base
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

    class CookZ_StirFryBox: CookZ_Box_Base
    {
        displayName="Stir Fry";
        descriptionShort="A nutritious and long-lasting box of stir fry. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_stir_fry_co.paa"
        };
    };
    class CookZ_StirFryBox_Opened: CookZ_BoxOpened_Base
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

    class CookZ_FishAndChipsBox: CookZ_Box_Base
    {
        displayName="Fish And Chips";
        descriptionShort="A nutritious and long-lasting box of fish and chips. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_fish_and_chips_co.paa"
        };
    };
    class CookZ_FishAndChipsBox_Opened: CookZ_BoxOpened_Base
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
    
    class CookZ_RicePuddingBox: CookZ_Box_Base
    {
        displayName="Rice Pudding";
        descriptionShort="A nutritious and long-lasting box of rice pudding. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_rice_pudding_co.paa"
        };
    };
    class CookZ_RicePuddingBox_Opened: CookZ_BoxOpened_Base
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

    class CookZ_MushroomRisottoBox: CookZ_Box_Base
    {
        displayName="Mushroom Risotto";
        descriptionShort="A nutritious and long-lasting box of mushroom risotto. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_mushroom_risotto_co.paa"
        };
    };
    class CookZ_MushroomRisottoBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Mushroom Risotto";
        descriptionShort="A nutritious box of mushroom risotto. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_mushroom_risotto_co.paa",
            "CookZ\data\box_food_mushroom_risotto_co.paa"
        };
        varQuantityInit=800
        varQuantityMax=800
        class Nutrition
        {
            fullnessIndex=3;
            energy=156.25;
            water=256.25;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_PilafBox: CookZ_Box_Base
    {
        displayName="Pilaf";
        descriptionShort="A nutritious and long-lasting box of pilaf. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_pilaf_co.paa"
        };
    };
    class CookZ_PilafBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Pilaf";
        descriptionShort="A nutritious box of pilaf. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_pilaf_co.paa",
            "CookZ\data\box_food_pilaf_co.paa"
        };
        varQuantityInit=1000
        varQuantityMax=1000
        class Nutrition
        {
            fullnessIndex=3;
            energy=135.0;
            water=82.5;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_GaghBox: CookZ_Box_Base
    {
        displayName="Gagh";
        descriptionShort="A nutritious and long-lasting box of gagh. Will last two to five years depending on storage conditions. Earth-Style: the worms are cooked.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_gagh_co.paa"
        };
    };
    class CookZ_GaghBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Gagh";
        descriptionShort="A nutritious box of gagh. Eat up before it spoils. Earth-Style: the worms are cooked.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_gagh_co.paa",
            "CookZ\data\box_food_gagh_co.paa"
        };
        varQuantityInit=800
        varQuantityMax=800
        class Nutrition
        {
            fullnessIndex=3;
            energy=150;
            water=80;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_HaggisBox: CookZ_Box_Base
    {
        displayName="Haggis with Mashed Potatoes";
        descriptionShort="A nutritious and long-lasting box of haggis with mashed potatoes. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_haggis_co.paa"
        };
    };
    class CookZ_HaggisBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Haggis with Mashed Potatoes";
        descriptionShort="A nutritious box of haggis with mashed potatoes. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_haggis_co.paa",
            "CookZ\data\box_food_haggis_co.paa"
        };
        varQuantityInit=900
        varQuantityMax=900
        class Nutrition
        {
            fullnessIndex=3;
            energy=227.78;
            water=83.78;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_StuffedPeppersBox: CookZ_Box_Base
    {
        displayName="Suffed Peppers";
        descriptionShort="A nutritious and long-lasting box of stuffed peppers. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_stuffed_peppers_co.paa"
        };
    };
    class CookZ_StuffedPeppersBox_Opened: CookZ_BoxOpened_Base
    {
        displayName="Suffed Peppers";
        descriptionShort="A nutritious box of stuffed peppers. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_stuffed_peppers_co.paa",
            "CookZ\data\box_food_stuffed_peppers_co.paa"
        };
        varQuantityInit=950
        varQuantityMax=950
        class Nutrition
        {
            fullnessIndex=3;
            energy=276.32;
            water=50.0;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_GoulashCan: SpaghettiCan
    {
        displayName="Goulash";
        descriptionShort="A nutritious and long-lasting can of goulash that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_goulash_co.paa"
        };
    };
    class CookZ_GoulashCan_Opened: SpaghettiCan_Opened
    {
        displayName="Goulash";
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

    class CookZ_PumpkinSoupCan: SpaghettiCan
    {
        displayName="Pumpkin Soup";
        descriptionShort="A nutritious and long-lasting can of pumpkin soup that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_pumpkin_soup_co.paa"
        };
    };
    class CookZ_PumpkinSoupCan_Opened: SpaghettiCan_Opened
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

    class CookZ_FishSoupCan: SpaghettiCan
    {
        displayName="Fish Soup";
        descriptionShort="A nutritious and long-lasting can of fish soup that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_fish_soup_co.paa"
        };
    };
    class CookZ_FishSoupCan_Opened: SpaghettiCan_Opened
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

	class CookZ_UkhaCan: SpaghettiCan
    {
        displayName="Ukha";
        descriptionShort="A nutritious and long-lasting can of Ukha that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_ukha_co.paa"
        };
    };
    class CookZ_UkhaCan_Opened: SpaghettiCan_Opened
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

    class CookZ_LecsoCan: SpaghettiCan
    {
        displayName="Lecso";
        descriptionShort="A nutritious and long-lasting can of Lecso that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_lecso_co.paa"
        };
    };
    class CookZ_LecsoCan_Opened: SpaghettiCan_Opened
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

    class CookZ_MysteryMeatCan: SpaghettiCan
    {
        displayName="Mystery Meat";
        descriptionShort="A nutritious and long-lasting can of mixed meats that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_mystery_meat_co.paa"
        };
    };
    class CookZ_MysteryMeatCan_Opened: SpaghettiCan_Opened
    {
        displayName="Mystery Meat";
        descriptionShort="A nutritious can of mixed meats. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_mystery_meat_co.paa"
        };
        varQuantityInit=950
        varQuantityMax=950
        class Nutrition
        {
            fullnessIndex=3;
            energy=300.0;
            water=50.0;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_ZucchiniCaviarCan: SpaghettiCan
    {
        displayName="Zucchini Caviar";
        descriptionShort="A nutritious and long-lasting can of zucchini caviar that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_zucchini_caviar_co.paa"
        };
    };
    class CookZ_ZucchiniCaviarCan_Opened: SpaghettiCan_Opened
    {
        displayName="Zucchini Caviar";
        descriptionShort="A nutritious can of zucchini caviar. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_zucchini_caviar_co.paa"
        };
        varQuantityInit=850
        varQuantityMax=850
        class Nutrition
        {
            fullnessIndex=3;
            energy=191.18;
            water=139.71;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_AppleMarmaladeCan: SpaghettiCan
    {
        displayName="Apple Marmalade";
        descriptionShort="A nutritious and long-lasting can of apple marmalade that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_apple_marmalade_co.paa"
        };
    };
    class CookZ_AppleMarmaladeCan_Opened: SpaghettiCan_Opened
    {
        displayName="Apple Marmalade";
        descriptionShort="A nutritious can of apple marmalade. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_apple_marmalade_co.paa"
        };
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

    class CookZ_PlumMarmaladeCan: SpaghettiCan
    {
        displayName="Plum Marmalade";
        descriptionShort="A nutritious and long-lasting can of plum marmalade that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_plum_marmalade_co.paa"
        };
    };
    class CookZ_PlumMarmaladeCan_Opened: SpaghettiCan_Opened
    {
        displayName="Plum Marmalade";
        descriptionShort="A nutritious can of plum marmalade. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_plum_marmalade_co.paa"
        };
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

    class CookZ_PearMarmaladeCan: SpaghettiCan
    {
        displayName="Pear Marmalade";
        descriptionShort="A nutritious and long-lasting can of pear marmalade that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_pear_marmalade_co.paa"
        };
    };
    class CookZ_PearMarmaladeCan_Opened: SpaghettiCan_Opened
    {
        displayName="Pear Marmalade";
        descriptionShort="A nutritious can of pear marmalade. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_pear_marmalade_co.paa"
        };
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

    // define crafting materials ----------------------------------------

    class Inventory_Base;
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
        model="CookZ\data\food_box.p3d";
        hiddenSelections[]=
		{
			"box"
		};
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\box_co.paa"
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

    class Bottle_Base;
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
		file = "CookZ\data\cookbook.html";
		displayName = "Survivor Cookbook";
		descriptionShort = "A cookbook for survivors.";
		scope = 2;
		hiddenSelectionsTextures[] = {"CookZ\data\cookbook.paa"};
	};

    // make some items able to get hot ----------------------------------------

    class Rag: Inventory_Base
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
