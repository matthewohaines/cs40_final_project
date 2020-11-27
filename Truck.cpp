#include "truck.h"


Truck::Truck(std::string shapeName, double radVal)
	: Vehicle(shapeName), radius{radVal} {}

Truck::~Truck() {}

