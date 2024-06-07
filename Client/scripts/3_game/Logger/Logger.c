#ifdef DZ_DabsFramework
[RegisterLogger(SpawnableCrateLogger)]
class SpawnableCrateLogger extends LoggerBase
{
	override string GetFolderName()
	{
		return "SpawnableCrates\\logs\\";
	}

    override string GetFileFormat()
	{
		return "%t%_%y%-%m%-%d%";
	}

    override bool DuplicateToConsole()
	{
		return true;
	}
	
	static void Debug(Class inst, string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		string inst_type;
		if (inst) {
			inst_type = "[" + inst.Type() + "]";
		}
		
		Log("[DEBUG]" + inst_type + ": " + string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9));
	}
	
	static void Error(Class inst, string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		string inst_type;
		if (inst) {
			inst_type = "[" + inst.Type() + "]";
		}
		
		Log("[ERROR]" + inst_type + ": " + string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9));
	}

	static void Info(Class inst, string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		string inst_type;
		if (inst) {
			inst_type = "[" + inst.Type() + "]";
		}
		
		Log("[ INFO]" + inst_type + ": " + string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9));
	}
		
	static override void Log(string log)
	{
		DoLog(SpawnableCrateLogger, log);
	}
}
#else
class SpawnableCrateLogger
{
	static void Debug(Class inst, string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		string inst_type;
		if (inst) {
			inst_type = "[" + inst.Type() + "]";
		}
		
		Log("[DEBUG]" + inst_type + ": " + string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9));
	}
	
	static void Error(Class inst, string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		string inst_type;
		if (inst) {
			inst_type = "[" + inst.Type() + "]";
		}
		
		Log("[ERROR]" + inst_type + ": " + string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9));
	}

	static void Info(Class inst, string msg, string param1 = "", string param2 = "", string param3 = "", string param4 = "", string param5 = "", string param6 = "", string param7 = "", string param8 = "", string param9 = "")
	{
		string inst_type;
		if (inst) {
			inst_type = "[" + inst.Type() + "]";
		}
		
		Log("[ INFO]" + inst_type + ": " + string.Format(msg, param1, param2, param3, param4, param5, param6, param7, param8, param9));
	}
		
	static void Log(string log)
	{
		PrintFormat("%1", log);
	}
}
#endif
enum CrateLogLevels
{
	DEBUG,
	ERROR,
	INFO
}