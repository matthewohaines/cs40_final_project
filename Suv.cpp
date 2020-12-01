#include "Vehicle.h"
#include "Section.h"


using namespace std;


Suv::Suv(int theVehID, Section *first, Section *second, Section *third)
        : Vehicle(theVehID)
        {
            one = *first;
            two = *second;
            third = *third;
        }
    
Suv::~Suv(){}

