class FishAndChipsCan : Edible_Base
{
	override void Open()
	{
		ReplaceEdibleWithNew("FishAndChipsCan_Opened");
	}
	
	override bool IsOpen()
	{
		return false;
	}
}
