class CfgPatches
{
    class CookZ {};
};

class CfgVehicles
{
    // imports

    class SpaghettiCan;
    class SpaghettiCan_Opened;

    // bases

    // items

    class CookZ_GoulashCan: SpaghettiCan
    {
        scope=2;
        displayName="Goulash";
        descriptionShort="A nutritious and long-lasting can of goulash that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_goulash_co.paa"
        };
    };
    class CookZ_GoulashCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Goulash";
        descriptionShort="A nutritious can of goulash. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_goulash_co.paa"
        };
        varQuantityInit=800;
        varQuantityMax=800;
        class Nutrition
        {
            energy=215.625;
            water=89.9375;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_PumpkinSoupCan: SpaghettiCan
    {
        scope=2;
        displayName="Pumpkin Soup";
        descriptionShort="A nutritious and long-lasting can of pumpkin soup that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_pumpkin_soup_co.paa"
        };
    };
    class CookZ_PumpkinSoupCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Pumpkin Soup";
        descriptionShort="A nutritious can of pumpkin soup. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_pumpkin_soup_co.paa"
        };
        varQuantityInit=500
        varQuantityMax=500
        class Nutrition
        {
            energy=125;
            water=112;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_FishSoupCan: SpaghettiCan
    {
        scope=2;
        displayName="Fish Soup";
        descriptionShort="A nutritious and long-lasting can of fish soup that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_fish_soup_co.paa"
        };
    };
    class CookZ_FishSoupCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Fish Soup";
        descriptionShort="A nutritious can of fish soup. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_fish_soup_co.paa"
        };
        varQuantityInit=1300
        varQuantityMax=1300
        class Nutrition
        {
            energy=140.385;
            water=89.2308;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

	class CookZ_UkhaCan: SpaghettiCan
    {
        scope=2;
        displayName="Ukha";
        descriptionShort="A nutritious and long-lasting can of Ukha that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_ukha_co.paa"
        };
    };
    class CookZ_UkhaCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Ukha";
        descriptionShort="A nutritious can of Ukha. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_ukha_co.paa"
        };
        varQuantityInit=1500
        varQuantityMax=1500
        class Nutrition
        {
            energy=148.333;
            water=77.3333;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_LecsoCan: SpaghettiCan
    {
        scope=2;
        displayName="Lecso";
        descriptionShort="A nutritious and long-lasting can of Lecso that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_lecso_co.paa"
        };
    };
    class CookZ_LecsoCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Lecso";
        descriptionShort="A nutritious can of Lecso. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_lecso_co.paa"
        };
        varQuantityInit=700
        varQuantityMax=700
        class Nutrition
        {
            energy=192.857;
            water=125.571;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_MysteryMeatCan: SpaghettiCan
    {
        scope=2;
        displayName="Mystery Meat";
        descriptionShort="A nutritious and long-lasting can of mixed meats that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_mystery_meat_co.paa"
        };
    };
    class CookZ_MysteryMeatCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Mystery Meat";
        descriptionShort="A nutritious can of mixed meats. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_mystery_meat_co.paa"
        };
        varQuantityInit=950
        varQuantityMax=950
        class Nutrition
        {
            energy=300;
            water=25.2632;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_ZucchiniCaviarCan: SpaghettiCan
    {
        scope=2;
        displayName="Zucchini Caviar";
        descriptionShort="A nutritious and long-lasting can of zucchini caviar that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_zucchini_caviar_co.paa"
        };
    };
    class CookZ_ZucchiniCaviarCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Zucchini Caviar";
        descriptionShort="A nutritious can of zucchini caviar. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_zucchini_caviar_co.paa"
        };
        varQuantityInit=850
        varQuantityMax=850
        class Nutrition
        {
            energy=191.176;
            water=94.0588;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_CreamyTomatoSoupCan: SpaghettiCan
    {
        scope=2;
        displayName="Creamy Tomato Soup";
        descriptionShort="A nutritious and long-lasting can of creamy tomato soup that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_creamy_tomato_soup_co.paa"
        };
    };
    class CookZ_CreamyTomatoSoupCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Creamy Tomato Soup";
        descriptionShort="A nutritious can of creamy tomato soup. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_creamy_tomato_soup_co.paa"
        };
        varQuantityInit=800
        varQuantityMax=800
        class Nutrition
        {
            energy=218.75;
            water=122.5;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_MushroomStroganoffCan: SpaghettiCan
    {
        scope=2;
        displayName="Mushroom Stroganoff";
        descriptionShort="A nutritious and long-lasting can of mushroom stroganoff that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_mushroom_stroganoff_co.paa"
        };
    };
    class CookZ_MushroomStroganoffCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Mushroom Stroganoff";
        descriptionShort="A nutritious can of mushroom stroganoff. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_mushroom_stroganoff_co.paa"
        };
        varQuantityInit=950
        varQuantityMax=950
        class Nutrition
        {
            energy=302.632;
            water=178.947;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_BeefStewCan: SpaghettiCan
    {
        scope=2;
        displayName="Beef Stew";
        descriptionShort="A nutritious and long-lasting can of beef stew that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_beef_stew_co.paa"
        };
    };
    class CookZ_BeefStewCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Beef Stew";
        descriptionShort="A nutritious can of beef stew. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_beef_stew_co.paa"
        };
        varQuantityInit=1050
        varQuantityMax=1050
        class Nutrition
        {
            energy=209.524;
            water=93.2857;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_BoneBrothCan: SpaghettiCan
    {
        scope=2;
        displayName="Bone Broth";
        descriptionShort="A nutritious and long-lasting can of bone broth that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_bone_broth_co.paa"
        };
    };
    class CookZ_BoneBrothCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Bone Broth";
        descriptionShort="A nutritious can of bone broth. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_bone_broth_co.paa"
        };
        varQuantityInit=800
        varQuantityMax=800
        class Nutrition
        {
            energy=150;
            water=70;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_AppleMarmaladeCan: SpaghettiCan
    {
        scope=2;
        displayName="Apple Marmalade";
        descriptionShort="A nutritious and long-lasting can of apple marmalade that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_apple_marmalade_co.paa"
        };
    };
    class CookZ_AppleMarmaladeCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Apple Marmalade";
        descriptionShort="A nutritious can of apple marmalade. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_apple_marmalade_co.paa"
        };
        varQuantityInit=750
        varQuantityMax=750
        class Nutrition
        {
            energy=250;
            water=24;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_PlumMarmaladeCan: SpaghettiCan
    {
        scope=2;
        displayName="Plum Marmalade";
        descriptionShort="A nutritious and long-lasting can of plum marmalade that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_plum_marmalade_co.paa"
        };
    };
    class CookZ_PlumMarmaladeCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Plum Marmalade";
        descriptionShort="A nutritious can of plum marmalade. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_plum_marmalade_co.paa"
        };
        varQuantityInit=450
        varQuantityMax=450
        class Nutrition
        {
            energy=300;
            water=32;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };

    class CookZ_PearMarmaladeCan: SpaghettiCan
    {
        scope=2;
        displayName="Pear Marmalade";
        descriptionShort="A nutritious and long-lasting can of pear marmalade that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_pear_marmalade_co.paa"
        };
    };
    class CookZ_PearMarmaladeCan_Opened: SpaghettiCan_Opened
    {
        scope=2;
        displayName="Pear Marmalade";
        descriptionShort="A nutritious can of pear marmalade. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\dishes\canned\canned_pear_marmalade_co.paa"
        };
        varQuantityInit=600
        varQuantityMax=600
        class Nutrition
        {
            energy=300;
            water=16;
            fullnessIndex=3;
            nutritionalIndex=1;
            toxicity=0;
        };
    };
}