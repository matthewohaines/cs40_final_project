#ifndef __VEHICLE_H__
#define __VEHICLE_H__

enum class VehicleType {car, suv, truck};
enum class Direction {north, south, east, west};
enum class IntendedTurn {forward, right};

class Vehicle {

    public:
        static int vehicleCount;
        Vehicle(VehicleType type, Direction initialDirection, IntendedTurn intendedTurn);
        Vehicle(const Vehicle& other);
        ~Vehicle();
        int getVehicleID();
        VehicleType getVehicleType();
        Direction getVehicleInitialDirection();
        IntendedTurn getIntendedTurn();

    private:
        int vehicleID;
        VehicleType vehicleType;
        Direction vehicleDirection;
        IntendedTurn intendedTurn;
        int position;
        
};

#endif