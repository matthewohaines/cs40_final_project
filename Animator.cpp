#ifndef __ANIMATOR_CPP__
#define __ANIMATOR_CPP__

#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include "Animator.h"


// used for drawing width -- can be defined by user
int Animator::MAX_VEHICLE_COUNT = 9999;

// computed in constructor since user can redefine count above
int Animator::DIGITS_TO_DRAW = 0;
// repeated strings of '-' or ' ' based on the digit-width MAX_VEHCILE_COUNT;
// both computed in constructor
std::string Animator::SECTION_BOUNDARY_EW = "";
std::string Animator::EMPTY_SECTION = "";

// see https://unix.stackexchange.com/questions/124407/what-color-codes-can-i-use-in-my-ps1-prompt
const std::string Animator::COLOR_RED_FG    = "\033[1;31m";
const std::string Animator::COLOR_GREEN_FG  = "\033[1;32m";
const std::string Animator::COLOR_BLUE_FG   = "\033[1;34m";
const std::string Animator::COLOR_RED_BG    = "\033[41m\033[1;37m";
const std::string Animator::COLOR_GREEN_BG  = "\033[42m\033[1;37m";
const std::string Animator::COLOR_BLUE_BG   = "\033[44m\033[1;37m";
const std::string Animator::COLOR_YELLOW_BG = "\033[43m\033[1;37m";
const std::string Animator::COLOR_RESET     = "\033[0m";

std::string Animator::GREEN_LIGHT = "";
std::string Animator::YELLOW_LIGHT = "";
std::string Animator::RED_LIGHT = "";

const std::string Animator::SECTION_BOUNDARY_NS = "|";
const std::string Animator::ERROR_MSG =
    "Error in Animator::draw: must call all four Animator::setVehicles* methods prior to calling Animator::draw";

//======================================================================
//* Animator::Animator(int numSectionsBeforeIntersection)
//======================================================================
Animator::Animator(int numSectionsBeforeIntersection)
{
    // redo here in case the user set MAX_VEHCILE_COUNT differently
    Animator::DIGITS_TO_DRAW = Animator::MAX_VEHICLE_COUNT <= 1 ? 
        2 : static_cast<int>(log10(Animator::MAX_VEHICLE_COUNT)) + 1;
    Animator::SECTION_BOUNDARY_EW = std::string(Animator::DIGITS_TO_DRAW, '-');
    Animator::EMPTY_SECTION = std::string(Animator::DIGITS_TO_DRAW, ' ');

    // these will use the redone DIGITS TO DRAW above
    Animator::GREEN_LIGHT  = createLight("green");
    Animator::YELLOW_LIGHT = createLight("yellow");
    Animator::RED_LIGHT    = createLight("red");

    numSectionsBefore = numSectionsBeforeIntersection;
    // each lane will be twice the number of sections provided (before and 
    // after the intersection) plus the two intersection sections
   

    // this will set the values in the vector to 0 (false), indicating that
    // the user must set the vehicles in each of the four directions using the
    // setVehicles* functions
  
}

//======================================================================
//* Animator::~Animator()
//======================================================================
Animator::~Animator() {}

//======================================================================
//* std::string Animator::createLight(LightColor color)
//======================================================================
std::string Animator::createLight(std::string color)
{
    std::string light = "";

    if (color == "green")  light += Animator::COLOR_GREEN_BG;
    if (color == "yellow") light += Animator::COLOR_YELLOW_BG;
    if (color == "red")    light += Animator::COLOR_RED_BG;

    light += std::string(2, ' ') + Animator::COLOR_RESET;

    return light;
}
std::string Animator::getTrafficLight(TrafficLight theLight)
{
    std::string color = theLight.getColor();

    std::string light = "";
    
    // when odd DIGITS_TO_DRAW, want the extra padding on left of lights
    // for the southbound and eastbound traffice
    if (theLight.getDirection() == "southbound" || theLight.getDirection() == "eastbound")
        light += Animator::DIGITS_TO_DRAW % 2 == 0 ?
            std::string((Animator::DIGITS_TO_DRAW - 2) / 2, ' ') :
            std::string((Animator::DIGITS_TO_DRAW - 1) / 2, ' ');
    else
        light += std::string((Animator::DIGITS_TO_DRAW - 2) / 2, ' ');

    
    if (color == "green"){
       light += Animator::GREEN_LIGHT;
    } 
    if (color == "yellow"){
       light += Animator::YELLOW_LIGHT;
    }
    if (color == "red"){
       light += Animator::RED_LIGHT; 
    }
    
    // when odd DIGITS_TO_DRAW, want the extra padding on right of lights
    // for the northbound and westbound traffice
    if (theLight.getDirection() == "southbound" || theLight.getDirection() == "eastbound")
        light += std::string((Animator::DIGITS_TO_DRAW - 2) / 2, ' ');
    else
        light += Animator::DIGITS_TO_DRAW % 2 == 0 ?
            std::string((Animator::DIGITS_TO_DRAW - 2) / 2, ' ') :
            std::string((Animator::DIGITS_TO_DRAW - 1) / 2, ' ');

    return light;
}


#endif

