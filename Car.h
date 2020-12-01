#ifndef __CAR_H__
#define __CAR_H__

#include "Section.h"
#include "Vehicle.h"
#include <string>

class Car : public Vehicle
{

    public:
        Section *one;
        Section *two;

        Car(std::string theVehTurn);
        ~Car();
};

#endif
