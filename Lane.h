#ifndef __LANE_H__
#define __LANE_H__

#include "Section.h"
#include "Intersection.h"
#include "VehicleBase.h"
#include "TrafficLight.h"
#include <vector>

class Lane {

    private:
        Direction direction;
        Section *first;
        Section *last;
        int length;
        TrafficLight *trafficLight;
        std::vector<Section*> road;
        Section *link(int num, Section *last);

    public:
        Lane();
        Lane(Direction direction, int number_of_sections_before_intersection, TrafficLight *trafficLight, Intersection *interOne, Intersection *interTwo);
        ~Lane();

        std::vector<VehicleBase*> getVector();
        inline Direction getDirection() { return this->direction; }
        inline TrafficLight *getTrafficLight() { return this->trafficLight; }
        inline Section *getFirst() { return this->first;}

        bool canPlace();
        
};

#endif

