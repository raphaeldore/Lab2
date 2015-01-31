#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

class DynamicArray
{
public:
	DynamicArray();
	DynamicArray(const unsigned int & _capacite);
	DynamicArray(const DynamicArray & _dynamicArray);

	int getCapacite() const;
	int getElement(const int & _index) const;
	void setElement(const unsigned int _index, const int _valeur);
	void setCapacite(const unsigned int _capacite);

	DynamicArray& operator=(const DynamicArray & _dynamicArray);
	bool operator==(const DynamicArray & _dynamicArray);

private:
	unsigned int capacite;
	int * tabElements;
};

#endif //DYNAMICARRAY_H_