#ifndef __LANE_H__
#define __LANE_H__

#include "Section.h"
#include <string>
#include <deque>
#include "Intersection.h"
#include "Vehicle.h"

class Lane {

    private:
        std::string direction;
        int numberOfSections;
        int currentPosition;

    public:
        Lane(std::string direction, int number_of_sections_before_intersection);
        ~Lane();

        Section *firstSection;
        Section *lastSection;
        Section *currentSection;

        std::string getCurrentDirection();
        int getCurrentPosition();
        int getNumberOfSections();
        std::deque<Vehicle> laneQueue;

        void placeVehicle(Vehicle& vehicle);
        /*
        bool getCurrent();
        bool getFirst();
        bool getNext();
        bool getPrevious();
        bool getLast();
        */
    
        void add();
        void createLane(int number_of_sections_before_intersection);
        void reset();
        
        void linkFromIntersection(Intersection &inter, int number_of_sections_before_intersection);
        void linkToIntersection(Intersection &inter, int number_of_sections_before_intersection);

        void moveVehicle(Vehicle& vehicle);
        
};

#endif

