class PumpkinSoupCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("PumpkinSoupCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
