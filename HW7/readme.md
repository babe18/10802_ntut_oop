# OOP with C++ (and more)
#### Spring, 2020
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 7

### Due: 11:59 p.m., 22 May 2020

**For this assignment, please put class Polygon in src/polygon.h and class Vector in src/vector.h. Test class Polygon in test/ut_polygon.h, test class Vector in test/ut_vector.h.**

### Purpose of this assignment:
Let student parctice template method and lambda.

### Problems:
In this assignment, you are asked to implement a finding method with perimeter and area of polygons. The only standard container you can use is setting up the std::vector of the polygons before using findAll method.

Please implement these class and methods:

- Vector::int dim()const
- Vector::double at(int i)const
- Vector::Vector &operator+
- Vector::Vector &operator-
- Vector::double length()const
- Vector::double angle(Vector u)const
- Polygon::Vector point(int i)
- Polygon::int sides()
- Polygon::double perimeter()
- Polygon::double area()
- std::vector<Polygon \*> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)
- implement constructor, destructor or operator= as needed by your self.

### findAll:

findAll is a template method which prototype is

```c++
template <class RandomAccessIterator, class Condition>
std::vector<Polygon *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond);
```

when we have a list of polygons

std::vector<Polygon \*>  polygons = {...}

we can call findAll to find polygons that match the condiction

for example

```c++
std::vector<Polygon *> result = findAll(polygons.begin(), polygons.end(), [](Polygon *s) {
  return s->area() > 2 && s->area() < 5.5;
}); // find polygon that area larger then 2 and less then 5
```

or

```c++
std::vector<Polygon *> result = findAll(polygons.begin()+2, polygons.end(), [](Polygon *s) {
  return s->perimeter() > 7;
}); // find polygon that perimeter less then 7 in polygons[2:] range
```

### Grading standard and test senrio:

Vector::int dim()const
- get dimension of vector (5%)

Vector::double at(int i)const
- get the point of vector (5%)

Vector::Vector &operator+
- operator to add two vectors (5%)

Vector::Vector &operator-
- operator to substract two vectors (5%)

Vector::double length() const
- get the length of the vector(5%)

Vector::double angle(Vector u) const
- calculate the angle between two vectors (10%)

Polygon::Vector point(int i)
- get the vector of the point (5%)
- handling exception when index out of range of polygon (5%)

Polygon::int sides()
- get the sides of vector(5%)

Polygon::double perimeter()
- calculate perimeter of the polygon (10%)

Polygon::double area()
- calculate area of the polygon (10%)

std::vector<Polygon \*> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)
- find the polygon(s) by any given conidction (30%)
- you should test at last two different condition

### Sample code:

**makefile**

    .PHONY: directories clean

    all: directories bin/ut_all

    bin/ut_all: test/ut_main.cpp test/ut_polygon.h test/ut_vector.h src/vector.h src/polygon.h
    	g++ -std=c++11 test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

    directories:
    	mkdir -p bin

    clean:
    	rm -rf bin

    stat:
    	wc src/*.h src/*.cpp test/*.h test/*.cpp

Note:
1. Please implement your test cases reasonably and use the correct syntax, or you will lose point for that sub-problem.
2. \_TA project will be used in this assignment.
3. code section "[](Polygon *s) {return s->perimeter() > 7;}" is call lambda, we encourage you to use lambda in this assignment.
