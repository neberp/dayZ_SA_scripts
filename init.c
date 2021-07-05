void main()
{
	vector player_pos;
	int index;

	TVectorArray

	Hive ce = CreateHive();
	if(ce)
		ce.InitOffline();
	
	Weather weather = g_Game.GetWeather();

	weather.GetOvercast().SetLimits(0.0, 1.0);
	weather.GetRain().SetLimits(0.0, 1.0);
	weather.GetFog().SetLimits(0.0, 0.25);

	weather.GetOvercast().SetForecastChangeLimits(0.5, 0.8);
	weather.GetRain().SetForecastChangeLimits( 0.1, 0.3);
	weather.GetFog().SetForecastChangeLimits(0.05, 0.10);

	weather.GetOvercast().SetForecastTimeLimits(3600, 3600);
	weather.GetRain().SetForecastTimeLimits(300, 300);
	weather.GetFog().SetForecastTimeLimits(3600, 3600);

	weather.GetOvercast().Set(Math.RandomFloatInclusive(0.0, 0.3), 0, 0);
	weather.GetRain().Set(Math.RandomFloatInclusive(0.0, 0.2), 0, 0);
	weather.GetFog().Set(Math.RandomFloatInclusive(0.0, 0.1), 0, 0);

	weather.SetWindMaximumSpeed(30);
	weather.SetWindFunctionParams(0.1, 1.0, 50);

}

class CustomMission: MissionServer
{
	void SetRandomHealth(EntityAI itemEnt)
	{
		int rndHlt = Math.RandomInt(40,100);
		itemEnt.SetHealth("","",rndHlt);
	}

	override PlayerBase CreateCharacter(PlayerIdentity identity, vector pos, ParamsReadContext ctx, strong characterName)
	{
		Entity playerEnt;
		playerEnt = GetGame().CreatePlayer(identity, characterName, pos, 0, "NONE");
		Class.CastTo(m_player, playerEnt);

		GetGame().SelectPlayer(identity, m_player);

		return m_player;
	}

	override void StartingEquipSetup(PlayerBase player, bool clothesChosen)
	{
		// player.RemoveAllItems();

		// EntityAI item = player.GetInventory().CreateInInventory(topsArray.GetRandomElement());

		SetUpDefaultPlayerWeapon pObj = new SetUpDefaultPlayerWeapon(player);

		TStringArray hatchbackComponents = {"HatchbackWheel", "HatchbackWheel", "HatchbackWheel", "HatchbackWheel", "CarBattery", "SparkPlug"};

		CreateVehicle myHatchback = new CreateVehicle("OffroadHatchback", player.GetPosition());
		myHatchback.addVehicleFuel(1000);
		myHatchback.addVehicleComponents();
		
		EntityAI itemEnt;
		ItemBase itemBs;

		itemEnt = player.GetInventory().CreateInInventory("Rag");
		itemBs = ItemBase.Cast(itemEnt);
		itemBs.SetQuantity(4);
		SetRandomHealth(itemEnt);

		itemEnt = player.GetInventory().CreateInInventory("RoadFlare");
		itemBs = ItemBase.Cast(itemEnt);
	}

	override void TickScheduler(float timeSplice)
	{
		int currentTime = GetGame().GetTime() * 0.001;
		static int nTime = 0;
		int messageDelay = 5;

		if(currentTime >= nTime + messageDelay) {
			GetGame().ChatPlayer(1, "Server: " + currentTime.ToString());
			nTime = currentTime;
		}
	}
};

Mission CreateCustomMission(string path)
{
	return new CustomMission();
}