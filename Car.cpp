#ifndef __CAR_CPP__
#define __CAR_CPP__


#include "Vehicle.h"
#include "Section.h"
#include "Car.h"

Car::Car(std::string theVehTurn)
        : Vehicle(theVehTurn)
        {
            one = nullptr;
            two = nullptr;
        }
    
Car::~Car(){}
#endif
