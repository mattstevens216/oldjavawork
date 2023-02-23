/*************************************************************************************************************
 *Program: tool.cpp
 *Author: Matthew Stevens
 *Date:5/10/15
 *Description: tool functions
 *Input: N/A
 *Output: N/A
 *************************************************************************************************************/
#include "tool.h"

//changes the strengths of the tool
void tool::otherStrength(int i){
   if(i == 2){
    strength = strength * 2;
   }
   else if(i == 0){
      strength = strength / 2;
   }
}

//default const.
tool::tool(){
 strength = 0;
 type = 0;
}

//sets strength that user inputs
void tool::setStrength(int t){
   strength = t;
}

//gets the strength
int tool::getStrength(){
   return strength;
}

//sets the type of tool
void tool::setType(char c){
   type = c;
}

//gets the type of tool
char tool::getType(){
   return type;
}

//operator overload
tool& tool::operator=(const tool &g){
   type = g.type;
   strength = g.strength;
}
