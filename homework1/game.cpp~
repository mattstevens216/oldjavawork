#include <iostream>
#include <stdexcept>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

bool check_if_correct(int &guess, int &number){
	if(guess == number)
		return true;
	else return false;
}

int random_computer_guess(int &guess, int &lowerbound, int &upperbound){
	srand(time(NULL));
	guess = rand()%32;
   	while(guess < lowerbound || guess > upperbound){
	guess = rand()%32;
	}
	return guess;
}

int computer_number(int &number){
	srand(time(NULL));
   	number = rand()%32;
	return number;
}

int player_pick(int &number, int &upperbound){
	cout << "input a number between 1 and " << upperbound <<  endl; 
	cin >> number;
	if(number < 0 || number > upperbound){
		cout << "you have entered an invalid guess, please guess within the parameters" << endl;
		player_pick(number, upperbound);
	}
   	return number;
}
	
int player_guess(int &guess, int &lowerbound, int &upperbound){
		cout << "guess a number between " << lowerbound << " and " << upperbound << endl;
		if(upperbound == 33) 
			upperbound = upperbound-1;
		if(lowerbound == 33) 
			lowerbound = lowerbound-1;
	cin >> guess;
	while(guess < lowerbound || guess > upperbound){
		cout << "you have entered an invalid guess, please guess within the parameters" << endl;
		cin >> guess;
	}
	return guess;
}	

int computer_guess(int &range, int &lowerbound, int &guess, int &upperbound, int &proximity){
	if(range == 1){
		guess = lowerbound;
		return guess;
	}
	else if (upperbound == lowerbound){
		guess = lowerbound;
		return guess;
	}
	else if (proximity == 1){
		if (range == 0)
			guess = lowerbound;
		else if (range != 0)
			guess = (range/2) + lowerbound;
		return guess;
		}
	else if (proximity == 2){
		if (range == 0)
			guess = lowerbound;
		else if(range != 0)
			guess = (range/2) + lowerbound;
	return guess;
	}
	else {
		guess = range / 2;
		return guess;
	}
}
int main(){
	int proximity, i, z, x, guess, number, upperbound, lowerbound, range;	
	cout << "who do you want to guess the number? 1-player guesses 1-32, 2-computer randomizes a number and guesses it, 3- computer guesses player number via algorithm: " << endl;
	cin >> x;
	lowerbound = 1;
	upperbound = 32;
	range = 1;
/*	if(x==1){
		player_pick(number, upperbound);
		for(z = 0; z < 6; z++){
			random_computer_guess(lowerbound, guess, upperbound);
			check_if_correct(guess, number);
			if(guess > number){
				cout << "the computer guessed: " << guess << endl;
				cout << "lower" << endl;
				upperbound = guess;
			}
			if(guess < number){
				cout << "the computer guessed: " << guess << endl;
				cout << "higher" << endl;
				lowerbound = guess+1;
			}
			if(check_if_correct(guess, number)){
				cout << "the computer guessed: " << guess << endl;
				cout << "correct!" << endl;
				break;
			}
			cout << "you didn't guess the number in " << z << " tries! " << endl;
		}
*/
	if(x==1){
		computer_number(number);
		for(z = 1; z < 7; z++){
			player_guess(guess, lowerbound, upperbound);
			check_if_correct(guess, number);
			if(guess > number){
				cout << "the player guessed: " << guess << endl;
				cout << "lower" << endl;
					upperbound = guess;
			}
			if(guess < number){
				cout << "the player guessed: " << guess << endl;
				cout << "higher" << endl;
					lowerbound = guess+1;
			}
			if(check_if_correct(guess, number)){
				cout << "the player guessed: " << guess << endl;
				cout << "correct!" << endl;
				break;
			}
			cout << "you guessed " << z << " times! " << endl;
		}
	}
	
	if(x==2){
		proximity = 0;
		lowerbound = 1;
		range = 0;
		cout << "enter the upperbound you would like to have: " << endl;
		cin >> upperbound;
		srand(time(NULL));
		number = rand()% upperbound+1;
		for(int b=1; b > 0; b++){
			computer_guess(range, lowerbound, guess, upperbound, proximity);
			check_if_correct(guess, number);
			if(guess > number){
				cout << "the computer guessed: " << guess << endl;
				cout << "lower" << endl;
					upperbound = guess;
					proximity = 1;
			}
			if(guess < number){
				cout << "the computer guessed: " << guess << endl;
				cout << "higher" << endl;
					lowerbound = guess+1;
					proximity = 2;
			}
			if(check_if_correct(guess, number)){
				cout << "the compuer guessed: " << guess << endl;
				cout << "correct!" << endl;
				break;
			}
			cout << "the computer guessed " << b << " times!" << endl;

			range = upperbound - lowerbound;
		}
	}
	if(x==3){
		proximity = 0;
		lowerbound = 1;
		range = 0;
		srand(time(NULL));
		cout << "enter the upperbound you would like to have: " << endl;
		cin >> upperbound;
		player_pick(number, upperbound);
		for(int b=1; b > 0; b++){
			computer_guess(range, lowerbound, guess, upperbound, proximity);
			check_if_correct(guess, number);
			if(guess > number){
				cout << "the computer guessed: " << guess << endl;
				cout << "lower" << endl;
					upperbound = guess;
					proximity = 1;
			}
			if(guess < number){
				cout << "the computer guessed: " << guess << endl;
				cout << "higher" << endl;
					lowerbound = guess+1;
					proximity = 2;
			}
			if(check_if_correct(guess, number)){
				cout << "the compuer guessed: " << guess << endl;
				cout << "correct!" << endl;
				break;
			}
			cout << "the computer guessed " << b << " times!" << endl;

			range = upperbound - lowerbound;
		}
	}	
	return 0;
}
