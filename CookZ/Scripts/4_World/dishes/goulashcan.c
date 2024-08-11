class CookZ_GoulashCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_GoulashCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
