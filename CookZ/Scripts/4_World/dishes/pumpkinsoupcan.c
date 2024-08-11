class CookZ_PumpkinSoupCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_PumpkinSoupCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
