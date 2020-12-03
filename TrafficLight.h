#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include "VehicleBase.h"

class TrafficLight {

    private:
        int red;
        int yellow;
        int green;
        int clock;
        LightColor color;

    public:
        TrafficLight();
        TrafficLight(int greenC, int yellowC, int redC, LightColor colorC);
        ~TrafficLight();

        inline LightColor getColor() { return this->color;}
        inline int getClock() { return this->clock;}
        void decrease();

};

#endif