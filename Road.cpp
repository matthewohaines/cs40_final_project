#ifndef __ROAD_CPP__
#define __ROAD_CPP__

#include "Road.h"


Road::Road(std::string direction, int numSectionsBeforeIntersection){
      this->direction = direction;
      this->numSectionsBeforeIntersection = numSectionsBeforeIntersection;
      std::list<Section> road;
      for (int i=0; i < numSectionsBeforeIntersection * 2 + 2; i++){
          Section newSection();
          road.push(newSection);
       }
} 

Road::~Road() {}


#endif
