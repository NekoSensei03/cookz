class CfgPatches
{
    class CookZ
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

    class Edible_Base;

    // bases

    class CookZ_Box_Base: Edible_Base
    {
		debug_ItemCategory=6;
		itemSize[]={2,2};
		weight=265;
		varQuantityInit=0;
		varQuantityMin=0;
		varQuantityMax=0;
		isMeleeWeapon=1;
		model="CookZ\data\dishes\boxed\food_box.p3d";
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
					hitpoints=100;
					healthLevels[]=
					{
						{1,             {"CookZ\data\dishes\boxed\box.rvmat"}},
						{0.69999999,    {"CookZ\data\dishes\boxed\box.rvmat"}},
						{0.5,           {"CookZ\data\dishes\boxed\box_damage.rvmat"}},
						{0.30000001,    {"CookZ\data\dishes\boxed\box_damage.rvmat"}},
						{0,             {"CookZ\data\dishes\boxed\box_destruct.rvmat"}}
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
    };

    class CookZ_BoxOpened_Base: Edible_Base
    {
		debug_ItemCategory=6;
		itemSize[]={2,2};
		weight=265;
		varQuantityMin=0;
		isMeleeWeapon=1;
		model="CookZ\data\dishes\boxed\food_box_opened.p3d";
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
					hitpoints=100;
					healthLevels[]=
					{
						{1,             {"CookZ\data\dishes\boxed\box.rvmat"}},
						{0.69999999,    {"CookZ\data\dishes\boxed\box.rvmat"}},
						{0.5,           {"CookZ\data\dishes\boxed\box_damage.rvmat"}},
						{0.30000001,    {"CookZ\data\dishes\boxed\box_damage.rvmat"}},
						{0,             {"CookZ\data\dishes\boxed\box_destruct.rvmat"}}
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
    };

    // items

    class CookZ_FriedPotatoesBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_FriedPotatoesBox_DN";
        descriptionShort="$STR_CookZ_FriedPotatoesBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_fried_potatoes_co.paa"
        };
    };
    class CookZ_FriedPotatoesBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_FriedPotatoesBox_DN";
        descriptionShort="$STR_CookZ_FriedPotatoesBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_fried_potatoes_co.paa",
            "CookZ\data\dishes\boxed\box_food_fried_potatoes_co.paa"
        };
        varQuantityInit=1000;
        varQuantityMax=1000;
        class Nutrition
        {
            energy=260;
            water=12.4;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_StirFryBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_StirFryBox_DN";
        descriptionShort="$STR_CookZ_StirFryBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stir_fry_co.paa"
        };
    };
    class CookZ_StirFryBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_StirFryBox_DN";
        descriptionShort="$STR_CookZ_StirFryBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stir_fry_co.paa",
            "CookZ\data\dishes\boxed\box_food_stir_fry_co.paa"
        };
        varQuantityInit=850;
        varQuantityMax=850;
        class Nutrition
        {
            energy=250;
            water=19.5294;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_FishAndChipsBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_FishAndChipsBox_DN";
        descriptionShort="$STR_CookZ_FishAndChipsBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_fish_and_chips_co.paa"
        };
    };
    class CookZ_FishAndChipsBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_FishAndChipsBox_DN";
        descriptionShort="$STR_CookZ_FishAndChipsBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_fish_and_chips_co.paa",
            "CookZ\data\dishes\boxed\box_food_fish_and_chips_co.paa"
        };
        varQuantityInit=1100;
        varQuantityMax=1100;
        class Nutrition
        {
            energy=227.273;
            water=45.4545;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
    
    class CookZ_RicePuddingBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_RicePuddingBox_DN";
        descriptionShort="$STR_CookZ_RicePuddingBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_rice_pudding_co.paa"
        };
    };
    class CookZ_RicePuddingBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_RicePuddingBox_DN";
        descriptionShort="$STR_CookZ_RicePuddingBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_rice_pudding_co.paa",
            "CookZ\data\dishes\boxed\box_food_rice_pudding_co.paa"
        };
        varQuantityInit=950;
        varQuantityMax=950;
        class Nutrition
        {
            energy=210.526;
            water=95.7895;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_MushroomRisottoBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_MushroomRisottoBox_DN";
        descriptionShort="$STR_CookZ_MushroomRisottoBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_mushroom_risotto_co.paa"
        };
    };
    class CookZ_MushroomRisottoBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_MushroomRisottoBox_DN";
        descriptionShort="$STR_CookZ_MushroomRisottoBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_mushroom_risotto_co.paa",
            "CookZ\data\dishes\boxed\box_food_mushroom_risotto_co.paa"
        };
        varQuantityInit=800;
        varQuantityMax=800;
        class Nutrition
        {
            energy=156.25;
            water=141.25;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_PilafBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_PilafBox_DN";
        descriptionShort="$STR_CookZ_PilafBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pilaf_co.paa"
        };
    };
    class CookZ_PilafBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_PilafBox_DN";
        descriptionShort="$STR_CookZ_PilafBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pilaf_co.paa",
            "CookZ\data\dishes\boxed\box_food_pilaf_co.paa"
        };
        varQuantityInit=1000;
        varQuantityMax=1000;
        class Nutrition
        {
            energy=135;
            water=96.9;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_GaghBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_GaghBox_DN";
        descriptionShort="$STR_CookZ_GaghBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_gagh_co.paa"
        };
    };
    class CookZ_GaghBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_GaghBox_DN";
        descriptionShort="$STR_CookZ_GaghBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_gagh_co.paa",
            "CookZ\data\dishes\boxed\box_food_gagh_co.paa"
        };
        varQuantityInit=800;
        varQuantityMax=800;
        class Nutrition
        {
            energy=150;
            water=130;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_HaggisBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_HaggisBox_DN";
        descriptionShort="$STR_CookZ_HaggisBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_haggis_co.paa"
        };
    };
    class CookZ_HaggisBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_HaggisBox_DN";
        descriptionShort="$STR_CookZ_HaggisBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_haggis_co.paa",
            "CookZ\data\dishes\boxed\box_food_haggis_co.paa"
        };
        varQuantityInit=900;
        varQuantityMax=900;
        class Nutrition
        {
            energy=227.778;
            water=136.667;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_StuffedPeppersBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_StuffedPeppersBox_DN";
        descriptionShort="$STR_CookZ_StuffedPeppersBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stuffed_peppers_co.paa"
        };
    };
    class CookZ_StuffedPeppersBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_StuffedPeppersBox_DN";
        descriptionShort="$STR_CookZ_StuffedPeppersBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stuffed_peppers_co.paa",
            "CookZ\data\dishes\boxed\box_food_stuffed_peppers_co.paa"
        };
        varQuantityInit=950;
        varQuantityMax=950;
        class Nutrition
        {
            energy=276.316;
            water=22.1053;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_PommdoenerBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_PommdoenerBox_DN";
        descriptionShort="$STR_CookZ_PommdoenerBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pommdoener_co.paa"
        };
    };
    class CookZ_PommdoenerBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_PommdoenerBox_DN";
        descriptionShort="$STR_CookZ_PommdoenerBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pommdoener_co.paa",
            "CookZ\data\dishes\boxed\box_food_pommdoener_co.paa"
        };
        varQuantityInit=1100;
        varQuantityMax=1100;
        class Nutrition
        {
            energy=281.818;
            water=19.2727;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_BangersAndMashBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_BangersAndMashBox_DN";
        descriptionShort="$STR_CookZ_BangersAndMashBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_bangers_and_mash_co.paa"
        };
    };
    class CookZ_BangersAndMashBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_BangersAndMashBox_DN";
        descriptionShort="$STR_CookZ_BangersAndMashBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_bangers_and_mash_co.paa",
            "CookZ\data\dishes\boxed\box_food_bangers_and_mash_co.paa"
        };
        varQuantityInit=900;
        varQuantityMax=900;
        class Nutrition
        {
            energy=241.667;
            water=56;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_CurrywurstBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_CurrywurstBox_DN";
        descriptionShort="$STR_CookZ_CurrywurstBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_currywurst_co.paa"
        };
    };
    class CookZ_CurrywurstBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_CurrywurstBox_DN";
        descriptionShort="$STR_CookZ_CurrywurstBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_currywurst_co.paa",
            "CookZ\data\dishes\boxed\box_food_currywurst_co.paa"
        };
        varQuantityInit=1000;
        varQuantityMax=1000;
        class Nutrition
        {
            energy=262.5;
            water=60.6;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_StuffedMushroomsBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_StuffedMushroomsBox_DN";
        descriptionShort="$STR_CookZ_StuffedMushroomsBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stuffed_mushrooms_co.paa"
        };
    };
    class CookZ_StuffedMushroomsBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_StuffedMushroomsBox_DN";
        descriptionShort="$STR_CookZ_StuffedMushroomsBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_stuffed_mushrooms_co.paa",
            "CookZ\data\dishes\boxed\box_food_stuffed_mushrooms_co.paa"
        };
        varQuantityInit=800;
        varQuantityMax=800;
        class Nutrition
        {
            energy=318.75;
            water=63.75;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_RabbitRoastBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_RabbitRoastBox_DN";
        descriptionShort="$STR_CookZ_RabbitRoastBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_rabbit_roast_co.paa"
        };
    };
    class CookZ_RabbitRoastBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_RabbitRoastBox_DN";
        descriptionShort="$STR_CookZ_RabbitRoastBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_rabbit_roast_co.paa",
            "CookZ\data\dishes\boxed\box_food_rabbit_roast_co.paa"
        };
        varQuantityInit=1100;
        varQuantityMax=1100;
        class Nutrition
        {
            energy=177.273;
            water=20;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_NuggiesAndFriesBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_NuggiesAndFriesBox_DN";
        descriptionShort="$STR_CookZ_NuggiesAndFriesBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_nuggies_and_fries_co.paa"
        };
    };
    class CookZ_NuggiesAndFriesBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_NuggiesAndFriesBox_DN";
        descriptionShort="$STR_CookZ_NuggiesAndFriesBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_nuggies_and_fries_co.paa",
            "CookZ\data\dishes\boxed\box_food_nuggies_and_fries_co.paa"
        };
        varQuantityInit=850;
        varQuantityMax=850;
        class Nutrition
        {
            energy=247.059;
            water=17.8824;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_SchnitzelBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_SchnitzelBox_DN";
        descriptionShort="$STR_CookZ_SchnitzelBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_schnitzel_co.paa"
        };
    };
    class CookZ_SchnitzelBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_SchnitzelBox_DN";
        descriptionShort="$STR_CookZ_SchnitzelBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_schnitzel_co.paa",
            "CookZ\data\dishes\boxed\box_food_schnitzel_co.paa"
        };
        varQuantityInit=750;
        varQuantityMax=750;
        class Nutrition
        {
            energy=290;
            water=24;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_BiffALaNelsonBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_BiffALaNelsonBox_DN";
        descriptionShort="$STR_CookZ_BiffALaNelsonBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_biff_a_la_nelson_co.paa"
        };
    };
    class CookZ_BiffALaNelsonBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_BiffALaNelsonBox_DN";
        descriptionShort="$STR_CookZ_BiffALaNelsonBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_biff_a_la_nelson_co.paa",
            "CookZ\data\dishes\boxed\box_food_biff_a_la_nelson_co.paa"
        };
        varQuantityInit=1230;
        varQuantityMax=1230;
        class Nutrition
        {
            energy=216.667;
            water=36.5041;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_PorkAndAppleBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_PorkAndAppleBox_DN";
        descriptionShort="$STR_CookZ_PorkAndAppleBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pork_and_apple_co.paa"
        };
    };
    class CookZ_PorkAndAppleBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_PorkAndAppleBox_DN";
        descriptionShort="$STR_CookZ_PorkAndAppleBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_pork_and_apple_co.paa",
            "CookZ\data\dishes\boxed\box_food_pork_and_apple_co.paa"
        };
        varQuantityInit=975;
        varQuantityMax=975;
        class Nutrition
        {
            energy=273.077;
            water=18.6667;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_ChickenCordonBleuBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_ChickenCordonBleuBox_DN";
        descriptionShort="$STR_CookZ_ChickenCordonBleuBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_chicken_cordon_bleu_co.paa"
        };
    };
    class CookZ_ChickenCordonBleuBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_ChickenCordonBleuBox_DN";
        descriptionShort="$STR_CookZ_ChickenCordonBleuBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_chicken_cordon_bleu_co.paa",
            "CookZ\data\dishes\boxed\box_food_chicken_cordon_bleu_co.paa"
        };
        varQuantityInit=700;
        varQuantityMax=700;
        class Nutrition
        {
            energy=260.714;
            water=43.7143;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_RatatouilleBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_RatatouilleBox_DN";
        descriptionShort="$STR_CookZ_RatatouilleBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_ratatouille_co.paa"
        };
    };
    class CookZ_RatatouilleBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_RatatouilleBox_DN";
        descriptionShort="$STR_CookZ_RatatouilleBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_ratatouille_co.paa",
            "CookZ\data\dishes\boxed\box_food_ratatouille_co.paa"
        };
        varQuantityInit=1000;
        varQuantityMax=1000;
        class Nutrition
        {
            energy=240;
            water=15.2;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_BakedPotatoVegBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_BakedPotatoVegBox_DN";
        descriptionShort="$STR_CookZ_BakedPotatoVegBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_baked_potato_with_vegetables_co.paa"
        };
    };
    class CookZ_BakedPotatoVegBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_BakedPotatoVegBox_DN";
        descriptionShort="$STR_CookZ_BakedPotatoVegBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_baked_potato_with_vegetables_co.paa",
            "CookZ\data\dishes\boxed\box_food_baked_potato_with_vegetables_co.paa"
        };
        varQuantityInit=1150;
        varQuantityMax=1150;
        class Nutrition
        {
            energy=273.913;
            water=36.5217;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_BakedPotatoMeatBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_BakedPotatoMeatBox_DN";
        descriptionShort="$STR_CookZ_BakedPotatoMeatBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_baked_potato_with_meat_co.paa"
        };
    };
    class CookZ_BakedPotatoMeatBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_BakedPotatoMeatBox_DN";
        descriptionShort="$STR_CookZ_BakedPotatoMeatBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_baked_potato_with_meat_co.paa",
            "CookZ\data\dishes\boxed\box_food_baked_potato_with_meat_co.paa"
        };
        varQuantityInit=1200;
        varQuantityMax=1200;
        class Nutrition
        {
            energy=302.083;
            water=37.5;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_BakedPotatoFishBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_BakedPotatoFishBox_DN";
        descriptionShort="$STR_CookZ_BakedPotatoFishBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_baked_potato_with_seafood_co.paa"
        };
    };
    class CookZ_BakedPotatoFishBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_BakedPotatoFishBox_DN";
        descriptionShort="$STR_CookZ_BakedPotatoFishBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_baked_potato_with_seafood_co.paa",
            "CookZ\data\dishes\boxed\box_food_baked_potato_with_seafood_co.paa"
        };
        varQuantityInit=1300;
        varQuantityMax=1300;
        class Nutrition
        {
            energy=221.154;
            water=34.6154;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_PaprikasKrumpliBox: CookZ_Box_Base
    {
        scope=2;
        displayName="$STR_CookZ_PaprikasKrumpliBox_DN";
        descriptionShort="$STR_CookZ_PaprikasKrumpliBox_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_paprikas_krumpli_co.paa"
        };
    };
    class CookZ_PaprikasKrumpliBox_Opened: CookZ_BoxOpened_Base
    {
        scope=2;
        displayName="$STR_CookZ_PaprikasKrumpliBox_DN";
        descriptionShort="$STR_CookZ_PaprikasKrumpliBox_Opened_DS";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\boxed\box_paprikas_krumpli_co.paa",
            "CookZ\data\dishes\boxed\box_food_paprikas_krumpli_co.paa"
        };
        varQuantityInit=1200;
        varQuantityMax=1200;
        class Nutrition
        {
            energy=260.417;
            water=43.9167;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};