/*************************************************************************************************************
 *Program: rock.h
 *Author: Matthew Stevens
 *Date: 5/10/15
 *Description: rock header file
 *Input: N/A
 *Output: N/A
 *************************************************************************************************************/
#ifndef ROCK_H
#define ROCK_H
#include "./tool.h"

class rock : public tool{ 
   public:
      rock();
      rock(int);
      int fight(tool *t);
};
#endif
