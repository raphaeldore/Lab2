#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

class DynamicArray
{

public:
	DynamicArray();

	int getCapacite() const;
	int getElement(const int & _index) const;
	void setElement(const unsigned int _index, const int _valeur);


private:
	unsigned int capacite;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_