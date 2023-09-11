modded class Container_Base//SpawnableCase_Base extends Container_Base
{
	protected bool kc_IsLocked;
	protected bool kc_spawnable;
	protected bool kc_isRandom;
	protected bool kc_looted;
	protected bool kc_ready;
	protected bool kc_clear;
	protected int kc_keyItem;
	protected int kc_keytime;
	protected bool kc_playerCheck;
	protected int kc_respawntime;
	// private bool kc_IsOpenable;

	void Container_Base()
	{
		kc_looted = false;
		kc_ready = false;
		RegisterNetSyncVariableBool("kc_IsLocked");
		RegisterNetSyncVariableBool("kc_isRandom");
		RegisterNetSyncVariableBool("kc_looted");
		RegisterNetSyncVariableBool("kc_ready");
		RegisterNetSyncVariableBool("kc_clear");
		RegisterNetSyncVariableInt("kc_keyItem");
		RegisterNetSyncVariableInt("kc_keytime");
		RegisterNetSyncVariableBool("kc_playerCheck");
		RegisterNetSyncVariableInt("kc_respawntime");
	}

	override void EECargoOut(EntityAI item)
	{
		super.EECargoOut(item);

		if(IsSpawnableCrate())
		{
			if (GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).GetRemainingTime(ResetCrate))
				GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove(ResetCrate);

			GetGame().GetCallQueue(CALL_CATEGORY_SYSTEM).CallLater(ResetCrate, 2*60*1000);
		}
	}

	override bool NameOverride(out string output)
	{
		if ( IsLocked() )
		{
			GetGame().ObjectGetDisplayName(this, output);
			output = string.Format("Locked %1", output);  
			return true;
		}
		return super.NameOverride(output);
	}

	override bool CanDisplayCargo()
	{
		if ( IsLocked() ) return false;
		return super.CanDisplayCargo();
	}

	override bool CanPutIntoHands( EntityAI parent )
	{
		if(IsSpawnableCrate()) return false;
		return super.CanPutIntoHands(parent);
	}

	override bool CanPutInCargo( EntityAI parent )
	{
		if(IsSpawnableCrate()) return false;
		return super.CanPutInCargo(parent);
	}

	/*
	 * Custom Functions
	 */

	void ResetCrate() // this is so we know they are still looting
	{
		SetLooted(true);
		SetReady(false);

		// we should reset on timer
		if(GetRespawnTime() > 0)
		{
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).CallLater(ProcessCrate, GetRespawnTime()*1000);
		}
	}

	void ProcessCrate()
	{
		// refresh
		if (IsRandom())
		{
			Delete();
		}
		else
		{
			int cargoCount = GetInventory().CountInventory();
			CargoBase CargoItems1 = GetInventory().GetCargo();
			for( int i = 0; i < cargoCount; i++)
			{
				if (CargoItems1.GetItem(i))
					CargoItems1.GetItem(i).Delete();
			}
			PrepCrate();
		}
	}

	void PrepCrate() // this is getting the crate ready for spawning loot
	{
		if (GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).GetRemainingTime(ResetCrate))
			GetGame().GetCallQueue( CALL_CATEGORY_SYSTEM ).Remove(ResetCrate);

		// no players should be near when this is called
		SetLooted(false);
		SetReady(true);
	}

	void SetReady(bool value)
	{
		kc_ready = value;
		SetSynchDirty();
	}

	void SetLooted(bool value)
	{
		kc_looted = value;
		SetSynchDirty();
	}

	int GetKeyItem()
	{
		return kc_keyItem;
	}

	int GetUnlockTime()
	{
		return kc_keytime;
	}

	bool Looted() 
	{
		return kc_looted;
	}

	bool IsReady() 
	{
		return kc_ready;
	}
	
	bool IsLocked()
	{
		return kc_IsLocked;
	}

	bool IsSpawnableCrate()
	{
		return kc_spawnable;
	}
	
	bool GetPlayerCheck()
	{
		return kc_playerCheck;
	}

	int GetRespawnTime()
	{
		return kc_respawntime;
	}

	bool IsRandom()
	{
		return kc_isRandom;
	}

	bool TimeToClear() { return kc_clear; }
}

class SpawnableCase_Base extends Container_Base{};
class SpawnableCase_Openable_Base extends SpawnableCase_Base
{
	protected bool kc_IsOpened;
	protected bool kc_IsOpenedLocal;
	
	void SpawnableCase_Openable_Base()
	{
		RegisterNetSyncVariableBool("kc_IsOpened");
	}

	override void EEInit()
	{
		super.EEInit();		
        if(IsOpen())
            GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
		else
			GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);		
	}

	override void Open()
	{
		kc_IsOpened = true;
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().UnlockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override void Close()
	{
		kc_IsOpened = false;
		SoundSynchRemote();
		UpdateVisualState();
		GetInventory().LockInventory(HIDE_INV_FROM_SCRIPT);
	}

	override bool IsOpen()
	{
		return kc_IsOpened;
	}

	void UpdateVisualState()
	{
		if ( IsOpen() )
		{
			SetAnimationPhase("Lid",1);
			SetAnimationPhase("Lid2",0);
		}
		else
		{
			SetAnimationPhase("Lid",0);
			SetAnimationPhase("Lid2",1);
		}
	}

	override void OnVariablesSynchronized()
	{
		super.OnVariablesSynchronized();
		
		if ( kc_IsOpened != kc_IsOpenedLocal )
		{		
			if ( IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
			{
				SoundOpenPlay();
			}
			
			if ( !IsOpen() && IsSoundSynchRemote() && !IsBeingPlaced() )
			{
				SoundClosePlay();
			}	
			kc_IsOpenedLocal = kc_IsOpened;
		}
		
		UpdateVisualState();
	}
	
	override void OnStoreSave( ParamsWriteContext ctx )
	{   
		super.OnStoreSave( ctx );		
		ctx.Write( kc_IsOpened );
	}
	
	override bool OnStoreLoad( ParamsReadContext ctx, int version )
	{
		if ( !super.OnStoreLoad( ctx, version ) )
			return false;
		
		if (!ctx.Read( kc_IsOpened ) )
			return false;
		
		if ( kc_IsOpened )
			Open();
		else
			Close();
		
		return true;
	}

	void SoundOpenPlay()
	{
	}
	
	void SoundClosePlay()
	{
	}
	
	override bool CanReleaseCargo(EntityAI attachment)
	{
		return IsOpen();
	}

	override void SetActions()
	{
		super.SetActions();
		
		AddAction(ActionCrateOpenClose);
	}
}