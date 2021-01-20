#include "./shape.h"
#include "./vector.h"
#include "./circle.h"
#include "./convexPolygon.h"

#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>

Vector stringToVector2D(std::string coor){
  std::stringstream ss(coor);
  char ch;
  double a[2];
  ss >> ch >> a[0] >> ch >> a[1] >> ch;
  return Vector(a, 2);
}

std::string stringFromFile(std::string fileName) {
  std::ifstream ifs(fileName);
  std::string result = "";
  std::string line;
  std::getline(ifs, line);
  while(!ifs.eof() && !line.empty()) {
    result += line + "\n";
    std::getline(ifs, line);
  }
  return result;
}

bool areaAscending(Shape *s1, Shape *s2){
  return s1->area() < s2->area();
}

bool areaDescending(Shape *s1, Shape *s2){
  return s1->area() > s2->area();
}

bool perimeterAscending(Shape *s1, Shape *s2){
  return s1->perimeter() < s2->perimeter();
}

bool perimeterDescending(Shape *s1, Shape *s2){
  return s1->perimeter() > s2->perimeter();
}

std::vector<Shape *> handleSort(std::vector<Shape *> shapes, std::string compare, std::string order){
  if(compare == "area" && order == "inc"){
    std::sort(shapes.begin(), shapes.end(), areaAscending);
  }else if(compare == "area" && order == "dec"){
    std::sort(shapes.begin(), shapes.end(), areaDescending);
  }else if(compare == "perimeter" && order == "inc"){
    std::sort(shapes.begin(), shapes.end(), perimeterAscending);
  }else if(compare == "perimeter" && order == "dec"){
    std::sort(shapes.begin(), shapes.end(), perimeterDescending);
  }

  return shapes;
}

std::vector<Shape *> handleInput(std::string inputFile){
  std::ifstream ifs(inputFile);
  std::stringstream ss(stringFromFile(inputFile));
  std::vector<Shape *> shapes;

  while(!ifs.eof()){
    std::string line;
    std::getline(ifs, line);
    if(line == "circle {"){
      std::string name;
      std::getline(ifs, name);
      std::string origin;
      std::getline(ifs, origin);
      std::string radius;
      std::getline(ifs, radius);
      shapes.push_back(new Circle(std::stod(radius), name, stringToVector2D(origin)));
    }else if(line == "convex polygon {"){
      std::string name;
      std::getline(ifs, name);
      std::string coor;
      std::vector<Vector> vecs;
      while(true){
        std::getline(ifs, coor);
        if(coor == "}")
          break;
        vecs.push_back(stringToVector2D(coor));
      }
      shapes.push_back(new ConvexPolygon(vecs, name));
    }
  }
  return shapes;
}

 void handleOutput(std::string outputFile, std::vector<Shape *> shapes){
  std::ofstream ofs(outputFile);
  for(Shape *shape: shapes)
    ofs << shape->toString();
}
