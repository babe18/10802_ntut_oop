#ifndef SIZE_H
#define SIZE_H

#include "./style.h"

class Size : public Style{
public:
  Size(int h=0, int w=0):height(h), weight(w){}

  std::string renderStyle(){
    return "height:"+std::to_string(height)+"px;weight:"+std::to_string(weight)+"px;";
  }

private:
  int height, weight;
};

#endif
