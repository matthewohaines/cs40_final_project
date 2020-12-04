#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include "VehicleBase.h"

class TrafficLight {

    private:
        int greenTime;
        int yellowTime;
        int redTime;
        LightColor color;
        int timeLeft;

    public:
        TrafficLight(LightColor currentColor, int greenTime, int yellowTime, int redTime);
        ~TrafficLight(){}


        LightColor getColor();
        int getTimeLeft();
        void decrement();  
};

#endif
