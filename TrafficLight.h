#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include "TrafficLight.h"
#include <string>

class TrafficLight {
    
private:
    std::string color;
    std::string direction;

public:
    TrafficLight::TrafficLight();
    TrafficLight::TrafficLight(std::string directionBound);
    TrafficLight::~TrafficLight();
    TrafficLight::changeColor(std::string lightColor);
    bool TrafficLight::isColorRed();
    bool TrafficLight::isColorYellow();
    bool TrafficLight::isColorGreen();
};

#endif

