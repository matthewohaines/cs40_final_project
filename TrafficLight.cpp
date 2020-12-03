#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

TrafficLight::TrafficLight() {
    red = 0;
    yellow = 0;
    green = 0;
    clock = 0;
    color = LightColor::red;

}
TrafficLight::~TrafficLight() {}

TrafficLight::TrafficLight(int greenC, int yellowC, int redC, LightColor colorC) {
        red = redC;
        yellow = yellowC;
        green = greenC;
        color = colorC;
        if(color == LightColor::red) {
           clock = red;
        } 
        else if(color == LightColor::yellow) {
           clock = yellow;
        }
        else {
           clock = green;
        }
}

void TrafficLight::decrease() {
    clock--;
    if(clock == 0) {
        if(color == LightColor::red) {
            color = LightColor::green;
            clock = green;
        }
        else if(color == LightColor::yellow) {
            color = LightColor::red;
            clock = red;       
             }
        else {
            color = LightColor::yellow;
            clock = yellow;
        }
    }
}

#endif