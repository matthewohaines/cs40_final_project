#ifndef __INTERSECTION_CPP__
#define __INTERSECTION_CPP__

#include "Intersection.h"
#include "Section.h"

Intersection::Intersection() {

    this->one = Section();
    this->two = Section();
    this->three = Section();
    this->four = Section();
    linkSections();
}

Intersection::~Intersection() {}

void Intersection::linkSections() {

    one.setForward(two);
    two.setForward(three);
    three.setForward(four);
    four.setForward(one);
}

#endif