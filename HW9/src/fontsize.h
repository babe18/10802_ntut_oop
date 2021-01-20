#ifndef FONTSIZE_H
#define FONTSIZE_H

#include "./style.h"

#include <cstring>

class FontSize : public Style{
public:
  FontSize(int s = 16):size(s){}

  std::string renderStyle(){
    return "font-size:"+std::to_string(size)+"px;";
  }

private:
  int size;
};

#endif
