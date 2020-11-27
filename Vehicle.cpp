#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"

int Vehicle::vehicleCount = 0;

Vehicle::Vehicle(VehicleType type, Direction direction)
    : vehicleID(Vehicle::vehicleCount++), 
      vehicleType(type),
      vehicleDirection(direction)
{}

Vehicle::Vehicle(const Vehicle& other)
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleDirection(other.vehicleDirection)
{}

Vehicle::~Vehicle() {}

#endif
