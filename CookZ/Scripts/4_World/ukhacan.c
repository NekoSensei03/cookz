class UkhaCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("UkhaCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
