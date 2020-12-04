#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "VehicleBase.h"
#include "Lane.h"
#include "Section.h"

class Vehicle : public VehicleBase{
    private:

        Lane *lane;             
        Section *first;        
        Section *last;          
        int length;            
        bool atTheEnd = false;
        bool willTurn;  

    public:
        Vehicle(Lane *initialLane, VehicleType type, bool willTurn);
        ~Vehicle(){}

        void move();                                   
        bool reachedEnd();  
        bool getWillTurn();
};
#endif
