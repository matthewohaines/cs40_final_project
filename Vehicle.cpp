#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include "Section.h"
using namespace std;


Vehicle::Vehicle(int theVehicleID)
{
	vehicleID = theVehicleID;
	vehicleCount++;
}

Vehicle::Vehicle(const Vehicle& other)
    : vehicleID(other.vehicleID)
    {
    	vehicleCount++;
    }

Vehicle::~Vehicle(){}

int Vehicle::getVehicleID()
{
	return this->vehicleID;
}

int Vehicle::getVehicleCount()
{
	return vehicleCount;
}

#endif
