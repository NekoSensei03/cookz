class CfgPatches
{
    class CookZPlants
    {
        requiredAddons[] =
        {
            "DZ_Data", "DZ_Gear_Cultivation", "CookZ"
        };
    };
};

class CfgMods
{
    class CookZPlants
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
                files[] = {"CookZPlants/Scripts/3_Game"};
            };
            class worldScriptModule
            {
                value = "";
                files[] = {"CookZPlants/Scripts/4_World"};
            };
            class missionScriptModule
            {
                value = "";
                files[] = {"CookZPlants/Scripts/5_Mission"};
            };
        };
    };
};

class CfgVehicles
{
    // imports

    class Edible_Base;
    class Inventory_Base;
    class SeedBase;
    class PlantBase;

    // wheat and co ----------------------------------------

    class CookZPlants_WheatSeedsPack: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_WheatSeedsPack_DN";
        descriptionShort="$STR_CookZPlants_WheatSeedsPack_DS";
        model="\dz\gear\cultivation\tomato_seeds_pack.p3d";
        hiddenSelections[]={"zbytek"};
        hiddenSelectionsTextures[]={"CookZPlants\data\plants\wheat\cookz_wheat_seeds_package_co.paa"};
        rotationFlags=17;
        quantityBar=1;
        itemSize[]={1,1};
        weight=30;
        spawnOffset=0;
        lootCategory="Materials";
        lootTag[]=
        {
            "Farm",
            "Kitchen",
            "Forester"
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=5;
                    healthLevels[]=
                    {
                        {1,             {"DZ\gear\cultivation\data\tomato_seeds.rvmat"}},
                        {0.69999999,    {"DZ\gear\cultivation\data\tomato_seeds.rvmat"}},
                        {0.5,           {"DZ\gear\cultivation\data\tomato_seeds_damage.rvmat"}},
                        {0.30000001,    {"DZ\gear\cultivation\data\tomato_seeds_damage.rvmat"}},
                        {0,             {"DZ\gear\cultivation\data\tomato_seeds_destruct.rvmat"}}
                    };
                };
            };
        };
        class Horticulture
        {
            ContainsSeedsType="CookZPlants_WheatSeeds";
            ContainsSeedsQuantity=10;
        };
        class UserActions
        {
            class EmptyPack
            {
                displayNameDefault="Empty the pack";
                displayName="Empty the pack";
                position="action";
                onlyForPlayer=1;
                radius=2;
                condition="true";
                statement="this callMethod ['EmptySeedPack', _person];";
            };
        };
        class AnimEvents
        {
            class SoundWeapon
            {
                class pickup
                {
                    soundSet="seedpack_pickup_SoundSet";
                    id=797;
                };
            };
        };
    };

    class CookZPlants_WheatSeeds: SeedBase
    {
        scope=2;
        displayName="$STR_CookZPlants_WheatSeeds_DN";
        descriptionShort="$STR_CookZPlants_WheatSeeds_DS";
        model="\dz\gear\cultivation\tomato_seeds.p3d";
        canBeSplit=1;
        varQuantityInit=20;
        varQuantityMin=0;
        varQuantityMax=20;
        class Horticulture
        {
            PlantType="CookZPlants_PlantWheat";
        };
    };

    class CookZPlants_PlantWheat: PlantBase
    {
        scope=2;
        displayName="$STR_CookZPlants_PlantWheat_DN";
        descriptionShort="$STR_CookZPlants_PlantWheat_DS";
        model="CookZPlants\data\plants\wheat\cookz_wheat_plant.p3d";
        class Horticulture
        {
            GrowthStagesCount=6;
            CropsCount=4;
            CropsType="CookZPlants_WheatEars";
        };
    };

    class CookZPlants_WheatEars: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_WheatEars_DN";
        descriptionShort="$STR_CookZPlants_WheatEars_DS";
        itemSize[]={2,1};
        rotationFlags=17;
        model="CookZPlants\data\plants\wheat\cookz_wheat_ears.p3d";
        weight=36.279999;
        soundImpactType="organic";
        canBeSplit=1;
        varQuantityInit=1;
        varQuantityMin=0;
        varQuantityMax=10;
        varQuantityDestroyOnMin=1;
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\plants\wheat\cookz_wheat_ears.rvmat"}},
                        {0.69999999, {"CookZPlants\data\plants\wheat\cookz_wheat_ears.rvmat"}},
                        {0.5, {"CookZPlants\data\plants\wheat\cookz_wheat_ears_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\plants\wheat\cookz_wheat_ears_damage.rvmat"}},
                        {0, {"CookZPlants\data\plants\wheat\cookz_wheat_ears_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_MortarAndPestle: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_MortarAndPestle_DN";
        descriptionShort="$STR_CookZPlants_MortarAndPestle_DS";
        itemSize[]={2,2};
        model="CookZPlants\data\tools\cookz_mortarpestle.p3d";
        hiddenSelections[]=
        {
            "mortarpestle"
        };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\tools\cookz_mortarpestle_co.paa"
        };
        rotationFlags=8;
        weight=1700;
        soundImpactType="metal";
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=500;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\tools\cookz_mortarpestle.rvmat"}},
                        {0.69999999, {"CookZPlants\data\tools\cookz_mortarpestle.rvmat"}},
                        {0.5, {"CookZPlants\data\tools\cookz_mortarpestle_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\tools\cookz_mortarpestle_damage.rvmat"}},
                        {0, {"CookZPlants\data\tools\cookz_mortarpestle_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_FlourBag: Edible_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_FlourBag_DN";
        descriptionShort="$STR_CookZPlants_FlourBag_DS";
        model="CookZPlants\data\ingredients\cookz_flour_bag.p3d";
        debug_ItemCategory=6;
        weight=60;
        itemSize[]={1,2};
        varQuantityInit=500;
        varQuantityMin=0;
        varQuantityMax=500;
        absorbency=0.89999998;
        rotationFlags=63;
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\ingredients\cookz_flour_bag.rvmat"}},
                        {0.69999999, {"CookZPlants\data\ingredients\cookz_flour_bag.rvmat"}},
                        {0.5, {"CookZPlants\data\ingredients\cookz_flour_bag_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\ingredients\cookz_flour_bag_damage.rvmat"}},
                        {0, {"CookZPlants\data\ingredients\cookz_flour_bag_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZPlants_Dough: Inventory_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_Dough_DN";
        descriptionShort="$STR_CookZPlants_Dough_DS";
        itemSize[]={1,1};
        model="CookZPlants\data\ingredients\cookz_dough.p3d";
        hiddenSelections[]=
        {
            "dough"
        };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\ingredients\cookz_dough_co.paa"
        };
        weight=160;
        cookz_staticQuantity=160;
        soundImpactType="organic";
        varTemperatureInit=0;
        varTemperatureMin=0;
        varTemperatureMax=120;
        class Nutrition
        {
            energy=300;
            water=200;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
        class DamageSystem
        {
            class GlobalHealth
            {
                class Health
                {
                    hitpoints=40;
                    healthLevels[]=
                    {
                        {1, {"CookZPlants\data\ingredients\cookz_dough.rvmat"}},
                        {0.69999999, {"CookZPlants\data\ingredients\cookz_dough.rvmat"}},
                        {0.5, {"CookZPlants\data\ingredients\cookz_flour_bag_damage.rvmat"}},
                        {0.30000001, {"CookZPlants\data\ingredients\cookz_flour_bag_damage.rvmat"}},
                        {0, {"CookZPlants\data\ingredients\cookz_flour_bag_destruct.rvmat"}}
                    };
                };
            };
        };
    };

    class CookZ_Cookbook_Item: Inventory_Base
    {
        chapters[] += {
            "CookZPlants\data\cookbook\01_plant_dishes.html"
        };
        chapterIcons[] += {
            "CookZPlants/data/cookbook/icon_wheat.edds"
        };
    };
};

class CfgHorticulture
{
    class Plants
    {
        class CookZPlants_PlantWheat
        {
            infestedTex="";
            infestedMat="";
            healthyTex="CookZPlants\data\plants\wheat\cookz_wheat_plant_ripe_co.paa";
            healthyMat="CookZPlants\data\plants\wheat\cookz_wheat_plant.rvmat";
        };
    };
};