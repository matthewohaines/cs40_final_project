#ifndef __SECTION_H__
#define __SECTION_H__

#include "Vehicle.h"

class Section {

    private:
        Section *forward;
        Section *previous;
        Section *right;

        friend class Lane;
        friend class Intersection;

        
    public:
        Section();
        ~Section();
        Vehicle *vehicle;

        bool isSectionOccupied();
        void changeSectionOccupied(Vehicle &vehicle);
        Vehicle getVehicle();
};

#endif
