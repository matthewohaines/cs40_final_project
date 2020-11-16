#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

TrafficLight::TrafficLight() {

    this->color = "";
    this->direction = "";
}

TrafficLight::TrafficLight(std::string directionBound){
    this->direction = directionBound;
    this->color = "red"
}

TrafficLight::~TrafficLight() {}

TrafficLight::changeColor(std::string lightColor) {
    this->color = lightColor
}

bool TrafficLight::isColorRed(){
    if (this->color == "red"){
        return true;
    }
    returnn false;
}

bool TrafficLight::isColorYellow(){
    if (this->color == "yellow"){
        return true;
    }
    returnn false;
}

bool TrafficLight::isColorGreen(){
    if (this->color == "green"){
        return true;
    }
    return false;
}
#endif

