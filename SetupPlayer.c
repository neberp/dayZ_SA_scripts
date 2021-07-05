class SetUpDefaultPlayerWeapon
{
	private PlayerBase player;
	private EntityAI weapon;

	void SetUpDefaultPlayerWeapon(PlayerBase pIn)
	{
		player = pIn;
		weapon = player.GetHumanInventory().CreateInHands("M4A1");
		addWeaponAttachments();
	}

	void addWeaponAttachments()
	{
		weapon.GetInventory().CreateAttachment("M4_OEBttstck");
		weapon.GetInventory().CreateAttachment("M4_CarryHandleOptic");
		weapon.GetInventory().CreateAttachment("M4_PlasticHndgrd");
	}
	void addMagazineToPlayer()
	{
		player.GetInventory().CreateInInventory("Mag_STANAG_30Rnd");
	}
};