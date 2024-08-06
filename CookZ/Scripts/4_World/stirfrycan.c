class StirFryCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("StirFryCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
