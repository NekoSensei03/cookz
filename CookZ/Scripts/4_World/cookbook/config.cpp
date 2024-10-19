class CfgPatches
{
    class CookZ {};
};

class CfgVehicles
{
    class CookZ_Recipes
    {
		// add a recipes here

        class CookZ_FriedPotatoesBox 	// name needs to be name of dish to be created
        {
            allowPot = false;			// can pot be used for recipe?
            allowCauldron = false;		// can cauldron be used for recipe?
            allowPan = true;			// can pan be used for recipe?
            needsWater = false;			// is water needed? only makes sense if pot or cauldron is allowed
            needsEmptyCan = false;      // is an empty can needed
            needsEmptyBox = true;       // is an empty box needed
            doNotReplaceIngredients = false; // do not replace ingredients by dish (e.g. disenfecting rags)
            canBeOpened = true;         // does dish need to be opened before eating
            numDishes = 1;              // number of dishes that will be created
            ingredients[] = {
				"Potato,4",				// <NAME>,<QUANITY>, name must be the food item name OR AnyMeat etc
                "Lard,1"
            };
        };
        class CookZ_StirFryBox
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
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
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
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
            needsWater = true;
            needsEmptyBox = true;
            canBeOpened = true;
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
            needsWater = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "Rice,1",
                "AnyMushroom,2"
            };
        };
        class CookZ_StuffedPeppersBox
        {
            allowPot = true;
            allowCauldron = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "GreenBellPepper,3",
                "AnyMeat,2"
            };
        };
        class CookZ_PilafBox
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "Rice,1",
                "GreenBellPepper,2",
                "Tomato,2"
            };
        };
        // class CookZ_GaghBox
        // {
        //     allowPot = true;
        //     allowCauldron = true;
        //     needsWater = true;
        //     needsEmptyBox = true;
        //     canBeOpened = true;
        //     ingredients[] = {
        //         "Worm,8"
        //     };
        // };
        class CookZ_HaggisBox
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "Guts,1",
                "Potato,2"
            };
        };
        class CookZ_PommdoenerBox
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "CowSteakMeat,1",
                "Lard,1",
                "Potato,2"
            };
        };
        class CookZ_GoulashCan
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
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
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "SlicedPumpkin,2"
            };
        };
        class CookZ_FishSoupCan
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
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
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
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
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
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
            needsEmptyCan = true;
            canBeOpened = true;
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
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "AnyMeat,3",
                "Lard,1"
            };
        }
        class CookZ_ZucchiniCaviarCan
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "Zucchini,3",
                "GreenBellPepper,1",
                "Tomato,1"
            };
        }
        class CookZ_CreamyTomatoSoupCan
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "Tomato,6",
                "PowderedMilk,1"
            };
        }
        class CookZ_BeefStewCan
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "CowSteakMeat,1",
                "GreenBellPepper,1",
                "Potato,1",
                "Tomato,2"
            };
        }
        class CookZ_MushroomStroganoffCan
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "PowderedMilk,1",
                "AnyMushroom,5"
            };
        }
        class CookZ_AppleMarmaladeCan
        {
            allowPot = true;
            allowCauldron = true;
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "Apple,6"
            };
        };
        class CookZ_PlumMarmaladeCan
        {
            allowPot = true;
            allowCauldron = true;
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "Plum,6"
            };
        };
        class CookZ_PearMarmaladeCan
        {
            allowPot = true;
            allowCauldron = true;
            needsEmptyCan = true;
            canBeOpened = true;
            ingredients[] = {
                "Pear,4"
            };
        };
        class CookZ_Beef_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "CowSteakMeat,1"
            };
        };
        class CookZ_Chicken_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "ChickenBreastMeat,3"
            };
        };
        class CookZ_Pig_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "PigSteakMeat,2"
            };
        };
        class CookZ_Goat_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "GoatSteakMeat,2"
            };
        };
        class CookZ_Bear_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "BearSteakMeat,1"
            };
        };
        class CookZ_Sheep_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "SheepSteakMeat,2"
            };
        };
        class CookZ_Boar_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "BoarSteakMeat,2"
            };
        };
        class CookZ_Deer_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "DeerSteakMeat,2"
            };
        };
        class CookZ_Hare_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "RabbitLegMeat,2"
            };
        };
        class CookZ_Wolf_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "WolfSteakMeat,2"
            };
        };
        class CookZ_Human_Sausage
        {
            allowPot = true;
            allowCauldron = true;
            numDishes = 2;
            ingredients[] = {
                "Guts,1",
                "HumanSteakMeat,2"
            };
        };
        class CookZ_DisinfectRags
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            doNotReplaceIngredients = true;
            ingredients[] = {
                "AnyDisinfect,-1"    // -1 any number of rag, bandage, ... > 0
            };
        };
        class CookZ_BangersAndMashBox
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "AnySausage,1",
                "Potato,2"
            };
        };
        class CookZ_CurrywurstBox
        {
            allowpan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "AnySausage,1",
                "Lard,1",
                "Potato,1",
                "Tomato,1"
            };
        };
        class CookZ_Cheese
        {
            allowPot = true;
            allowCauldron = true;
            needsWater = true;
            numDishes = 4;
            ingredients[] = {
                "Lard,2",
                "PowderedMilk,2"
            };
        };
        class CookZ_StuffedMushroomsBox
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "AnyMushroom,4",
                "CookZ_Cheese,1"
            };
        };
        class CookZ_RabbitRoastBox
        {
            allowPot = true;
            allowCauldron = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "RabbitLegMeat,2",
                "GreenBellPepper,2",
                "Tomato,3"
            };
        };
        class CookZ_NuggiesAndFriesBox
        {
            allowPan = true;
            needsEmptyBox = true;
            canBeOpened = true;
            ingredients[] = {
                "ChickenBreastMeat,2",
                "Potato,2",
                "Lard,1"
            };
        };
    }
}