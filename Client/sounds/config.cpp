class CfgPatches
{
	class KeycardSounds
	{
		units[] = {};
		ammo[] = {};
		weapons[] = {};
		magazines[] = {};
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data"};
	};
};
class CfgSounds
{
	class default
	{
		name = "";
		titles[] = {};
	};
	class Sound_Door_Accepted: default
	{
		sound[] = {"\KeycardCrates\Client\sounds\Door_Accepted",1,1,1000};
	};
	class Sound_Door_Denied: default
	{
		sound[] = {"\KeycardCrates\Client\sounds\Door_Denied",1,1,1000};
	};
};
