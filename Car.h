#ifndef __Car_H__
#define __Car_H__

#include "Vehicle.h"

class Car : public Vehicle 
{
	private:
		

	public:
		Car(std::string shapeName, double radVal);
		~Car();

};

#endif