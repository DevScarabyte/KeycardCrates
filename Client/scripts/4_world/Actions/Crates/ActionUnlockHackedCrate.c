class ActionUnlockHackedCrateCB : ActionContinuousBaseCB
{
	override void CreateActionComponent()
    {
        m_ActionData.m_ActionComponent = new CAContinuousTime(UATimeSpent.LOCK);
    }
}

class ActionUnlockHackedCrate : ActionContinuousBase
{
    void ActionUnlockHackedCrate()
    {
        m_CallbackClass = ActionUnlockHackedCrateCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
		m_FullBody = true;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_CROUCH | DayZPlayerConstants.STANCEMASK_ERECT;
		m_SpecialtyWeight = UASoftSkillsWeight.PRECISE_HIGH;
    }

    override void CreateConditionComponents()
    {
       	m_ConditionItem = new CCINonRuined;
		m_ConditionTarget = new CCTCursor(UAMaxDistances.DEFAULT);
    }

    override string GetText()
    {
        return "Start Hacking Crate";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item)
    {
		if(!target)
			return false;
		if (!target.GetObject())
			return false;
		SpawnableCase_Hackable_Base crate = SpawnableCase_Hackable_Base.Cast(target.GetObject());

        if(crate)
		{
            // lets make sure its ready
            //crate.ConvertKeyItem();
            if (Math.AbsInt(item.GetType().Hash()) != crate.GetKeyItem())
                return false;
            if (crate.IsHacked())
                return true;
		}					
        return false;
    }
}