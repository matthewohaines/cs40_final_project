#ifndef __SUV_CPP__
#define __SUV_CPP__

#include "Vehicle.h"
#include "Section.h"
#include "Suv.h"


Suv::Suv(std::string theVehTurn)
        : Vehicle(theVehTurn)
        {
            one = nullptr;
            two = nullptr;
            three = nullptr;
        }
    
Suv::~Suv(){}
#endif
