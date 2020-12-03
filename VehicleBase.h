#ifndef __VEHICLEBASE_H__
#define __VEHICLEBASE_H__

enum class VehicleType {car, suv, truck};
enum class Direction {north, south, east, west};
enum class LightColor {red, yellow, green};

class VehicleBase {

    public:
        VehicleBase(VehicleType type, Direction initialDirection);
        VehicleBase(const VehicleBase& other);
        virtual ~VehicleBase();

        static int vehicleCount;

        inline int getVehicleID() const { return this->vehicleID; }
        inline VehicleType getVehicleType() const { return this->vehicleType; }
        inline Direction getVehicleOriginalDirection() const { return this->vehicleDirection; }
        inline void changeDirection(Direction direction) {vehicleDirection = direction;}

    protected:
        int vehicleID;
        VehicleType vehicleType;
        Direction vehicleDirection;
        
        
};

#endif