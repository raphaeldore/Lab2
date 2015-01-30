#ifndef DYNAMICARRAY_H_
#define DYNAMICARRAY_H_

class DynamicArray
{

public:
	DynamicArray();

	int getCapacite();
	int getElement(int i);


private:
	unsigned int capacite;
	int * tabElements;
};


#endif //DYNAMICARRAY_H_