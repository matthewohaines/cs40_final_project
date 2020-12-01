#ifndef __SUV_H__
#define __SUV_H__

#include "Section.h"
#include "Vehicle.h"

using namespace std;

class Suv : public Vehicle
{

    public:
        Section *one;
        Section *two;
        Section *three;

        Suv(int theVehID, Section *first, Section *second, Section *third);
        ~Suv();
};

#endif
