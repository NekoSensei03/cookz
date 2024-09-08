class CookZ_Box_Base: CookZ_ClosedDish
{
    override void SetActions()
	{
		super.SetActions();
		AddAction(ActionOpen);
	}
}

class CookZ_FriedPotatoesBox : CookZ_Box_Base {}
class CookZ_StirFryBox : CookZ_Box_Base {}
class CookZ_FishAndChipsBox : CookZ_Box_Base {}
class CookZ_RicePuddingBox : CookZ_Box_Base {}
class CookZ_MushroomRisottoBox : CookZ_Box_Base {}
class CookZ_PilafBox : CookZ_Box_Base {}
class CookZ_StuffedPeppersBox : CookZ_Box_Base {}
class CookZ_GaghBox : CookZ_Box_Base {}
class CookZ_HaggisBox : CookZ_Box_Base {}
class CookZ_PommdoenerBox : CookZ_Box_Base {}
class CookZ_BangersAndMashBox : CookZ_Box_Base {}
class CookZ_CurrywurstBox : CookZ_Box_Base {}

class CookZ_FriedPotatoesBox_Opened : CookZ_OpenedDish {}
class CookZ_StirFryBox_Opened : CookZ_OpenedDish {}
class CookZ_FishAndChipsBox_Opened : CookZ_OpenedDish {}
class CookZ_RicePuddingBox_Opened : CookZ_OpenedDish {}
class CookZ_MushroomRisottoBox_Opened : CookZ_OpenedDish {}
class CookZ_PilafBox_Opened : CookZ_OpenedDish {}
class CookZ_StuffedPeppersBox_Opened : CookZ_OpenedDish {}
class CookZ_GaghBox_Opened : CookZ_OpenedDish {}
class CookZ_HaggisBox_Opened : CookZ_OpenedDish {}
class CookZ_PommdoenerBox_Opened : CookZ_OpenedDish {}
class CookZ_BangersAndMashBox_Opened : CookZ_OpenedDish {}
class CookZ_CurrywurstBox_Opened : CookZ_OpenedDish {}
