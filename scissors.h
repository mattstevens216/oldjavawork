/*************************************************************************************************************
 *Program: scissors.h
 *Author: Matthew Stevens
 *Date: 5/10/15
 *Description:
 *Input:
 *Output:
 *************************************************************************************************************/
#ifndef SCISSORS_H
#define SCISSORS_H
#include "./tool.h"

class scissors : public tool{
   
   public:
      scissors();
      scissors(int);
      int fight(tool *t);
};
#endif
