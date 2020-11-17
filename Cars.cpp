#ifndef __CARS_CPP__
#define __CARS_CPP__

#include "Lane.h"
#include "Section.h"
#include "Intersection.h"
#include "Cars.h"


Cars::Cars(int idNum, int len)
{
	this->idNumber = idNum;
	this->length = len;
}

Cars::~Cars(){}

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