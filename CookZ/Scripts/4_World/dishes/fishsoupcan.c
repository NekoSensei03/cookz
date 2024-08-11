class CookZ_FishSoupCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_FishSoupCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
