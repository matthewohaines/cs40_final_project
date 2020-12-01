#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "Section.h"
#include <string>

class Vehicle
{
   private:

      int vehicleID;
      std::string intendedTurn;

   public:
      static int vehicleCount;
      Vehicle(std::string turn);
      Vehicle(const Vehicle& other);
      ~Vehicle();
      int getVehicleID();
      int getVehicleCount();
      std::string getTurn();


};

#endif
