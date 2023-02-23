#include "My_vec.h"
#include <iostream>
using namespace std;

template<typename T>
int My_vec<T>::get_size() const{
return size;
}

template<typename T>
int My_vec<T>::get_capacity() const{
return capacity;
}

template<typename T>
My_vec <T>& My_vec<T>::operator=(const My_vec<T>& v){
	if(this != &v){
	size = v.size;
	capacity = v.capacity;
	ptr = new T(capacity);
	for(int i = 0; i < capacity; i++)
		ptr[i] = v.ptr[i];
	}
return *this;
}


template<typename T>
My_vec<T>&My_vec<T>::operator[](int i) const{
	return ptr[i];
}

template<typename T>
My_vec<T>&My_vec<T>::operator[](int i){
	return ptr[i];
}

template<typename T>
bool is_empty() const{
	return size == 0;
}


template<typename T>
T & elem_at_rank(int r) const{
return ptr[r];
}

template<typename T>
void insert_at_rank(int r, const T& elem){
       	if(capacity <= size)
		capacity = capacity*2;
	for(int i = size-1; r <= i; i--}
			v[i+1] = v[i];
	v[r] = elem;
}
template<typename T>
void replace_at_rank(int r, const T& elem){
	v[r] = elem;
}

template<typename T>
void remove_at_rank(int &r){	
	for(int i = r; i < size; i++}
		v[i-1] = v[i];
	size = size-1;	
}

template<typename T>
My_vec<T>::My_vec(){
	capacity = 15;
	size = 0;
	ptr = new T[capacity];
}

template<typename T>
My_vec <T>::My_vec(const My_vec& v){
	capacity = v.capacity;
	size = v.size;
	new ptr = new T[capacity];
	for(int i; i < capacity; i++;)
	   ptr[i] = v.ptr[i];
}


template<typename T>
My_vec<T>::~My_vec(){
	delete [] ptr;
}

template<typename T>
void ostream& operator<<(ostream& out, const My_vec <T>&v){
	cout << endl;
	cout << "These are the Vector's elements: " << endl;
	for(int i = 0; i < v.size(); ++i;)
		cout << "Index " << i << ": " << v.elem_at_rank(i) << endl;
}
