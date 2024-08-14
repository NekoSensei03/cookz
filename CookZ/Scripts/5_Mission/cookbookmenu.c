class CookbookMenu extends BookMenu
{
	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("CookZ/gui/layouts/cookbook.layout");
		Class.CastTo(m_content, layoutRoot.FindAnyWidget("HtmlWidget"));
		Class.CastTo(m_author, layoutRoot.FindAnyWidget("Author")); 
		Class.CastTo(m_title, layoutRoot.FindAnyWidget("Title"));
		Class.CastTo(m_page, layoutRoot.FindAnyWidget("Page"));

		float width;
		m_content.GetScreenSize(width, m_page_height);

		return layoutRoot;
	}

	override void OnHide()
	{
		super.OnHide();
		MissionGameplay gamePlay = MissionGameplay.Cast( GetGame().GetMission() );
		gamePlay.RemoveActiveInputExcludes({"inventory"});
		gamePlay.RemoveActiveInputRestriction(EInputRestrictors.INVENTORY);
	}
}
