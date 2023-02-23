/*************************************************************************************************************
 *Program: tool.h
 *Author: Matthew Stevens
 *Date:5/10/15
 *Description: tool header file
 *Input: N/A
 *Output: N/A
 *************************************************************************************************************/
#ifndef TOOL_H
#define TOOL_H

class tool{
   protected:
      int strength;
      char type;
   public:
      tool();
      void otherStrength(int);
      void setStrength(int);
      int getStrength();
      void setType(char);
      char getType();
      virtual int fight(tool*) = 0;
      tool& operator=(const tool &g);
};
#endif
