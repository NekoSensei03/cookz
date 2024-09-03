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
            MakeDirectory(COOKZ_CONFIG_ROOT);

            string saveErrorMessage;
            if (!JsonFileLoader<CookZ_Config>.SaveFile(configPath, config, saveErrorMessage))
            {
                Print(string.Format("[CookZ] Error generating configuration: %1", saveErrorMessage));
            }
            else
            {
                Print("[CookZ] Successfully generated configuration.");
            }
            return;
        }

        string loadErrorMessage;
        if (!JsonFileLoader<CookZ_Config>.LoadFile(configPath, config, loadErrorMessage))
        {
            Print(string.Format("[CookZ] Error loading configuration: %1", loadErrorMessage));
        }
        else
        {
            Print("[CookZ] Successfully loaded configuration.");
        }
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