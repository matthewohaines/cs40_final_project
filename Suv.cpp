#include "Suv.h"


Suv::Suv(std::string shapeName, double radVal)
	: Vehicle(shapeName), radius{radVal} {}

Suv::~Suv() {}

