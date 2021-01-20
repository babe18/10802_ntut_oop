#ifndef POSITION_H
#define POSITION_H

#include"./style.h"

#include<cstring>

class Position : public Style{
public:
  Position(int top = 0, int left = 0):top(top),left(left){}

  std::string renderStyle(){
    return "top:"+std::to_string(top)+"px;left:"+std::to_string(left)+"px;position:absolute;";
  }

private:
  int top, left;
};

#endif
