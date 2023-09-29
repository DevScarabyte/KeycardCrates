modded class BuildingBase
{
    private bool m_isKeyCard; // sync on player side?
    private int m_buildingId;
    private bool m_debugging;

    void BuildingBase()
    {
        RegisterNetSyncVariableBool("m_isKeyCard");
        RegisterNetSyncVariableInt("m_buildingId");
        RegisterNetSyncVariableBool("m_debugging");
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