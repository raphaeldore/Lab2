#include "dynamicArray.h"
#include <stdexcept>

DynamicArray::DynamicArray()
{
	this->capacite = 100;
	this->tabElements = new int[100](); // Initialise tous les éléments à 0
}

DynamicArray::DynamicArray(const unsigned int& _capacite)
{
	if (_capacite < 1)
		throw std::invalid_argument("Vous ne pouvez pas initialiser un tableau plus petit que 1");

	this->capacite = _capacite;
	this->tabElements = new int[_capacite]();
}

DynamicArray::DynamicArray(const DynamicArray& _dynamicArray)
{
	this->tabElements = new int[_dynamicArray.getCapacite()];
	this->capacite = _dynamicArray.getCapacite();

	for (int i = 0; i < _dynamicArray.getCapacite(); i++)
	{
		this->setElement(i, _dynamicArray.getElement(i));
	}
}

int DynamicArray::getCapacite() const
{
	return this->capacite;
}

int DynamicArray::getElement(const int& _index) const
{
	if (_index < 0 || _index >= this->getCapacite())
		throw std::out_of_range("Vous avez tenté d'accèder à un élément hors du tableau");

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
	if (_capacite < 1)
		throw std::invalid_argument("Vous ne pouvez pas redimensionner un tableau d'une capacité plus petite que 1");

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

DynamicArray& DynamicArray::operator=(const DynamicArray& _dynamicArray)
{
	// Vérifie si l'objet tente de s'assigner à lui même
	// Si oui, on arrête ici.
	if (this != &_dynamicArray)
	{
		if (this->getCapacite() != _dynamicArray.getCapacite()) // Si la capacité est la même, inutile de supprimer et d'allouer ensuite la même quantité... 
		{
			// On désalloue la mémoire du tableau
			delete[] this->tabElements;

			// On alloue de la mémoire pour contenir les éléments de _dynamicArray
			tabElements = new int[_dynamicArray.getCapacite()];
			this->capacite = _dynamicArray.getCapacite();
		}

		// On copie ensuite les valeurs de _dynamicArray
		for (int i = 0; i < _dynamicArray.getCapacite(); i++)
		{
			this->setElement(i, _dynamicArray.getElement(i));
		}
	}

	// Finalement on retourne une référence de soi-même
	return *this;
}

DynamicArray& DynamicArray::operator+=(const DynamicArray& _dynamicArray)
{
	DynamicArray dynamicArrayAAdditionner;
	if (&_dynamicArray == this) // Si on s'additionne soi-même
	{
		dynamicArrayAAdditionner = *this;
	}

	dynamicArrayAAdditionner = _dynamicArray;

	int capaciteDeDepart = this->getCapacite();
	for (int i = 0; i < dynamicArrayAAdditionner.getCapacite(); i++)
	{
		this->setElement(i + capaciteDeDepart, dynamicArrayAAdditionner.getElement(i));
	}

	return *this;
}

const DynamicArray DynamicArray::operator+(const DynamicArray& _dynamicArray) const
{
	DynamicArray resultat = *this;
	resultat += _dynamicArray;
	return resultat;
}

bool DynamicArray::operator==(const DynamicArray& _dynamicArray)
{
	if (this == &_dynamicArray) return true; // Si on se compare soi-même
	if (this->capacite != _dynamicArray.getCapacite()) return false;

	bool isEqual = true;

	for (int i = 0; i < this->getCapacite(); i++)
	{
		if (this->getElement(i) != _dynamicArray.getElement(i))
		{
			isEqual = false;
			break; // Pas besoin de regarder le reste, puisque au moins un élément n'est pas le même
		}
	}

	return isEqual;
}