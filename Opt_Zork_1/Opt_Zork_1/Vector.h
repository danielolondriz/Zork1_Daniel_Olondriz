#ifndef VECTOR
#define VECTOR
#include<assert.h>

template <class TYPE>
class Vector
{
private:
	TYPE* buffer;
	unsigned int capacity = 10;
	unsigned int num_elements = 0;
public:
	//EMPTY VECTOR
	Vector()
	{

		buffer = new TYPE[capacity];

	}
	Vector(const  Vector& vector)
	{
		num_elements = vector.num_elements;
		capacity = vector.capacity;
		buffer = new TYPE[capacity];
		for (unsigned int i = 0; i < num_elements; i++)
		{
			buffer[i] = vector.buffer[i];
		}


	}

	~Vector()
	{
	}

	void Push_back(const TYPE& vector)
	{

		TYPE* temp = nullptr;
		if (num_elements == capacity)
		{
			capacity *= 2;
			temp = new TYPE[capacity];
			for (int i = 0; i < capacity; i++)
			{
				*(temp + i) = *(buffer + i);
			}
			delete[]buffer;
			buffer = temp;
		}
		buffer[num_elements++] = vector;
	}
	void Push_front(const TYPE& vector)
	{

		TYPE* temp = nullptr;
		if (num_elements == capacity)
		{
			capacity *= 2;
			temp = new TYPE[capacity];
			for (int i = num_elements; i >= 0; i--)
			{
			*(temp + i+1) = *(buffer + i+1);
			}
			delete[]buffer;
			buffer = temp;
		}
		for (int i = num_elements; i >= 0; i--)
		{
			*(buffer + i + 1) = *(buffer + i);
		}
		*buffer = vector;
		num_elements++;
	}
	TYPE operator[](unsigned int word)const
	{
		assert(word < num_elements);
		return buffer[word];
	}
	TYPE operator[](unsigned int word)
	{
		assert(word < num_elements);
		return buffer[word];
	}
	unsigned int size()
	{
		return num_elements;
	}
	//empty();
	//clean();
	//size();
	//capacity();
	//pop_back();
	//shrink_to_fit();


};



#endif