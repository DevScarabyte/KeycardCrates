modded class PlayerBase extends ManBase
{
    protected bool m_debuggingdoors;

    void PlayerBase()
    {
        RegisterNetSyncVariableBool("m_debuggingdoors");
    }

    bool IsDebuggingDoors() { return m_debuggingdoors; }
}
