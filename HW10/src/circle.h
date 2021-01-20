#ifndef CIRCLE_H
#define CIRCLE_H

#include "vector.h"
#include "shape.h"

#include <math.h>
#include <string>
#include <sstream>


class Circle : public Shape {
public:

  Circle(double r, std::string name = "anonymous", Vector origin = Vector(2))
  :Shape(name), _r(r), _origin(origin){}

  ~Circle() override{
    // std::cout<<"Circle destructor called"<<std::endl;
  }

  double area() const override{
    return M_PI * _r * _r;
  }

  double perimeter() const override{
    return 2 * M_PI * _r;
  }

  std::string toString() const override{
    std::stringstream ss;
    ss << "circle {\n"
       << name() << "\n"
       << _origin.toString() << "\n"
       << _r << "\n"
       << "}\n";
    return ss.str();
  }


private:
  double _r;
  Vector _origin;

};

#endif
