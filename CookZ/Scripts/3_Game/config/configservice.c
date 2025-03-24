class CookZ_Config
{
	bool CanCraftCookBook;
    bool CanCraftEmptyCans;
    bool CanCraftEmptyBoxes;
    int MinIngredientQuantityPercent;
    float TemperaturOfCreatedDish;
    float ChanceToRemoveBrainAgent;
    float ChanceToRemoveHeavyMetalAgent;
    float ChanceToRemoveSalmonellaAgent;
    bool EnableCheeseDecay;
    bool EnableSausageDecay;
    bool EnableBoxAndCanDecay;
    bool InstantCook;
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
        config.MinIngredientQuantityPercent = 50;
        config.TemperaturOfCreatedDish = 80.0;
        config.ChanceToRemoveBrainAgent = 1.0;
        config.ChanceToRemoveHeavyMetalAgent = 1.0;
        config.ChanceToRemoveSalmonellaAgent = 1.0;
        config.EnableCheeseDecay = false;
        config.EnableSausageDecay = false;
        config.EnableBoxAndCanDecay = true;
        config.InstantCook = false;
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