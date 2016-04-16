#ifndef __VECTOR_H__
#define __VECTOR_H__
#include<stdio.h>
#include <assert.h>
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
	Vector(unsigned int elements){
		capacity = elements;
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


	TYPE operator[](unsigned int index) const {
		assert(index <= num_elements)
			return	vector[index];
	}

	TYPE operator[](unsigned int index){
		assert(index <= num_elements)
			return	vector[index];
	}
	

	bool empty()const{
		if (num_elements == 0)
			return true;
		else
			return false;
	}

	void clean(){
		num_elements = 0;
	}
	unsigned int size(){
		return num_elements;
	}
	unsigned int get_capacity(){
		return capacity;
	}
	bool pop_back(TYPE& value){
		if (num_elements > 0){
			num_elements--;
			value = vector[num_elements];
			return true;
		}
		return false;
	}
	void shrink_to_fit(){
		capacity = num_elements;
		vector = new TYPE[capacity];
	}


	~Vector(){
		delete[]vector;
	}
};
#endif