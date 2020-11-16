#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Section.h"

class Intersection {

    public:
        Section one;
        Section two;
        Section three;
        Section four;
        Intersection();
        ~Intersection();
        void linkSections();
};

#endif
