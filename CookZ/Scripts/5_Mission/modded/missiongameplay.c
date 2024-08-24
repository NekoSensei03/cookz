modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		PlayerBase pBase = PlayerBase.Cast(GetGame().GetPlayer());
		if (pBase && pBase.IsReadingCookbook())
		{
			pBase.ToggleCookbookReading();
			CookZ_Cookbook_Item cookbook = CookZ_Cookbook_Item.Cast(pBase.GetItemInHands());
			CookbookMenu cookbookMenu = CookbookMenu.Cast( GetUIManager().EnterScriptedMenu(COOKZ_COOKBOOK_MENU, NULL) );
			if (cookbook && cookbookMenu)
			{
				AddActiveInputExcludes({"inventory"});
				AddActiveInputRestriction(EInputRestrictors.INVENTORY);
				cookbookMenu.ReadBook(cookbook);
			}
		}
	}

	override void OnKeyPress(int key)
	{
		super.OnKeyPress(key);

		if (key == KeyCode.KC_ESCAPE)
		{
			UIScriptedMenu menu = m_UIManager.GetMenu();
			if (menu)
			{
				CookbookMenu cookbookMenu = CookbookMenu.Cast(menu);
				if (cookbookMenu)
				{
					cookbookMenu.Close();
				}
			}
		}
	}
};
