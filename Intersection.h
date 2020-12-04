#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Section.h"

class Intersection : public Section {
    private:
        Section *intersectionOne;
        Section *intersectionTwo;
        Section *intersectionThree;
        Section *intersectionFour;

    public:
        Intersection();
        ~Intersection(){}

        Section *getForward() override;
        Section *getPrevious() override;
        Section *getRight();
        Section *getIntersectionOne();
        Section *getIntersectionTwo();
        Section *getIntersectionThree();
        Section *getIntersectionFour();

        void setIntersectionOne(Section *one);
        void setIntersectionTwo(Section *two);
        void setIntersectionThree(Section *three);
        void setIntersectionFour(Section *four);
};

#endif
