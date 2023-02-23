/*************************************************************************************************************
 *Program: paper.cpp
 *Author: Matthew Stevens
 *Date: 5/10/15
 *Description:
 *Input:
 *Output:
 *************************************************************************************************************/
#include "./paper.h"
#include "./tool.h"

//default const.
paper::paper(){
   strength = 1;
   type = 'p';
}

//nondefault const.
paper::paper(int s){
   strength = s;
   type = 'p';
}

//paper fight
int paper::fight(tool *t){
   if(t->getType() == 'r'){
      setStrength(2);
   }
   else if(t->getType() == 's'){
      setStrength(0);
   }
   
   if(t->getStrength() < strength){
      return 0;
   }
   else if(t->getStrength() > strength){
      return 1;
   }
   else if(t->getStrength() == strength){
      return 2;
   }
}
