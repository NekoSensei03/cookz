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

	override void OnRPC(PlayerIdentity sender, int rpc_type, ParamsReadContext ctx)
    {
        super.OnRPC(sender, rpc_type, ctx);

        switch (rpc_type)
        {
            case COOKZ_CHECK_CONFIG:
            {
                Param1<CookZ_Config> configParams;
                if (!ctx.Read(configParams))
				{
					return;
				}

                GetDayZGame().SetCookZ_Config(configParams.param1);
                break;
            }
        }
    }
}
