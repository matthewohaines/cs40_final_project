#ifndef __SECTION_CPP__
#define __SECTION_CPP__

#include "Section.h"

Section::Section() {

    this->sectionOccupied = false;
    this->forward = nullptr;
    this->right = nullptr;
}

Section::~Section() {}

bool Section::isSectionOccupied() {

    return this->sectionOccupied;
}

void Section::changeSectionOccupied(bool value) {

    this->sectionOccupied = value;
}

bool Section::freeToMoveForward() {

    if(this->forward == nullptr) {
        return false;
    }
    if(forward->isSectionOccupied() == true) {
        return false;
    }
    return true;
}
bool Section::freeToMoveRight() {
    
    if(this->right == nullptr) {
        return false;
    }
    if(right->isSectionOccupied() == true) {
        return false;
    }
    return true;
}

#endif