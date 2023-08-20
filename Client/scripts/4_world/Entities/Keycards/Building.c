modded class BuildingBase
{
    private bool m_isKeyCard; // sync on player side?
    private int m_buildingId;

    void BuildingBase()
    {
        RegisterNetSyncVariableBool("m_isKeyCard");
        RegisterNetSyncVariableInt("m_buildingId");
    }

    bool IsUsingActions(int door)
    {
        return m_buildingId > 0;
    }

    bool IsKeyCardDoor()
    {
        return m_isKeyCard;
    }

    int GetAction(int door)
    {
        return m_buildingId;
    }

    void UnlockKeyCard(int index)
    {
        UnlockDoor(index);
    }
}