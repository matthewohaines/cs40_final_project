#ifndef __LANE_H__
#define __LANE_H__

#include "Intersection.h"
#include "Section.h"
#include "TrafficLight.h"  
#include "VehicleBase.h"
#include <vector>

class Lane{
    
    private:
        std::vector<Section *> lane;
        Direction direction;
        Section *priorSection;
        TrafficLight *trafficLight;
        int totalLength;

    public:
        Lane(){};
        Lane(int numberOfSections, Direction direction, TrafficLight *trafficLight, Intersection *interOne, Intersection *interTwo);
        ~Lane();

        std::vector<VehicleBase*> getVector();
        Section *getPrior();
        Direction getDirection();
        TrafficLight *getTrafficLight();
        bool canCreate();                                             
};

#endif
