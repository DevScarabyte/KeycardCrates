#ifndef CRATECONFIGBASE
#define CRATECONFIGBASE
class CrateConfigBase
{
    protected bool enabled = true;
    protected bool debugging = false;
    [NonSerialized()]
    protected string folder = "SpawnableCrates";
    [NonSerialized()]
    protected string filename = ClassName();

    void CrateConfigBase()
    {
        OnCreate();
    }

    void OnCreate();

    bool IsEnabled() { return enabled; }
    bool IsDebugging() { return debugging; }
    string GetFolder() { return folder; }
    string GetFilename() { return filename; }
    string GetPath()
    {
        return string.Format("$profile:%1/%2.json", folder, filename);
    }
}
#endif