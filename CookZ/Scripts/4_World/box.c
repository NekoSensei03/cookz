class FriedPotatoesBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("FriedPotatoesBox_Opened");
    }
}

class StirFryBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("StirFryBox_Opened");
    }
}

class FishAndChipsBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("FishAndChipsBox_Opened");
    }
}

class RicePuddingBox : CookZ_Box_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("RicePuddingBox_Opened");
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
