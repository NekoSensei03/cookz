modded class MissionGameplay
{
	override void OnUpdate(float timeslice)
	{
		super.OnUpdate(timeslice);

		PlayerBase pBase = PlayerBase.Cast(GetGame().GetPlayer());
		if (pBase && pBase.IsReadingCookbook())
		{
			pBase.ToggleCookbookReading();
			InventoryItem book = pBase.GetItemInHands();
			BookMenu bookMenu = BookMenu.Cast( GetUIManager().EnterScriptedMenu(MENU_BOOK, NULL) );
			if (bookMenu)
			{
				AddActiveInputExcludes({"inventory"});
				AddActiveInputRestriction(EInputRestrictors.INVENTORY);
				bookMenu.ReadBook(book);
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
				BookMenu bookMenu = BookMenu.Cast(menu);
				if (bookMenu)
				{
					bookMenu.Close();
				}
			}
		}
	}
};
