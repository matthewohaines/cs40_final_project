#ifndef __SECTION_H__
#define __SECTION_H__

#include "VehicleBase.h"

class Section {
    
    private:
        Section *forward;
        Section *previous;
        VehicleBase *vehicle = nullptr;
        bool empty = true;

    protected:
        bool isIntersection = false;

    public:
        Section();
        virtual ~Section(){}

        virtual Section *getForward();
        virtual Section *getPrevious();
        virtual bool getIsIntersection();
        bool isEmpty();
        VehicleBase *getVehicle();
        void setForward(Section *section);
        void setPrevious(Section *section);
        void setEmpty();
        void setVehicle(VehicleBase *veh);
};

#endif
