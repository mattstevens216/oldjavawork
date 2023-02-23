/*************************************************************************************************************
 *Program: scissors.cpp
 *Author: Matthew Stevens
 *Date: 5/10/15
 *Description: scissors fight file
 *Input: N/A
 *Output: N/A
 *************************************************************************************************************/
#include "./scissors.h"
#include "./tool.h"

//default const.
scissors::scissors(){
   strength = 1;
   type = 's';
}

//nondefault const.
scissors::scissors(int s){
   strength = s;
   type = 's';
}

//scissors fight function
int scissors::fight(tool *t){
   if(t->getType() == 'p'){
      setStrength(2);
   }
   else if(t->getType() == 'r'){
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
