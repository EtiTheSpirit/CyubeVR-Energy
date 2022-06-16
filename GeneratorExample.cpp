#include "GeneratorExample.h"
#include "EnergyStorage.h"
namespace XTiles 
{

	GeneratorExample::GeneratorExample()
	{
		this->_energyPerFuelUnit = 10;
		this->_maxFuel = 100;
		this->_currentFuel = 100; // May be 0 in a real application, placing the block starts it as empty.
	}

	int GeneratorExample::ExtractEnergy(int amount, bool simulate) 
	{
		// The simulate argument can be used by other devices to see if they can get enough energy out of this device.
		// For example, say something wants 200 energy, but we have only 1 fuel (10 energy, using the default values here, see ctor)

		// Note: This implementation has a critical problem!
		// What if something requests an invalid amount? (amount < 0? What about amount < _energyPerFuelUnit? Fuel is an integer!)
		
		// It would start normally...
		int fuelRequired = amount / _energyPerFuelUnit;
		if (fuelRequired > _currentFuel)
		{
			// ...But if we need more fuel than we have...
			int currentFuel = _currentFuel;
			if (!simulate) 
			{
				// ... Check simulation: skip deducting from the fuel count if we are only simulating...
				// NOTE:
				// => In this situation, we are not simulating so we would need to handle that.
				// You have two options.
				// #1: Only deduct fuel in this condition, then return energy based on the remaining amount of fuel.
				// #2: Return 0, and don't deduct fuel (unrealistic, but friendly to fuel supplies)
				// This example goes with #1.
				_currentFuel = 0; // Set current fuel to 0 when not simulating.
			}

			// ... but otherwise return the amount of energy from the amount of consumed fuel.
			return currentFuel * _energyPerFuelUnit; // ...While still telling the device how much energy it will actually get out.
		}

		_currentFuel -= fuelRequired;
		return fuelRequired * _energyPerFuelUnit;
	}

	int GeneratorExample::ReceiveEnergy(int amount, bool simulate) 
	{
		return 0; // No matter what, this device will not receive any energy. Return 0 to signify that.
	}

	int GeneratorExample::GetStoredEnergy()
	{
		return 0; // Similarly, this should return 0. The device does not store energy, so when polling how much it has, it has 0.
	}

	int GeneratorExample::GetMaxStoredEnergy()
	{
		return 0; // Same as above. Can't store, amount is 0.
	}

	bool GeneratorExample::CanExtract() 
	{
		// For the record: This is a method instead of a field so that it can change during runtime.
		return true;
	}

	bool GeneratorExample::CanReceive() 
	{
		return false;
	}
}
