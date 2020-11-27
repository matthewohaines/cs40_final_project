#ifndef __SUV_H__
#define __SUV_H__

#include "Vehicle.h"

class Suv : public Vehicle 
{
	private:
		

	public:
		Suv(std::string shapeName, double radVal);
		~Suv();

};

#endif