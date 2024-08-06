class GoulashCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("GoulashCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
