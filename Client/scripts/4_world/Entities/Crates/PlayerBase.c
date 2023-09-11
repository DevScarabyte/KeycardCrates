modded class PlayerBase
{
    void SetActions(out TInputActionMap InputActionMap)
	{
        super.SetActions(InputActionMap);

        AddAction(ActionScaraUnlockKeyCardDoor, InputActionMap);
        AddAction(ActionUnlockCrate, InputActionMap);
        AddAction(ActionOpenDebugDoors, InputActionMap);
    }
}