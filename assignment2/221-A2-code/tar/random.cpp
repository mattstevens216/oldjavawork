#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>

using namespace std;

int main() {
	int number = 0;
	srand(time(NULL));
 	ofstream myfile;
	myfile.open ("input.txt", ios::out);
	if (myfile.is_open()){
		for(int i = 0; i < 1000; i++){
			number = rand()%1000;
			myfile << number << "\r\n";
		}
	myfile.close();
	}
	else cout << "could not open file." << endl;
	return 0;
}
