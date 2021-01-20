#ifndef COLOR_H
#define COLOR_H

#include"style.h"

#include<cstring>

class Color : public Style{
public:
  Color(std::string c = "#000000"):color(c){}

  std::string renderStyle(){
    return "color:" + color + ";";
  }

private:
  std::string color;
};

#endif
