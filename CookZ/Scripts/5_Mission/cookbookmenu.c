class CookbookMenu extends UIScriptedMenu
{
	protected float m_page_height;
	protected ref array<string> m_content;
	protected ref array<int> m_page_to_content;
	protected ref array<float> m_page_to_position;

	protected int m_current_page;
	
	protected TextWidget m_author;
	protected TextWidget m_title;
	
	protected TextWidget m_page_left;
	protected HtmlWidget m_content_left;
	
	protected TextWidget m_page_right;
	protected HtmlWidget m_content_right;

	override Widget Init()
	{
		layoutRoot = GetGame().GetWorkspace().CreateWidgets("CookZ/gui/layouts/cookbook.layout");
		Class.CastTo(m_content_left, layoutRoot.FindAnyWidget("HtmlWidgetLeft"));
		Class.CastTo(m_content_right, layoutRoot.FindAnyWidget("HtmlWidgetRight"));
		Class.CastTo(m_author, layoutRoot.FindAnyWidget("Author")); 
		Class.CastTo(m_title, layoutRoot.FindAnyWidget("Title"));
		Class.CastTo(m_page_left, layoutRoot.FindAnyWidget("PageLeft"));
		Class.CastTo(m_page_right, layoutRoot.FindAnyWidget("PageRight"));

		float width;
		m_content_left.GetScreenSize(width, m_page_height);

		return layoutRoot;
	}

	override void OnHide()
	{
		super.OnHide();
		MissionGameplay gamePlay = MissionGameplay.Cast( GetGame().GetMission() );
		gamePlay.RemoveActiveInputExcludes({"inventory"});
		gamePlay.RemoveActiveInputRestriction(EInputRestrictors.INVENTORY);
	}

	void ReadBook(InventoryItem book)
	{
		array<string> chapters = new array<string>;
		book.ConfigGetTextArray("chapters", chapters);

		m_content = new array<string>;
		m_page_to_content = new array<int>;
		m_page_to_position = new array<float>;

		int pageCounter = 0;
		for (int i = 0;i < chapters.Count(); i++)
		{
			string chapterContent = "";
			LoadFile(chapters[i], chapterContent);
			m_content.Insert(chapterContent);

			m_content_left.SetText(m_content[i]);
			float contentHeight = m_content_left.GetContentHeight();
			
			int numPagesForChapter = Math.Ceil(contentHeight / m_page_height);
			for (int j = 0;j < numPagesForChapter;j++)
			{
				m_page_to_content.Insert(i);
				m_page_to_position.Insert(j * m_page_height)
				pageCounter++;
			}
		}

		m_current_page = 0;
		UpdatePage();

		m_author.SetText( book.ConfigGetString("author") );
		m_title.SetText( book.ConfigGetString("title") );
	}

	bool LoadFile(string file, out string content)
	{
		FileHandle file_index = OpenFile(file, FileMode.READ);
		
		if ( file_index == 0 )
		{
			return false;
		}
		
		string line_content = "";
		int char_count = FGets( file_index,  line_content );
		while ( char_count != -1 )
		{
			content = content + line_content;
			
			char_count = FGets( file_index,  line_content );
		}
		
		CloseFile(file_index);
		
		return true;
	}

	override bool OnClick(Widget w, int x, int y, int button)
	{
		super.OnClick(w, x, y, button);

		switch (w.GetUserID())
		{
			case IDC_BOOK_VIEWER_PREV:
				PrevPage();
				return true;
			case IDC_BOOK_VIEWER_NEXT:
				NextPage();
				return true;
			case IDC_CANCEL:
				Close();
				return true;
		}

		return false;
	}

	void NextPage()
	{
		if (m_current_page < m_page_to_position.Count() - 2)
		{
			m_current_page = m_current_page + 2;
			UpdatePage();
		}
	}

	void PrevPage()
	{
		if (m_current_page > 1)
		{
			m_current_page = m_current_page - 2;
			UpdatePage();
		}
	}

	void UpdatePage()
	{
		m_content_left.SetText(m_content[m_page_to_content[m_current_page]]);
		m_content_left.SetContentOffset(m_page_to_position[m_current_page], true);

		if (m_current_page + 1 < m_page_to_position.Count())
		{
			m_content_right.SetText(m_content[m_page_to_content[m_current_page + 1]]);
			m_content_right.SetContentOffset(m_page_to_position[m_current_page + 1], true);
		}
		else
		{
			m_content_right.SetText("");
			m_content_right.SetContentOffset(0, true);
		}

		m_page_left.SetText((m_current_page + 1).ToString());
		m_page_right.SetText((m_current_page + 2).ToString());
	}
}
