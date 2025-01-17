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

    class CookZ_Sausage_Base: Edible_Base
    {
		debug_ItemCategory=6;
		rotationFlags=32;
		itemSize[]={2,2};
		weight=265;
		varQuantityMin=0;
		isMeleeWeapon=1;
		model="CookZ\data\dishes\sausage\sausage.p3d";
        hiddenSelections[]=
		{
			"s_area"
		};
		soundImpactType="organic";
        class DamageSystem
		{
			class GlobalHealth
			{
				class Health
				{
					hitpoints=100;
					healthLevels[]=
					{
						{1,             {"CookZ\data\dishes\sausage\sausage.rvmat"}},
						{0.69999999,    {"CookZ\data\dishes\sausage\sausage.rvmat"}},
						{0.5,           {"CookZ\data\dishes\sausage\sausage_damage.rvmat"}},
						{0.30000001,    {"CookZ\data\dishes\sausage\sausage_damage.rvmat"}},
						{0,             {"CookZ\data\dishes\sausage\sausage_destruct.rvmat"}}
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

    class CookZ_Beef_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Beef Sausage";
        descriptionShort="A juicy beef sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_cow_co.paa"
        };
		varQuantityInit=500;
		varQuantityMax=500;
        class Nutrition
        {
            energy=275;
            water=87;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Chicken_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Chicken Sausage";
        descriptionShort="A juicy chicken sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_chicken_co.paa"
        };
		varQuantityInit=438;
		varQuantityMax=438;
        class Nutrition
        {
            energy=228.571;
            water=96;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Pig_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Pig Sausage";
        descriptionShort="A juicy pig sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_pig_co.paa"
        };
		varQuantityInit=500;
		varQuantityMax=500;
        class Nutrition
        {
            energy=275;
            water=87;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Goat_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Goat Sausage";
        descriptionShort="A juicy goat sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_goat_co.paa"
        };
		varQuantityInit=400;
		varQuantityMax=400;
        class Nutrition
        {
            energy=250;
            water=102.75;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Bear_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Bear Sausage";
        descriptionShort="A juicy bear sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_bear_co.paa"
        };
		varQuantityInit=500;
		varQuantityMax=500;
        class Nutrition
        {
            energy=325;
            water=87;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Sheep_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Sheep Sausage";
        descriptionShort="A juicy sheep sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_sheep_co.paa"
        };
		varQuantityInit=400;
		varQuantityMax=400;
        class Nutrition
        {
            energy=250;
            water=102.75;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Boar_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Boar Sausage";
        descriptionShort="A juicy boar sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_boar_co.paa"
        };
		varQuantityInit=500;
		varQuantityMax=500;
        class Nutrition
        {
            energy=287.5;
            water=87;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Deer_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Deer Sausage";
        descriptionShort="A juicy deer sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_deer_co.paa"
        };
		varQuantityInit=500;
		varQuantityMax=500;
        class Nutrition
        {
            energy=300;
            water=87;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Hare_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Hare Sausage";
        descriptionShort="A juicy hare sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_rabbit_co.paa"
        };
		varQuantityInit=500;
		varQuantityMax=500;
        class Nutrition
        {
            energy=200;
            water=82;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Wolf_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Wolf Sausage";
        descriptionShort="A juicy wolf sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_wolf_co.paa"
        };
		varQuantityInit=400;
		varQuantityMax=400;
        class Nutrition
        {
            energy=231.25;
            water=102.75;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Human_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Human Sausage";
        descriptionShort="A sausage made from human meat ... just don't ...";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_human_co.paa"
        };
		varQuantityInit=400;
		varQuantityMax=400;
        class Nutrition
        {
            energy=231.25;
            water=102.75;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Fox_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Fox Sausage";
        descriptionShort="A juicy fox sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_fox_co.paa"
        };
		varQuantityInit=445;
		varQuantityMax=445;
        class Nutrition
        {
            energy=228.09;
            water=94.7865;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_Reindeer_Sausage: CookZ_Sausage_Base
    {
        scope=2;
        displayName="Reindeer Sausage";
        descriptionShort="A juicy reindeer sausage, perfect for survivors in need of a quick bite.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\sausage\sausage_reindeer_co.paa"
        };
		varQuantityInit=500;
		varQuantityMax=500;
        class Nutrition
        {
            energy=238.462;
            water=120.923;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};