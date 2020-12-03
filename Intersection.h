#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Section.h"

class Intersection : public Section {

    private:
        Section *north;
        Section *south;
        Section *west;
        Section *east;

    public:
        Intersection();
        Intersection(const Intersection &other);
        ~Intersection();

        Section *getForward() override;
        Section *getPrevious() override;
        Section *getRight();

        inline Section *getNorth() {return north;}
        inline Section *getSouth() {return south;}
        inline Section *getWest() {return west;}
        inline Section *getEast() {return east;}
        inline Section *setNorth(Section *north){return this->north = north;}
        inline Section *setSouth(Section *south){return this->south = south;}
        inline Section *setWest(Section *west){return this->west = west;}
        inline Section *setEast(Section *east){return this->east = east;}
};

#endif
