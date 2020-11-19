#ifndef __CARS_H__
#define __CARS_H__

#include "Section.h"
#include "Intersection.h"

#include <string>

class Cars {

    private:
        int idNumber;
        int length;
        static int numCars;

    public:
        Cars(int idNum, int len);
        ~Cars();
        void moveOne();
        void turnRight();
        int getIDNumber();
        void setIDNumber();
        int getLength();
        void setLength();
        void increaseNumberCars();

};

#endif
