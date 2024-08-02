class FriedPotatoesCan : Edible_Base
{
	override void Open()
	{
		ReplaceEdibleWithNew("FriedPotatoesCan_Opened");
	}
	
	override bool IsOpen()
	{
		return false;
	}
}
