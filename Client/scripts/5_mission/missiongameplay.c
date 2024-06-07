modded class MissionGameplay
{
    void MissionGameplay()
    {
        GetRPCManager().AddRPC("SpawnableCrates", "SyncToClient", this);
    }

    void SyncToClient(CallType type, ParamsReadContext ctx, PlayerIdentity sender, Object target)
	{
        SpawnableCrateLogger.Debug(this, "Config Synchronized");
		Param1<autoptr CrateSettings> data;
		if (!ctx.Read(data)) return;

        g_scara_crates = data.param1;
	}
}