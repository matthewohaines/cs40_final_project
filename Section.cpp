#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"

Section::Section() {

    this->sectionOccupied = false;
    this->forward = nullptr;
    this->right = nullptr;
}

Section::~Section() {}

bool Section::getSectionOccupied() {

    return this->sectionOccupied;
}

void Section::setSectionOccupied(bool value) {

    this->sectionOccupied = value;
}

bool Section::getForwardSectionOccupied() {

    return this->forward->getSectionOccupied();
}

void Section::setForward(Section &next) {

    this->forward = &next;
}

void Section::setRight(Section &next) {

    this->right  = &next;
}

#endif