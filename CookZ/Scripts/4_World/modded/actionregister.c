modded class ActionConstructor
{
	override void RegisterActions(TTypenameArray actions)
	{
		super.RegisterActions(actions);
		actions.Insert(CookZ_ActionReadBook);
	}
};

class CookZ_ActionReadBook extends ActionSingleUseBase
{
	void CookZ_ActionReadBook()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_DROPITEM_HANDS;
		m_FullBody = false;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT | DayZPlayerConstants.STANCEMASK_PRONE;
	}

	override void CreateConditionComponents()
	{
		m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTNone;
	}

	override bool HasTarget()
	{
		return false;
	}

	override string GetText()
	{
		return "#read";
	}

	override void OnExecuteClient( ActionData action_data )
	{
		action_data.m_Player.ToggleCookbookReading();
	}

	override void OnExecuteServer( ActionData action_data )
	{
		if (!GetGame().IsMultiplayer())
			action_data.m_Player.ToggleCookbookReading();
	}
};