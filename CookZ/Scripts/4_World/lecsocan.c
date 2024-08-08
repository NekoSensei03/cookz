class LecsoCan : Edible_Base
{
    override void Open()
    {
        ReplaceEdibleWithNew("LecsoCan_Opened");
    }
    
    override bool IsOpen()
    {
        return false;
    }
}
