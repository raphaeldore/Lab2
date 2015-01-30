#include "dynamicArray.h"

DynamicArray::DynamicArray()
{
	this->capacite = 100;
	this->tabElements = new int[100]();
}

int DynamicArray::getCapacite()
{
	return this->capacite;
}

int DynamicArray::getElement(int i)
{
	return this->tabElements[i];
}