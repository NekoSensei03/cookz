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
            // const int MENU_BOOK = 23;  use menu book id plus prefix
            case 133723:
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