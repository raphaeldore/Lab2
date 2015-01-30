#include "dynamicArray.h"

DynamicArray::DynamicArray()
{
	this->capacite = 100;
	this->tabElements = new int[100]();
}

int DynamicArray::getCapacite() const
{
	return this->capacite;
}

int DynamicArray::getElement(const int& _index) const
{
	return this->tabElements[_index];
}

void DynamicArray::setElement(const unsigned int _index, const int _valeur)
{
	this->tabElements[_index] = _valeur;
}