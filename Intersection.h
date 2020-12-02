#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Section.h"

class Intersection {

    private:
        Section one;
        Section two;
        Section three;
        Section four;

        friend class Lane;

    public:
        Intersection();
        ~Intersection();
        void linkSections();
};

#endif
