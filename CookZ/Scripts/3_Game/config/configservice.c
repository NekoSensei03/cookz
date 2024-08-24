class CookZ_Config
{
	bool CanCraftCookBook;
    bool CanCraftEmptyCans;
    bool CanCraftEmptyBoxes;
};

class CookZ_ConfigService
{
    static void LoadConfig(string configName, out CookZ_Config config)
    {
        string configPath = COOKZ_CONFIG_ROOT + configName;
		
        if (!FileExist(configPath))
        {
            CreateDefaultConfig(config);
            if (!FileExist(COOKZ_CONFIG_ROOT))
            {
                MakeDirectory(COOKZ_CONFIG_ROOT);
            }

            JsonFileLoader<CookZ_Config>.JsonSaveFile(configPath, config);
            return;
        }

        JsonFileLoader<CookZ_Config>.JsonLoadFile(configPath, config);
    }

    protected static void CreateDefaultConfig(out CookZ_Config config)
    {
        config = new CookZ_Config();
		
		config.CanCraftCookBook = true;
		config.CanCraftEmptyCans = true;
		config.CanCraftEmptyBoxes = true;
    }
};

modded class DayZGame
{    
    protected ref CookZ_Config m_CookZ_Config;
    
    void SetCookZ_Config(CookZ_Config config)
    {
        m_CookZ_Config = config;
    }

    CookZ_Config GetCookZ_Config()
    {
        return m_CookZ_Config;
    }
};