modded class ModItemRegisterCallbacks
{
    override void RegisterOneHanded(DayZPlayerType pType, DayzPlayerItemBehaviorCfg pBehavior)
    {
        super.RegisterOneHanded (pType, pBehavior);
        pType.AddItemInHandsProfileIK("CookZ_EmptyBox",			"dz/anims/workspaces/player/player_main/player_main_1h.asi",	pBehavior,	"dz/anims/anm/player/ik/gear/pepper_green_fresh.anm");
        pType.AddItemInHandsProfileIK("CookZ_Box_Base",			"dz/anims/workspaces/player/player_main/player_main_1h.asi",	pBehavior,	"dz/anims/anm/player/ik/gear/pepper_green_fresh.anm");
        pType.AddItemInHandsProfileIK("CookZ_BoxOpened_Base",	"dz/anims/workspaces/player/player_main/player_main_1h.asi",	pBehavior,	"dz/anims/anm/player/ik/gear/pepper_green_fresh.anm");
        
        pType.AddItemInHandsProfileIK("CookZ_Cookbook_Item",	"dz/anims/workspaces/player/player_main/player_main_1h.asi",	pBehavior,	"dz/anims/anm/player/ik/gear/book.anm");
   	};
};
