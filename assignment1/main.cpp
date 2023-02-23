
// main.cpp
//Tests all functionality of the My_vec class.

#include <iostream>
#include <stdexcept>
#include "My_vec.h"

using namespace std;

int main(){
try{
	My_vec<char> v;
	// define an object v of My_vec type
	// insert 'B' at the rank 0 into the vector v
        v.insert_at_rank(0,'B');
    	// use the overloaded operator << to display vector elements
	cout << "insert 0, b, Elements of Vector: " << v << endl;
    	// display the vector v size
	cout << "the vector size is: " << v.get_size() << endl;
	// insert 'A' at the rank 0 into the vector v
        v.insert_at_rank(0,'A');
	// use the overloaded operator << to display vector elements
	cout << "INSERT 0,a, Elements of Vector: " << v << endl;
	// display the vector v size
	cout << "the vector size is: " << v.get_size() << endl;
	// insert 'D' at the rank 10 into the vector v
        v.insert_at_rank(10,'D');
	// use the overloaded operator << to display vector elements
	cout << "insert 10, d, Elements of Vector:   " << v << endl;
	// display the vector v size
	cout << "the vector size is: " << v.get_size() << endl;
	// remove a character at the rank 2 from the vector v
	v.remove_at_rank(2);
	// use the overloaded operator << to display vector elements
	cout << "remove rank 2, Elements of Vector:     " << v << endl;
	// display the vector v size
	cout << "the vector size is: " << v.get_size() << endl;
	// replace a character at the rank 2 by the character 'E' 
	v.replace_at_rank(2, 'E');
	// use the overloaded operator << to display vector elements
	cout << "replace 2, E,3Elements of Vector: 1    " << v << endl;
	// display the vector v size	
	cout << "the vector size is:    " << v.get_size() << endl;
	// create a copy v1 of the vector v using a copy constructor
	My_vec<char> v1(v);
	// use the overloaded operator << to display the vector v1
	cout << "COPY V TO V1, the vector size is: " << v1.get_size() << endl;
	cout << "Elements of Vector:      " << v1 << endl;
    	// replace a character at the rank 2 of the vector v1 with the character 'Y'
	v1.replace_at_rank(2, 'Y');
	// use the overloaded operator << to display vector v1 elements
	cout << "REPLACE 2, Y, the vector size is:      " << v1.get_size() << endl;
	cout << "Elements of Vector:     " << v1 << endl;
	// define an object v2 of My_vec type
	My_vec<char> v2;
	// insert 'K' at the rank 0 into the vector v2
	v2.insert_at_rank(0, 'K');
	// use the overloaded operator << to display vector elements
	cout << "INSERT 0, K, the vector size is:   " << v2.get_size() << endl;
	cout << "Elements of Vector:    " << v2 << endl;
    	// display the vector v2 size
	cout << "the vector size is: " << v2.get_size() << endl;
    	// test the assignment operator and copy the vector v1 to v2 
	v2 = v1;	
    	// use the overloaded operator << to display vector v2
	cout << "COPY V1 TO V2, Elements of Vector: 3     " << v2 << endl;
    	// display the vector v2 size
	cout << "the vector size is: " << v.get_size() << endl;
    	// test the function find_max_index using v2
	cout << "the max index is: " << find_max_index(v2, v2.get_size()) << endl;
	// test the function sort_max using v2
 	//sort_max(v2);
	// replace in the vector v2 a character at the rank 14 with 'S'
	v2.replace_at_rank(14, 'S');
}

catch(exception &error){
	cerr << "Error: " << error.what() << endl;
}
}
