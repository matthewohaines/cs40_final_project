#ifndef __TRAFFICLIGHT_CPP__
#define __TRAFFICLIGHT_CPP__

#include "TrafficLight.h"

TrafficLight::TrafficLight(LightColor currentColor, int greenTime, int yellowTime, int redTime) {

    this->color = currentColor;
    this->greenTime = greenTime;
    this->yellowTime = yellowTime;
    this->redTime = redTime;
    switch(this->color) {
        case LightColor::green :
            this->timeLeft = this->greenTime;
            break;
        
        case LightColor::yellow :
            this->timeLeft = this->yellowTime;
            break;

        case LightColor::red :
            this->timeLeft = this->redTime;
            break;
    }
}

LightColor TrafficLight::getColor() {

    return this->color;
}

int TrafficLight::getTimeLeft() {

    return this->timeLeft;
}

void TrafficLight::decrement() {
    this->timeLeft--;
    if(this->timeLeft == 0) {
        switch(this->color) {
            case LightColor::green:
                this->color = LightColor::yellow;
                this->timeLeft = yellowTime;
                break;

            case LightColor::yellow:
                this->color = LightColor::red;
                this->timeLeft = redTime;
                break;

            case LightColor::red:
                this->color = LightColor::green;
                this->timeLeft = greenTime;
                break;
            
        }
    }
}


#endif
