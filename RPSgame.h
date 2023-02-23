/*************************************************************************************************************
 *Program: RPSgame.h
 *Author: Matthew Stevens
 *Date: 5/10/15
 *Description: Header file for the game
 *Input: N/A
 *Output: N/A
 *************************************************************************************************************/
#ifndef RPSGAME_H
#define RPSGAME_H

#include "tool.h"
#include "rock.h"
#include "paper.h"
#include "scissors.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

class RPSgame{
   private:
      tool* p;
      tool* com;
      int humanWins;
      int comWins;
      int ties;
      int HS;
      int CS;
   public:
      RPSgame();
      RPSgame(const RPSgame &g);
      ~RPSgame();
      RPSgame& operator=(const RPSgame &g);
      void pChoose();
      void comChoose();
      void whoWins();
      void printScore();
      void strengthChange();
      void reset();
      void go();
};
#endif
