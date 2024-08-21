class CookZ_Cookbook_Item extends ItemBase
{
	override void SetActions()
	{
		super.SetActions();

		AddAction(CookZ_ActionReadBook);
	}
}
