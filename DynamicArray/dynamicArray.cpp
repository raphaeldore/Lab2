#include "dynamicArray.h"

DynamicArray::DynamicArray()
{
	this->capacite = 100;
	this->tabElements = new int[100](); // Initialise tous les éléments à 0
}

DynamicArray::DynamicArray(const unsigned int& _capacite)
{
	this->capacite = _capacite;
	this->tabElements = new int[_capacite]();
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
	if (_index > this->capacite - 1)
	{
		this->setCapacite(_index + 1);
	}

	this->tabElements[_index] = _valeur;
}

void DynamicArray::setCapacite(const unsigned int _capacite)
{
	if (this->capacite != _capacite)
	{
		int * vieuxTableau = this->tabElements;
		int * nouveauTableau = new int[_capacite]();

		unsigned int tmpCapacite = this->capacite;
		if (this->capacite > _capacite)
		{
			tmpCapacite = _capacite;
		}

		for (unsigned int i = 0; i < tmpCapacite; i++)
		{
			nouveauTableau[i] = vieuxTableau[i];
		}

		tabElements = nouveauTableau;
		this->capacite = _capacite;

		delete[] vieuxTableau;
	}

}