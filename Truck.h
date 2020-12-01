#ifndef __TRUCK_H__
#define __TRUCL_H__

#include "Section.h"
#include "Vehicle.h"

using namespace std;

class Truck : public Vehicle
{

    public:
        Section *one;
        Section *two;
        Section *three;
        Section *four;

        Truck(int theVehID, Section *first, Section *second, Section *third, Section *fourth);
        ~Truck();
};

#endif
