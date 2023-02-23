/*************************************************************************************************************
 *Program: rock.cpp
 *Author: Matthew Stevens
 *Date: 5/10/15
 *Description:
 *Input:
 *Output:
 *************************************************************************************************************/
#include "./rock.h"
#include "./tool.h"

//default const.
rock::rock(){
   strength = 1;
   type = 'r';
}

//nondefault const.
rock::rock(int s){
   strength = s;
   type = 'r';
}

//fight function
int rock::fight(tool *t){
   if(t->getType() == 's'){
      setStrength(2);
   }
   else if(t->getType() == 'p'){
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
