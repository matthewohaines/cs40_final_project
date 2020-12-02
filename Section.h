#ifndef __SECTION_H__
#define __SECTION_H__

#include "Vehicle.h"

class Section {

    private:
        Vehicle *vehicle;
        Section *forward;
        Section *previous;
        Section *right;

        friend class Lane;
        friend class Intersection;

        
    public:
        Section();
        ~Section();

        bool isSectionOccupied();
        void changeSectionOccupied(Vehicle &vehicle);
        Vehicle getVehicle();
};

#endif
