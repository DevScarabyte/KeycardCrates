class ActionOpenDebugDoors extends ActionOpenDoors
{
    string m_custom = "Add door to config";
    BuildingBase _building;

    override void OnActionInfoUpdate( PlayerBase player, ActionTarget target, ItemBase item )
	{
		m_Text = m_custom;
	}

    override bool ActionCondition( PlayerBase player, ActionTarget target, ItemBase item )
	{
		if (!target) 
			return false;

		if (!IsBuilding(target)) 
			return false;

		if (Class.CastTo(_building, target.GetObject()))
		{
            Print("Building Debugging: " + player.IsDebuggingDoors());
            if (player.IsDebuggingDoors())
            {
                int doorIndex = _building.GetDoorIndex(target.GetComponentIndex());
                if (doorIndex != -1)
                {
                    if (!IsInReach(player, target, UAMaxDistances.DEFAULT)) 
                        return false;
                    
                    if (_building.IsDoorOpen(doorIndex))
                        return false;

                    if (CheckIfDoorIsLocked())
                    {
                        if (_building.IsDoorLocked(doorIndex))
                            return false;
                    }
                    else
                    {
                        if (!_building.IsDoorLocked(doorIndex))
                            return false;
                    }

                    return true;
                }
            }
		}

		return false;
	}
}