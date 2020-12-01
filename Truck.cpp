#include "Vehicle.h"
#include "Section.h"


using namespace std;


Truck::Truck(int theVehID, Section *first, Section *second, Section *third, Section *fourth)
        : Vehicle(theVehID)
        {
            one = *first;
            two = *second;
            third = *third;
            four = *fourth;
        }
    
Truck::~Truck(){}

