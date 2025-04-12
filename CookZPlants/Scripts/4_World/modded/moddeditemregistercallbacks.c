modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded (pType, pBehavior);
        pType.AddItemInHandsProfileIK("CookZPlants_WheatSeedsPack",   "dz/anims/workspaces/player/player_main/player_main_1h.asi",  pBehavior,  "dz/anims/anm/player/ik/gear/zucchini_seeds_pack.anm");
        pType.AddItemInHandsProfileIK("CookZPlants_WheatEars",        "dz/anims/workspaces/player/player_main/player_main_1h.asi",  pBehavior,  "dz/anims/anm/player/ik/gear/hammer_ik.anm");
        pType.AddItemInHandsProfileIK("CookZPlants_MortarAndPestle",  "dz/anims/workspaces/player/player_main/player_main_1h.asi",  pBehavior,  "dz/anims/anm/player/ik/gear/zucchini_seeds_pack.anm");
        pType.AddItemInHandsProfileIK("CookZPlants_FlourBag",         "dz/anims/workspaces/player/player_main/player_main_1h.asi",  pBehavior,  "dz/anims/anm/player/ik/gear/lard.anm");
        pType.AddItemInHandsProfileIK("CookZPlants_Dough",            "dz/anims/workspaces/player/player_main/player_main_1h.asi",  pBehavior,  "dz/anims/anm/player/ik/gear/apple.anm");
   };

   override void RegisterTwoHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
   {
        pType.AddItemInHandsProfileIK("CookZ_Pizza_Base",             "dz/anims/workspaces/player/player_main/player_main_2h.asi",  pBehavior,  "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
        pType.AddItemInHandsProfileIK("CookZ_PizzaOpened_Base",       "dz/anims/workspaces/player/player_main/player_main_2h.asi",  pBehavior,  "dz/anims/anm/player/ik/two_handed/BatteryCar.anm");
   };
};
