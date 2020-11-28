#ifndef __SECTION_H__
#define __SECTION_H__

class Section {

    private:
        bool sectionOccupied;

        
    public:
        Section *forward;
        Section *right;
        Section();
        ~Section();

        bool getSectionOccupied();
        void setSectionOccupied(bool value);
        bool getForwardSectionOccupied();
        void setForward(Section &next);
        void setRight(Section &next);

        friend class Lane;


};

#endif