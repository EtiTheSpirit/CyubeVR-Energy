#pragma once
namespace XTiles 
{
	/// <summary>
	/// Represents an arbitrary object that can store a common unit of energy. 
	/// This is also for objects that consume or generate this energy.
	/// Implementors should extend this class.
	/// 
	/// Implementation derived from COFH's "Redstone Flux", a Minecraft modding API for energy.
	/// </summary>
	class EnergyStorage 
	{
		/*
		-> Copy/Paste for your .h files that implement this:

		int ReceiveEnergy(int receiveAmount, bool isSimulated);
		int ExtractEnergy(int extractAmount, bool isSimulated);
		int GetStoredEnergy();
		int GetMaxStoredEnergy();
		bool CanExtract();
		bool CanReceive();

		//////////////////////////////////////////////////////////////////////////
		
		-> IMPORTANT NOTES:
		Remember to use the return values of Extract/Receive, and use simulation!
		WRONG:
			int useEnergy = 10;
			thing.ExtractEnergy(useEnergy, false);
			this->energy -= useEnergy;

		CORRECT (if the device can use any amount of energy):
			int useEnergy = 10;
			int takenEnergy = thing.ExtractEnergy(useEnergy, false); // Note simulate=false
			this->energy -= takenEnergy;

		CORRECT (if the device needs a specific amount, no less):
			int neededEnergy = 10;
			int takenEnergy = thing.ExtractEnergy(neededEnergy, true); // Note simulate=true
			if (takenEnergy >= neededEnergy) 
			{
				thing.ExtractEnergy(neededEnergy, false); // Do not need to assign takenEnergy here, simulate already gave us the result.
				this->energy -= takenEnergy;
			}
			
		*/

	public:

		/// <summary>
		/// Instruct this storage to receive up to the given amount of energy.
		/// </summary>
		/// <param name="receiveAmount">The amount of energy to receive.</param>
		/// <param name="isSimulated">If true, the operation should be only simulated and this should not actually affect the storage.</param>
		/// <returns>The actual amount of energy that was stored in this storage.</returns>
		virtual int ReceiveEnergy(int receiveAmount, bool isSimulated) = 0;

		/// <summary>
		/// Instruct this storage to release up to the given amount of energy.
		/// </summary>
		/// <param name="extractAmount">The amount of energy to take.</param>
		/// <param name="isSimulated">If true, the operation should be only simulated, and this should not actually affect the storage.</param>
		/// <returns>The actual amount of energy that was taken from this storage.</returns>
		virtual int ExtractEnergy(int extractAmount, bool isSimulated) = 0;

		/// <summary>
		/// Returns the current amount of energy that is stored within this storage.
		/// </summary>
		/// <returns>The current amount of energy that is stored within this storage.</returns>
		virtual int GetStoredEnergy() = 0;

		/// <summary>
		/// Returns the largest amount of energy that can be stored within this storage.
		/// </summary>
		/// <returns>The largest amount of energy that can be stored within this storage.</returns>
		virtual int GetMaxStoredEnergy() = 0;

		/// <summary>
		/// Returns true if outside influences can extract energy from this device.
		/// Generally this should be false if this is some machine that needs energy to run.<para/>
		/// Actors should ALWAYS call this method before attempting to take energy from this!
		/// </summary>
		/// <returns>True if outside influences can extract energy from this device, false if not.</returns>
		virtual bool CanExtract() = 0;

		/// <summary>
		/// Returns true if outside influences can give energy to this device.
		/// Generally this should be false if this is some generator that makes energy on its own.<para/>
		/// Actors should ALWAYS call this method before attempting to send energy to this!
		/// </summary>
		/// <returns>True if outside influences can give energy to this device, false if not.</returns>
		virtual bool CanReceive() = 0;
		
	};
}
