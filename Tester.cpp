#include "Section.h"
#include "Lane.h"
#include "Intersection.h"
#include <iostream>

int main() {

    /*
    Lane northBound("northBound");
    Lane southBound("southBound");
    Lane eastBound("eastBound");
    Lane westBound("westBound");

    northBound.createLane(3);
    southBound.createLane(3);
    westBound.createLane(3);
    eastBound.createLane(3);

    std::cout << northBound.currentPosition << " [6]" << std::endl;
    std::cout << northBound.currentSection->freeToMoveRight() << " [0]" << std::endl;
    std::cout << northBound.currentSection->freeToMoveForward() << " [0]" << std::endl;
    std::cout << northBound.firstSection->freeToMoveRight() << " [0]" << std::endl;
    std::cout << northBound.firstSection->freeToMoveForward() << " [1]" << std::endl;

    northBound.reset();
    std::cout << northBound.currentPosition << " [1]" << std::endl;
    while(northBound.currentPosition != 4) {
        northBound.moveCurrent();
    }
    std::cout << northBound.currentPosition << " [4]" << std::endl;
    std::cout << northBound.currentSection->freeToMoveForward() << " [1]" << std::endl;
    std::cout << northBound.currentSection->freeToMoveRight() << " [0]" << std::endl;

    Intersection inter;
    std::cout << inter.one.isSectionOccupied() << " [0]" << std::endl;
    inter.one.forward->changeSectionOccupied(true);

    northBound.linkFromIntersection(inter, 3);
    std::cout << inter.two.isSectionOccupied() << " [1]" << std::endl;
    inter.two.forward->changeSectionOccupied(true);
    std::cout << inter.two.freeToMoveForward() << " [0]" << std::endl;
    inter.three.changeSectionOccupied(false);
    std::cout << inter.two.freeToMoveForward() << " [1]" << std::endl;

    
    northBound.linkToIntersection(inter, 3);
    std::cout << northBound.currentPosition << " [3]" << std::endl;
    std::cout << northBound.currentSection->forward->isSectionOccupied() << " [0]" << std::endl;
    inter.one.changeSectionOccupied(true);
    std::cout << northBound.currentSection->forward->isSectionOccupied() << " [1]" << std::endl;

    westBound.linkToIntersection(inter, 3);
    std::cout << westBound.currentPosition << " [3]" << std::endl;
    std::cout << westBound.currentSection->forward->isSectionOccupied() << " [1]" << std::endl;
    */

   Lane northBound("northBound", 3);
   Lane southBound("southBound", 3);
   Lane eastBound("eastBound", 3);
   Lane westBound("westBound", 3);

   Intersection intersection = Intersection();
   northBound.linkFromIntersection(intersection, 3);
   northBound.linkToIntersection(intersection, 3);
   southBound.linkFromIntersection(intersection, 3);
   southBound.linkToIntersection(intersection, 3);
   eastBound.linkFromIntersection(intersection, 3);
   eastBound.linkToIntersection(intersection, 3);
   westBound.linkFromIntersection(intersection, 3);
   westBound.linkToIntersection(intersection, 3);

   std::cout << northBound.currentPosition << std::endl;
   std::cout << northBound.currentSection->isSectionOccupied() << " [0]" << std::endl;
   std::cout << northBound.currentSection->forward->isSectionOccupied() << " [0]" << std::endl;
   intersection.one.changeSectionOccupied(true);
   std::cout << northBound.currentSection->forward->isSectionOccupied() << " [1]" << std::endl;

   std::cout << eastBound.currentPosition << std::endl;

   eastBound.reset();
   std::cout << eastBound.currentPosition << " [1]" << std::endl;
   for(int i=0; i<7; i++) {
       eastBound.moveCurrent(intersection, 3);
   }
   std::cout << eastBound.currentPosition << " [8]" << std::endl;
   if(eastBound.currentSection->forward == nullptr) {
       std::cout << "Nice" << std::endl;
   }
  




   
    



}
