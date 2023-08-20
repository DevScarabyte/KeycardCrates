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
class CfgSoundShaders
{
	class baseCharacter_SoundShader;
	class CardAcceptedSound_Shader: baseCharacter_SoundShader
	{
		samples[] = {{"\KeycardCrates\Client\sounds\Door_Accepted",1}};
		volume = 1;
		range = 10;
	};
	class CardDeniedSound_Shader: baseCharacter_SoundShader
	{
		samples[] = {{"\KeycardCrates\Client\sounds\Door_Denied",1}};
		volume = 1;
		range = 10;
	};
};
class CfgSoundSets
{
	class baseCharacter_SoundSet;
	class CardAccepted_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[] = {"CardAcceptedSound_Shader"};
	};
	class CardDenied_SoundSet: baseCharacter_SoundSet
	{
		soundShaders[] = {"CardDeniedSound_Shader"};
	};
};