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
    };

    class CookZ_CreamyTomatoSoupCan: SpaghettiCan
    {
        displayName="Creamy Tomato Soup";
        descriptionShort="A nutritious and long-lasting can of creamy tomato soup that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_creamy_tomato_soup_co.paa"
        };
    };
    class CookZ_CreamyTomatoSoupCan_Opened: SpaghettiCan_Opened
    {
        displayName="Creamy Tomato Soup";
        descriptionShort="A nutritious can of creamy tomato soup. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_creamy_tomato_soup_co.paa"
        };
        varQuantityInit=800
        varQuantityMax=800
    };

    class CookZ_MushroomStroganoffCan: SpaghettiCan
    {
        displayName="Mushroom Stroganoff";
        descriptionShort="A nutritious and long-lasting can of mushroom stroganoff that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_mushroom_stroganoff_co.paa"
        };
    };
    class CookZ_MushroomStroganoffCan_Opened: SpaghettiCan_Opened
    {
        displayName="Mushroom Stroganoff";
        descriptionShort="A nutritious can of mushroom stroganoff. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_mushroom_stroganoff_co.paa"
        };
        varQuantityInit=950
        varQuantityMax=950
    };

    class CookZ_BeefStewCan: SpaghettiCan
    {
        displayName="Beef Stew";
        descriptionShort="A nutritious and long-lasting can of beef stew that can be opened with a can opener. Will last two to five years depending on storage conditions.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_beef_stew_co.paa"
        };
    };
    class CookZ_BeefStewCan_Opened: SpaghettiCan_Opened
    {
        displayName="Beef Stew";
        descriptionShort="A nutritious can of beef stew. Eat up before it spoils.";
        hiddenSelectionsTextures[]=
        {
            "CookZ\data\canned_beef_stew_co.paa"
        };
        varQuantityInit=1050
        varQuantityMax=1050
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
    };
}