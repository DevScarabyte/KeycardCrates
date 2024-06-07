modded class ActionConstructor
{
    override void RegisterActions(TTypenameArray actions)
	{
        super.RegisterActions(actions);

        actions.Insert(ActionUnlockCrate);
        actions.Insert(ActionUnlockHackedCrate);
        actions.Insert(ActionCrateOpenClose);
        actions.Insert(ActionHackedCrateOpenClose);
    }
}