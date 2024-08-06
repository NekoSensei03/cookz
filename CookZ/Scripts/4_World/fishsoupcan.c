class FishSoupCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("FishSoupCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
