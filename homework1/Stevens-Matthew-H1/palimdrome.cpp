#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

bool palindrome_check(vector <char> word1, string str){
	// c+ 3n/2
	vector<char> word2(str.begin(), str.end()); //c
	bool palindrome = false; //c1
	reverse(word2.begin(), word2.end()); //n/2
	if (word2 == word1){
		palindrome = true; //c1
		for(int i = 0; i < word1.size(); i++){ //n
			cout << word1.at(i); // c2
		}
	cout << " is a palindrome. " << endl; // c3
	}
	else{
		for(int i = 0; i < word1.size(); i++){ //n
			cout << word1.at(i); //c2
		}
		cout << " is not a palindrome." << endl; //c4
	}
	return palindrome; //c5
}

int main(int argc, char* argv[]){
	string str;
	char cont = 'y';
	int b = 1;
	int x;
	cout << "Do you want to enter in an empty string? 1 for yes 2 for no." << endl;
	cin >> x;
	/*if (x = 1){
		*str = NULL;
		vector <char> word1(str.begin(), str.end());
		palindrome_check(word1, str);
	}
	*/
	if(argc > 1){
		while(b < argc){
		str = argv[b];
		vector <char> word1(str.begin(), str.end());
		palindrome_check(word1, str);
		b += 1;
		}
	}
	while(cont == 'y'){
		cout << "Enter word: " << endl;
		cin >> str;
		vector<char> word1(str.begin(), str.end());
	palindrome_check(word1, str);

	cout << "Do you want to check another? (y/n)";
	cin >> cont;
	}

}
