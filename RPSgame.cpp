/*************************************************************************************************************
 *Program: RPSgame.cpp
 *Author: Matthew Stevens
 *Date: 5/10/15
 *Description: contains constructors and other functions for RPS
 *Input: N/A
 *Output: N/A
 *************************************************************************************************************/
#include "RPSgame.h"

//default const.
RPSgame::RPSgame(){
   p = NULL;
   com = NULL;
   humanWins = 0;
   comWins = 0;
   ties = 0;
   HS = 1;
   CS = 1;
}

//nondefault const.
RPSgame::RPSgame(const RPSgame &g){
   p = g.p;
   com = g.com;
   humanWins = g.humanWins;
   comWins = g.comWins;
   ties = g.ties;
};

//destruct
RPSgame::~RPSgame(){
   delete p;
   delete com;
   p = NULL;
   com = NULL;
}

//operator overload
RPSgame& RPSgame::operator=(const RPSgame &g){
   p = g.p;
   com = g.com;
   humanWins = g.humanWins;
   comWins = g.comWins;
   ties = g.ties;
}

//player chooses his tool
void RPSgame::pChoose(){
   char q;
   cout << "Choose your tool(r-rock, p-paper, s-scissors, e-exit):" << endl;
   cin >> q;
   if(q == 'e'){
      exit(0);
   }
   else if(q == 'r'){
      p = new rock(HS);
      cout << "You chose Rock." << endl;
   }
   else if(q == 'p'){
      p = new paper(HS);
      cout << "You chose Paper." << endl;
   }
   else if(q == 's'){
      p = new scissors(HS);
      cout << "You chose Scissors." << endl;
   }
}

//com chooses his tool
void RPSgame::comChoose(){
   int w;
   srand(time(NULL));
   w = rand()%3;
   if(w == 0){
      com = new rock(CS);
      cout << "Computer chose Rock." << endl;
   }
   else if(w == 1){
      com = new paper(CS);
      cout << "Computer chose Paper." << endl;
   }
   else if(w == 2){
      com = new scissors(CS);
      cout << "Computer chose Scissors." << endl;
   }
}

//compares tool weights to see who won
void RPSgame::whoWins(){
   if(p->fight(com) == 0){
      cout << "A winner is you." << endl;
      humanWins += 1;
   }
   else if(p->fight(com) == 1){
      cout << "Ya got REKT!" << endl;
      comWins += 1;
   }
   else{
      cout << "It is a tie." << endl;
      ties += 1;
   }
}

//prints who won how many times
void RPSgame::printScore(){
   cout << "Human wins: " << humanWins << endl;
   cout << "Computer wins: " << comWins << endl;
   cout << "Ties: " << ties << endl;
}

//changes the strength of the tools
void RPSgame::strengthChange(){
   char e;
   cout << "Do you want to choose different strengths for the tools? (y-yes, n-no): " << endl;
   cin >> e;
   if(e == 'y'){
      cout << "What is the human tool\'s new strength?(Please enter an int): " << endl;
      cin >> HS;
      cout << "What is the computer tool\'s new strength?(Please enter an int): " << endl;
      cin >> CS;
   }
}

//keeps the game running
void RPSgame::go(){
   bool r = true;
   strengthChange();
   while(r){
      pChoose();
      comChoose();
      whoWins();
      printScore();
   }
}
