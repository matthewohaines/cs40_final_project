#ifndef __ROAD_H__
#define __ROAD_H__

#include "Vehicle.h"
#include "Section.h"
#include <list>
#include <string>

class Road{
    private:
        std::string direction;
        int numSectionsBeforeIntersection;
    public:
        Road(std::string direction, int numSectionsBeforeIntersection);
        ~Road();

};

#endif
