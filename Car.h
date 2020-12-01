#ifndef __CAR_H__
#define __CAR_H__

#include "Section.h"
#include "Vehicle.h"

using namespace std;

class Car : public Vehicle
{

    public:
        Section *one;
        Section *two;

        Car(int theVehID, Section *first, Section *second);
        ~Car();
};

#endif
