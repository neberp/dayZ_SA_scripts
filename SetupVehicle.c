class CreateVehicle
{
	private Car vehicle;
	void CreateVehicle(string vehName, vector pos)
	{
		vehicle = GetGame().CreateObject(vehName, pos);
	}
	void addVehicleFuel(float fuelAmount)
	{
		vehicle.Fill(CarFluid.FUEL, fuelAmount);
	}
	void addVehicleComponents(TStringArray partsArray);
	{
		for (int i = 0; i < partsArray.Count(); i++)
		{
			vehicle.GetInventory().CreateAttachment(partsArray[i]);
		}


		// vehicle.GetInventory().CreateAttachment("HatchbackWheel");
		// vehicle.GetInventory().CreateAttachment("HatchbackWheel");
		// vehicle.GetInventory().CreateAttachment("HatchbackWheel");
		// vehicle.GetInventory().CreateAttachment("HatchbackWheel");
		// vehicle.GetInventory().CreateAttachment("CarBattery");
		// vehicle.GetInventory().CreateAttachment("SparkPlug");

	}
}