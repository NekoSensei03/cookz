class CookZ_FriedPotatoesBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_FriedPotatoesBox_Opened");
    }
}

class CookZ_StirFryBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_StirFryBox_Opened");
    }
}

class CookZ_FishAndChipsBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_FishAndChipsBox_Opened");
    }
}

class CookZ_RicePuddingBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_RicePuddingBox_Opened");
    }
}

class CookZ_MushroomRisottoBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_MushroomRisottoBox_Opened");
    }
}

class CookZ_Box_Base: Edible_Base
{
    override bool IsOpen()
    {
        return false;
    }

    override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionOpen);
	}
}
