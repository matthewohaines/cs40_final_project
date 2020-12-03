#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "VehicleBase.h"
#include "Section.h"
#include "Lane.h"

enum class IntendedTurn {forward, right};

class Vehicle : public VehicleBase {

    private:
        Section *first;
        Section *last;
        Lane *lane;
        IntendedTurn intendedTurn;
        bool atEnd;
        int length;
        void moveForward();
        void moveRight();

    public:
        Vehicle(Lane *laneC, VehicleType type, IntendedTurn turn);
        ~Vehicle(){}
        void move();
        inline bool isAtEnd() { return this->atEnd;}
        inline IntendedTurn getIntendedTurn() { return this->intendedTurn; }
};

#endif