#include <string>
#include <vector>
#include "Vehicle.h"
#include <iostream>

int main() {
std::vector<Vehicle*> northlane(23);
std::vector<Vehicle*> southlne(23);
std::vector<Vehicle*> eastlane(23);
std::vector<Vehicle*> westlane(23);
 

int count = 0; 
if (count == 0){
Vehicle newCar(VehicleType::car, Direction::north, IntendedTurn::right);
northlane[0] = &newCar;
northlane[1] = &newCar;
count++;
} 
if (count == 1){
Vehicle newCar(VehicleType::car, Direction::north, IntendedTurn::right);
northlane[3] = &newCar;
northlane[4] = &newCar;
count++;
}
if (count == 2){
Vehicle newCar(VehicleType::car, Direction::north, IntendedTurn::right);
northlane[8] = &newCar;
northlane[9] = &newCar;
northlane[10] = &newCar;
}
int time = 0;
while (time < 10){
for (int i = 22; i >= 0; i--){
   if (i<22 && i == 10){
    eastlane[i+1] = northlane[i];
    northlane[i] = nullptr;
   } 
   if (i<22 && northlane[i] != nullptr){
   if (northlane[i+1] == nullptr){
   northlane[i+1] = northlane[i];
   northlane[i] = nullptr;
   std::cout << i << ": " <<  northlane[i+1]->getVehicleID() << std::endl;
   }
   }
   else{
   std::cout << i << ": " << "NULL" << std::endl;
   }
}
time++;
}

return 0;

}

