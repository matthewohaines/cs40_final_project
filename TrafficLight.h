#ifndef __TRAFFICLIGHT_H__
#define __TRAFFICLIGHT_H__

#include "TrafficLight.h"
#include <string>

class TrafficLight {
    
private:
    std::string color;
    std::string direction;

public:
    TrafficLight();
    TrafficLight(std::string directionBound, std::string lightColor);
    ~TrafficLight();
    void changeColor(std::string lightColor);
    bool isRed();
    bool isYellow();
    bool isGreen();
    std::string getColor();
    std::string getDirection();
};

#endif

