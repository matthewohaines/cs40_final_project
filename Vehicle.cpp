#ifndef __VEHICLE_CPP__
#define __VEHICLE_CPP__

#include "Vehicle.h"
#include "Lane.h"

int VehicleBase::vehicleCount = 0;

VehicleBase::VehicleBase(VehicleType type, Lane theVehicleLane)
    : vehicleID(VehicleBase::vehicleCount++), 
      vehicleType(type),
      vehicleLane(theVehicleLane)
{}

VehicleBase::VehicleBase(const VehicleBase& other)
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleLane(other.vehicleLane)
{}

VehicleBase::~VehicleBase() {}

#endif
