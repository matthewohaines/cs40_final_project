#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

TrafficLight::TrafficLight() {

    this->color = "";
    this->direction = "";
}

TrafficLight::TrafficLight(std::string directionBound, std::string lightColor){
    this->direction = directionBound;
    this->color = lightColor;
}

TrafficLight::~TrafficLight() {}

void TrafficLight::changeColor(std::string lightColor) {
    this->color = lightColor;
}

bool TrafficLight::isRed(){
    if (this->color == "red"){
        return true;
    }
    return false;
}

bool TrafficLight::isYellow(){
    if (this->color == "yellow"){
        return true;
    }
    return false;
}

bool TrafficLight::isGreen(){
    if (this->color == "green"){
        return true;
    }
    return false;
}

std::string TrafficLight::getColor(){
    return this->color;
}
#endif

