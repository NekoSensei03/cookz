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

    class CookZ_Cheese_Base: Edible_Base
    {
		debug_ItemCategory=6;
		rotationFlags=16;
		itemSize[]={2,1};
		weight=200;
		varQuantityMin=0;
		isMeleeWeapon=1;
		model="CookZ\data\dishes\cheese\cookz_cheese.p3d";
        hiddenSelections[]=
		{
			"cheese"
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
						{1,             {"CookZ\data\dishes\cheese\cookz_cheese.rvmat"}},
						{0.69999999,    {"CookZ\data\dishes\cheese\cookz_cheese.rvmat"}},
						{0.5,           {"CookZ\data\dishes\cheese\cookz_cheese_damage.rvmat"}},
						{0.30000001,    {"CookZ\data\dishes\cheese\cookz_cheese_damage.rvmat"}},
						{0,             {"CookZ\data\dishes\cheese\cookz_cheese_destruct.rvmat"}}
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

    class CookZ_Cheese: CookZ_Cheese_Base
    {
        scope=2;
        displayName="Cheese";
        descriptionShort="A piece of makeshift cheese. It almost tastes like the real thing.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\cheese\cookz_cheese_co.paa"
        };
		varQuantityInit=200;
		varQuantityMax=200;
        class Nutrition
        {
            energy=375;
            water=115;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};