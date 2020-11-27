#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "Lane.h"

enum class VehicleType {car, suv, truck};

class VehicleBase
{
   public:
      static int vehicleCount;

   private:
      int         vehicleID;
      VehicleType vehicleType;
      Lane   vehicleLane;

   public:
      VehicleBase(VehicleType type, Lane theVehicleLane);
      VehicleBase(const VehicleBase& other);
      ~VehicleBase();

      inline int getVehicleID() const { return this->vehicleID; }

      inline VehicleType getVehicleType() const { return this->vehicleType; }

};

#endif