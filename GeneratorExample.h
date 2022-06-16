#pragma once
#include "EnergyStorage.h"
namespace XTiles 
{
	class GeneratorExample : public EnergyStorage
	{
	public:

		GeneratorExample();

		// From EnergyStorage's required overloads
		int ReceiveEnergy(int receiveAmount, bool isSimulated);
		int ExtractEnergy(int extractAmount, bool isSimulated);
		int GetStoredEnergy();
		int GetMaxStoredEnergy();
		bool CanExtract();
		bool CanReceive();

	protected:
		/// <summary>
		/// The amount of energy generated per fuel unit.
		/// </summary>
		int _energyPerFuelUnit;

		/// <summary>
		/// The amount of fuel this can store.
		/// </summary>
		int _maxFuel;

		/// <summary>
		/// The current amount of fuel this has.
		/// </summary>
		int _currentFuel;
	};
}
