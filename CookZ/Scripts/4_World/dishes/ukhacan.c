class CookZ_UkhaCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_UkhaCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
