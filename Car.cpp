#include "Vehicle.h"
#include "Section.h"

using namespace std;


Car::Car(int theVehID, Section *first, Section *second)
        : Vehicle(theVehID)
        {
            one = *first;
            two = *second;
        }
    
Car::~Car(){}

