#ifndef __TRUCK_H__
#define __TRUCK_H__

#include "Section.h"
#include "Vehicle.h"
#include <string>

class Truck : public Vehicle
{

    public:
        Section *one;
        Section *two;
        Section *three;
        Section *four;

        Truck(std::string theVehTurn);
        ~Truck();
};

#endif
