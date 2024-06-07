class CrateSettings extends CrateConfigBase
{
	// autoptr array<autoptr SpawnableLocation> Locations;
	// autoptr array<autoptr ListLootConfig> LootTables;

	// array<autoptr SpawnableLocation> GetLocations() { return Locations; }
	// array<autoptr ListLootConfig> GetLootTables() { return LootTables; }
    autoptr array<autoptr SpawnableCrateData> CrateData;

    array<autoptr SpawnableCrateData> GetCrateData() { return CrateData; }

    SpawnableCrateData GetCrateDataById(string id)
    {
        foreach(SpawnableCrateData data : CrateData)
        {
            if (data.ContainerName == id)
                return data;
        }
        return null;
    }
}

static autoptr CrateSettings g_scara_crates;
static autoptr CrateSettings GetCrateManagerClient()
{
	return g_scara_crates;
}