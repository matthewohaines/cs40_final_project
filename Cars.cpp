#ifndef __CARS_CPP__
#define __CARS_CPP__

#include "Lane.h"
#include "Section.h"
#include "Intersection.h"
#include "Cars.h"
#include <stdlib.h>


Cars::Cars(int idNum, int len, Lane *theLane)
{
	this->idNumber = numCars;
	increaseNumberCars();
	this->length = len;
	this->sectionOne = theLane.firstSection;

}

Cars::Cars()
{
	rseed = rand() % 4 + 2;
	this->length = rseed;
	rseed = rand() % 1000 + 1;
	this->idNumber = rseed;
	increaseNumberCars();
}

Cars::~Cars(){}

void Cars::increaseNumberCars()
{
	numCars++;
	return;
}

void Cars::moveOne()
{
	return;
}

void Cars::TurnRight()
{
	return;
}

int Cars::getIDNumber()
{
	return this->idNumber;
}

void Cars::setIDNumber(int idNum)
{
	this->idNumber = idNum;
	return;
}

int Cars::getLength()
{
	return this->length;
}

void Cars::setLength(int len)
{
	this->length = len;
	return;
}

#endif