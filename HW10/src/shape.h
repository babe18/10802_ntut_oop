#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class Shape {
public:
  virtual ~Shape(){
    // std::cout<<"Shape destructor called"<<std::endl;
  }

  virtual double area() const = 0; // pure virtual function
  virtual double perimeter() const = 0; // pure virtual function

  virtual std::string toString() const{
    return "";
  }

  std::string name() const {
    return _name;
  }

protected:
  Shape(std::string name):_name(name){}

private:
  std::string _name;
};


#endif
