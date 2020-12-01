#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include "Section.h"


int Vehicle::vehicleCount = 0;
Vehicle::Vehicle(std::string turn)
{
	this->vehicleID = vehicleCount;
        this->intendedTurn = turn;
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
std::string Vehicle::getTurn()
{
        return this->intendedTurn;
}

int Vehicle::getVehicleCount()
{
	return vehicleCount;
}

#endif
