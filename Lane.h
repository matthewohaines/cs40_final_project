#ifndef __LANE_H__
#define __LANE_H__

#include "Section.h"
#include <string>
#include "Intersection.h"

class Lane {

    private:
        std::string direction;
        int numberOfSections;
        int currentPosition;

    public:
        Section *firstSection;
        Section *lastSection;
        Section *currentSection;
        std::string getCurrentDirection();
        int getCurrentPosition();
        int getNumberOfSections();
        
        Lane(std::string direction, int number_of_sections_before_intersection);
        ~Lane();
        void add();
        void createLane(int number_of_sections_before_intersection);
        void reset();
        void moveCurrent(Intersection &inter, int number);
        void linkFromIntersection(Intersection &inter, int number_of_sections_before_intersection);
        void linkToIntersection(Intersection &inter, int number_of_sections_before_intersection);
};

#endif

