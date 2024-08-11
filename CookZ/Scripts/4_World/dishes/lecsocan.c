class CookZ_LecsoCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("CookZ_LecsoCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
