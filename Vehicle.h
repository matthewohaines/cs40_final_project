#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "Section.h"
using namespace std;

class Vehicle
{
   private:

      int vehicleID;

   public:
      static int vehicleCount;
      Vehicle(int theVehicleID);
      Vehicle(const Vehicle& other);
      ~Vehicle();
      int getVehicleID();


};

#endif