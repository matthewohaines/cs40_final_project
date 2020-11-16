#ifndef __SECTION_H__
#define __SECTION_H__

class Section {

    private:
        bool sectionOccupied;
        
    public:
        Section();
        ~Section();

        Section *forward;
        Section *right;

        bool isSectionOccupied();
        void changeSectionOccupied(bool value);  
        bool freeToMoveForward();
        bool freeToMoveRight();
};

#endif