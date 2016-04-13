#ifndef __VECTOR_H__
#define __VECTOR_H__
#include<stdio.h>

#define BASE_CAPACITY 5

template<class TYPE>

class Vector{
private:
	TYPE *vector;
	unsigned int capacity = BASE_CAPACITY;
	unsigned int num_elements=0;


public:
	Vector(){
		vector = new TYPE[capacity];
	}
	Vector(const Vector& otherclas){
		capacity = otherclas.capacity;
		num_elements = otherclas.num_elements;
		vector = new TYPE[capacity];
		for (unsigned int 0; i < num_elements; i++){
			vector[i] = otherclas.vector[i];
		}
		
	}
	
	//metode pushback, pushfront
	void pushback(const TYPE& item){
		if (num_elements == capacity){
			TYPE* temp;	
			capacity += BASE_CAPACITY;
			temp =  new TYPE[capacity];
			for (int i = 0; i < num_elements; i++){
				temp[i] = vector[i];
			}
			delete[] vector;
			vector = temp;
		}
		*(vector +(num_elements++)) = item;
	}

	void pushfront(const TYPE item){
		if (capacity == num_elements){
			capacity += BASE_CAPACITY;
			TYPE* temp;
			temp = new TYPE[capacity];
			for (int i = 0; i < num_elements; i++){
				temp[i] = vector[i];
			}
			delete[] vector;
			vector = temp;
		}

		for (int i = num_elements; i >= 0; --i){
			vector[i+1] = vector[i];
		}
		*(vector) = item;
		++num_elements;
	}


	TYPE operator[](const int index){
		return	vector[index];
	}
	

	bool empty()const{
		for (int i = 0; i < capacity; i++){
			if (vector[i] != NULL){
				return false;
			}
		}
		return true;
	}



	~Vector(){
		delete[]vector;
	}
};
#endif