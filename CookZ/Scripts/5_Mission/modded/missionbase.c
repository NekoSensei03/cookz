modded class MissionBase
{
    override UIScriptedMenu CreateScriptedMenu(int id)
	{
        UIScriptedMenu menu = super.CreateScriptedMenu(id);
        if (menu)
        {
            return menu;
        }

        switch (id)
        {
            case COOKZ_COOKBOOK_MENU:
                menu = new CookbookMenu;
                break;
        }
        if (menu)
        {
            menu.SetID(id);
        }

        return menu;
    }
}