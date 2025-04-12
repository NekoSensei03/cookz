class CfgPatches
{
    class CookZ_Pizza
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

    class CookZ_Pizza_Base: Edible_Base
    {
        debug_ItemCategory=6;
        itemSize[]={3,2};
        weight=265;
        varQuantityInit=0;
        varQuantityMin=0;
        varQuantityMax=0;
        varTemperatureFreezeTime=1980;
        varTemperatureThawTime=1980;
        varTemperatureMax=120;
        isMeleeWeapon=1;
        model="CookZPlants\data\dishes\pizza\cookz_pizza_box_closed.p3d";
        hiddenSelections[]=
        {
            "box"
        };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\pizza\pizza_box_co.paa"
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
                        {1,             {"CookZPlants\data\dishes\pizza\pizza_box.rvmat"}},
                        {0.69999999,    {"CookZPlants\data\dishes\pizza\pizza_box.rvmat"}},
                        {0.5,           {"CookZPlants\data\dishes\pizza\pizza_box_damage.rvmat"}},
                        {0.30000001,    {"CookZPlants\data\dishes\pizza\pizza_box_damage.rvmat"}},
                        {0,             {"CookZPlants\data\dishes\pizza\pizza_box_destruct.rvmat"}}
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

    class CookZ_PizzaOpened_Base: Edible_Base
    {
        debug_ItemCategory=6;
        itemSize[]={3,2};
        weight=265;
        varQuantityMin=0;
        varTemperatureFreezeTime=1980;
        varTemperatureThawTime=1980;
        varTemperatureMax=120;
        isMeleeWeapon=1;
        model="CookZPlants\data\dishes\pizza\cookz_pizza_box_opened.p3d";
        hiddenSelections[]=
        {
            "dough",
            "box",
            "topping"
        };
        hiddenSelectionsTextures[]=
        {
            "CookZPlants\data\dishes\pizza\pizza_dough_co.paa",
            "CookZPlants\data\dishes\pizza\pizza_box_co.paa",
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
                        {1, {
                            "CookZPlants\data\dishes\pizza\pizza_dough.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_box.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_topping.rvmat"
                        }},
                        {0.69999999, {
                            "CookZPlants\data\dishes\pizza\pizza_dough.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_box.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_topping.rvmat"
                        }},
                        {0.5, {
                            "CookZPlants\data\dishes\pizza\pizza_dough_damage.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_box_damage.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_topping_damage.rvmat"
                        }},
                        {0.30000001, {
                            "CookZPlants\data\dishes\pizza\pizza_dough_damage.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_box_damage.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_topping_damage.rvmat"
                        }},
                        {0, {
                            "CookZPlants\data\dishes\pizza\pizza_dough_destruct.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_box_destruct.rvmat",
                            "CookZPlants\data\dishes\pizza\pizza_topping_destruct.rvmat"
                        }}
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

    class CookZPlants_MargheritaPizza: CookZ_Pizza_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_MargheritaPizza_DN";
        descriptionShort="$STR_CookZPlants_MargheritaPizza_DS";
    };
    class CookZPlants_MargheritaPizza_Opened: CookZ_PizzaOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_MargheritaPizza_DN";
        descriptionShort="$STR_CookZPlants_MargheritaPizza_Opened_DS";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\dishes\pizza\pizza_margherita_topping_co.paa"
        };
        varQuantityInit=920;
        varQuantityMax=920;
        class Nutrition
        {
            energy=300;
            water=126.087;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

	class CookZPlants_PepperoniPizza: CookZ_Pizza_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PepperoniPizza_DN";
        descriptionShort="$STR_CookZPlants_PepperoniPizza_DS";
    };
    class CookZPlants_PepperoniPizza_Opened: CookZ_PizzaOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_PepperoniPizza_DN";
        descriptionShort="$STR_CookZPlants_PepperoniPizza_Opened_DS";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\dishes\pizza\pizza_pepperoni_topping_co.paa"
        };
        varQuantityInit=1220;
        varQuantityMax=1220;
        class Nutrition
        {
            energy=277.459;
            water=111.885;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

	class CookZPlants_SeafoodPizza: CookZ_Pizza_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SeafoodPizza_DN";
        descriptionShort="$STR_CookZPlants_SeafoodPizza_DS";
    };
    class CookZPlants_SeafoodPizza_Opened: CookZ_PizzaOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_SeafoodPizza_DN";
        descriptionShort="$STR_CookZPlants_SeafoodPizza_Opened_DS";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\dishes\pizza\pizza_seafood_topping_co.paa"
        };
        varQuantityInit=1720;
        varQuantityMax=1720;
        class Nutrition
        {
            energy=204.07;
            water=68.0233;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

	class CookZPlants_VegetablePizza: CookZ_Pizza_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_VegetablePizza_DN";
        descriptionShort="$STR_CookZPlants_VegetablePizza_DS";
    };
    class CookZPlants_VegetablePizza_Opened: CookZ_PizzaOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_VegetablePizza_DN";
        descriptionShort="$STR_CookZPlants_VegetablePizza_Opened_DS";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\dishes\pizza\pizza_vegetable_topping_co.paa"
        };
        varQuantityInit=1070;
        varQuantityMax=1070;
        class Nutrition
        {
            energy=269.626;
            water=92.5234;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

	class CookZPlants_MushroomPizza: CookZ_Pizza_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_MushroomPizza_DN";
        descriptionShort="$STR_CookZPlants_MushroomPizza_DS";
    };
    class CookZPlants_MushroomPizza_Opened: CookZ_PizzaOpened_Base
    {
        scope=2;
        displayName="$STR_CookZPlants_MushroomPizza_DN";
        descriptionShort="$STR_CookZPlants_MushroomPizza_Opened_DS";
        hiddenSelectionsTextures[]+=
        {
            "CookZPlants\data\dishes\pizza\pizza_mushroom_topping_co.paa"
        };
        varQuantityInit=1170;
        varQuantityMax=1170;
        class Nutrition
        {
            energy=287.179;
            water=102.564;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
};