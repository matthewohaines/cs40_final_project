#ifndef __SECTION_H__
#define __SECTION_H__

#include "VehicleBase.h"

class Section {

    private:
        Section *forward;
        Section *previous;
        VehicleBase *vehicle;
        bool empty;

    protected:
        bool isIntersection;
        
    public:
        Section();
        virtual ~Section();

        virtual inline Section *getForward() {return forward;}
        virtual inline Section *getPrevious() {return previous;}
        virtual inline bool isEmpty() {return empty;}
        virtual inline VehicleBase *getVehicle() {return vehicle;}
        virtual inline bool getIsIntersection() {return isIntersection;}

        void setForward(Section *current);
        void setPrevious(Section *current);
        void clear();
        void placeVehicle(VehicleBase *veh);
};

#endif