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
			// const int MENU_BOOK = 23; use menu book id plus prefix
			CookbookMenu cookbookMenu = CookbookMenu.Cast( GetUIManager().EnterScriptedMenu(133723, NULL) );
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
