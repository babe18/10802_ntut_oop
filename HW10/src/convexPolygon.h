#ifndef CONVEXPOLYGON_H
#define CONVEXPOLYGON_H

#include "./shape.h"
#include "./vector.h"

#include <vector>
#include <sstream>

class ConvexPolygon : public Shape{
public:

  ConvexPolygon(std::vector<Vector> vertices, std::string name = "anonymous")
  :Shape(name){
    this->_vertexCount = vertices.size();

    for(Vector v: vertices)
      this->_vertices.push_back(v);
  }

  ~ConvexPolygon(){
    // std::cout << "convexPolygon destructor called" << std::endl;
  }

  double area() const override{
    double result = 0;
    for(int i=0; i<this->_vertices.size()-2; i++)
      result += (this->_vertices[i+1]-this->_vertices[0]).area(this->_vertices[i+2]-this->_vertices[0]);
    return result;
  }

  double perimeter() const override{
    std::vector<Vector> edges;
    for(int i=0; i<this->_vertexCount; i++)
      edges.push_back(this->_vertices[i%this->_vertexCount] - this->_vertices[(i+1)%this->_vertexCount]);

    double result = 0;
    for(Vector v: edges)
      result += v.length();

    return result;
  }

  std::string toString() const override{
    std::stringstream ss;
    ss << "convex polygon {\n"
       << this->name()
       << "\n";
    for(Vector v: this->_vertices)
      ss << v.toString() << "\n";
    ss << "}\n";
    return ss.str();
  }

private:
  std::vector<Vector> _vertices;
  int _vertexCount;

};

#endif
