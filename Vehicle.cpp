#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include "Lane.h"

int Vehicle::vehicleCount = 0;

Vehicle::Vehicle(VehicleType type, Lane theVehicleLane)
    : vehicleID(Vehicle::vehicleCount++), 
      vehicleType(type),
      vehicleLane(theVehicleLane)
{}

Vehicle::Vehicle(const Vehicle& other)
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleLane(other.theVehicleLane)
{}

Vehicle::~Vehicle() {}

#endif
