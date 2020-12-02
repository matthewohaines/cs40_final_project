#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"

int Vehicle::vehicleCount = 0;

Vehicle::Vehicle(VehicleType type, Direction initialDirection, IntendedTurn intendedTurn) 
    : vehicleID(Vehicle::vehicleCount++),
      vehicleType(type),
      vehicleDirection(initialDirection),
      intendedTurn(intendedTurn),
      position{}

    {}

Vehicle::Vehicle(const Vehicle& other) 
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleDirection(other.vehicleDirection),
      intendedTurn(other.intendedTurn),
      position(other.position)

    {}

Vehicle::~Vehicle() {}

int Vehicle::getVehicleID() {
    
    return this->vehicleID;
}

VehicleType Vehicle::getVehicleType() {

    return this->vehicleType;
}

Direction Vehicle::getVehicleInitialDirection() {

    return this->vehicleDirection;
}

IntendedTurn Vehicle::getIntendedTurn() {

    return this->intendedTurn;
}

#endif
