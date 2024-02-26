class ActionHackedCrateOpenClose: ActionInteractBase
{
	void ActionCrateOpenClose()
	{
		m_CommandUID = DayZPlayerConstants.CMD_ACTIONMOD_OPENDOORFW;
		m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
	}

	override void CreateConditionComponents()  
	{
		m_ConditionItem = new CCINone;
		m_ConditionTarget = new CCTNone;
	}

    override string GetText()
	{
		return "Start Hacking";
	}

	override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if( !target ) return false;

		// string selection = target.GetObject().GetActionComponentName(target.GetComponentIndex());

		SpawnableCase_Hackable_Base crate = SpawnableCase_Hackable_Base.Cast(target.GetObject());

		if (crate)
		{
			Print("ActionHackedCrateOpenClose ActionCondition " + crate.IsHacked() + " " + crate.BeingHacked());

			if (!crate.IsHacked() && !crate.BeingHacked())
				return true;
		}
		return false;
	}
};