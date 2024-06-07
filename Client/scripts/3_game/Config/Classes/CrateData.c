class SpawnableCrateData
{
    string LocationName;
    string ContainerName;
    vector POS, ORI;
    int ResetTimer = 120;
    bool ResetPlayerCheck = true;
	bool IsActive = true;
    int ActionID;
    string KeyItem;
    int UnlockTime;
    
    void SpawnableCrateData(string lName, string cname, vector pos, vector ori, int _timer, bool _playerCheck=true, bool _active=true, int _actionId=0, string _keyitem="", int _unlockTime=300)
	{
        LocationName = lName;
        ContainerName = cname;
        POS = pos;
        ORI = ori;
        ResetTimer = _timer;
        ResetPlayerCheck = _playerCheck;
        IsActive = _active;
        ActionID = _actionId;
        KeyItem = _keyitem;
        UnlockTime = _unlockTime;
    }
}