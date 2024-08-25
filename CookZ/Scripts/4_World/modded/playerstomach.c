modded class PlayerStomach
{
    // override here as methods to actually fetch the nurition profile are all static
    override void AddToStomach(string class_name, float amount, int food_stage = 0, int agents = 0)
    {
        NutritionalProfile profile = CookZ_GetCookbook().GetNutritionalProfile(class_name);
        if (!profile)
        {
            super.AddToStomach(class_name, amount, food_stage, agents);
            return;
        }

        // sanity checks start
        if(amount > ACCEPTABLE_QUANTITY_MAX || amount < 0)
        {
            amount = 0;
        }
        if (food_stage < 0 || food_stage > ACCEPTABLE_FOODSTAGE_MAX)
        {
            food_stage = FoodStageType.RAW;
        }
        // sanity checks end
        
        agents = agents | profile.GetAgents();
        bool found = false;
        for(int i = 0; i < m_StomachContents.Count(); i++)
        {
            StomachItem stomach_item = m_StomachContents.Get(i);
            if(stomach_item.GetClassName() == class_name )
            {
                if (stomach_item.GetFoodStage() == food_stage)
                {
                    stomach_item.AddAmount(amount);
                    stomach_item.AddAgents(agents);
                    found = true;
                }
            }
        }
        
        if(!found)
        {
            m_StomachContents.Insert(new StomachItem(class_name, amount, profile, food_stage, agents));
        }
    }
}