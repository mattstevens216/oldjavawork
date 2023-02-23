/*************************************************************************************************************
 *Program: paper.h
 *Author: Matthew Stevens
 *Date: 5/10/15
 *Description:
 *Input:
 *Output:
 *************************************************************************************************************/
#ifndef PAPER_H
#define PAPER_H
#include "./tool.h"

class paper : public tool{
   
   public:
      paper();
      paper(int);
      int fight(tool *t);
};
#endif
