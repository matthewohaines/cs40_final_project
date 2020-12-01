#ifndef __SUV_H__
#define __SUV_H__

#include "Section.h"
#include "Vehicle.h"
#include <string>

class Suv : public Vehicle
{

    public:
        Section *one;
        Section *two;
        Section *three;

        Suv(std::string theVehTurn);
        ~Suv();
};

#endif
