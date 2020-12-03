#ifndef __VEHICLEBASE_CPP__
#define __VEHICLEBASE_CPP__

#include "VehicleBase.h"

int VehicleBase::vehicleCount = 0;

VehicleBase::VehicleBase(VehicleType type, Direction initialDirection) 
    : vehicleID(VehicleBase::vehicleCount++),
      vehicleType(type),
      vehicleDirection(initialDirection)
    {}

VehicleBase::VehicleBase(const VehicleBase& other) 
    : vehicleID(other.vehicleID),
      vehicleType(other.vehicleType),
      vehicleDirection(other.vehicleDirection)
    {}

VehicleBase::~VehicleBase() {}

#endif