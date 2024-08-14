modded class PlayerBase
{
	protected bool isReadingCookbook;

	override void Init()
	{
		super.Init();
		isReadingCookbook = false;
	}

	void ToggleCookbookReading()
	{
		isReadingCookbook = !isReadingCookbook;
	}

	bool IsReadingCookbook()
	{
		return isReadingCookbook;
	}
}
