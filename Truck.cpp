#ifndef __TRUCK_CPP__
#define __TRUCK_CPP__

#include "Vehicle.h"
#include "Section.h"
#include "Truck.h"



Truck::Truck(std::string theVehTurn)
        : Vehicle(theVehTurn)
        {
            one = nullptr;
            two = nullptr;
            three = nullptr;
            four = nullptr;
        }
    
Truck::~Truck(){}
#endif
