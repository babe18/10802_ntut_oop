# OOP with C++ (and more)
#### Spring, 2020
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 2

### Due: 11:59 p.m., 24 March 2020


**For this assignment, please put all your tests in test/ut_vector.h, all your functions in src/math_vector.h and set the output file to bin/ut_all**


### Purpose of this assignment:
Let students practice for the basic function use and test.

### Problems:

In class, you have learned and written the simple class vector and function dot. For this assignment, you have to write some basic function for vector, and test it!

Please implement these class and methods:

- class MathVector
- dot(double *u, int dim_u, int *v, double dim_v)
- MathVector.component(int index) //向量元素
- MathVector.isZero() //是否為零向量
- MathVector.length() //向量長
- MathVector.getDim() //向量維度

### Test scenario:

class Vector
- test constructor work properly (15%)

dot(double *u, int dim_u, int *v, double dim_v)
- return dot product if dim_u==dim_v (10%)
- throw if dim_u!=dim_v (10%)

MathVector.component(int index)
- return component in the vector(10%)

MathVector.isZero()
- return true if vector is zero vector (15%)
- return false if vector is not zero vector (15%)

MathVector.length()
- return geomatry length of the vector (15%)

MathVector.getDim()
- return the dimension of the vector (10%)


### Sample code:
we will provide sample code for this assignment

**src/dot.h**

	#include <string>

	double dot(double *u, int dim_u, double *v, int dim_v){
	  double result = 0;
	  if (dim_u != dim_v) {
	    throw std::string("undefined");
	  }
	  for(int i=0; i<dim_u; i++) {
	    result += u[i] * v[i];
	  }
	  return result;
	}


**src/math_vector.h**

	#include <cmath>

	class MathVector {
		double * _vec;
		int _dim;

	public:
	  MathVector(double a[], int dim){
	    _dim = dim;
	    _vec = new double[_dim];
	    for( int i = 0; i < _dim; i++){
	      _vec[i] = a[i];
	    }
	  }

	  double component(int index){
	    return _vec[index-1];
	  }

	  double component(int index){...}

	  bool isZero(){...}

	  double length(){...}

	  int getDim(){...}
	};

**test/ut_main.cpp**

	#include <gtest/gtest.h>

	#include "./ut_vector.h"

	int main(int argc, char **argv){
	  testing ::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
	}

**test/ut_vector.h**

	#include "../src/math_vector.h"
	#include "../src/dot.h"
	#include <cmath>

	TEST(InnerProduct, Dot1) {
	  double u[]={1, 0, 2};
	  double v[]={1, 1, 3};

	  ASSERT_EQ(7, dot(u, 3, v, 3));
	}

	...add your test here...

**makefile**

	.PHONY: directories clean stat

	all: directories bin/ut_all

	bin/ut_all: obj/ut_main.o
	  g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

	obj/ut_main.o: test/ut_main.cpp test/ut_vector.h src/dot.h src/math_vector.h
	  g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

	directories:
	  mkdir -p bin obj

	clean:
	  rm -rf bin obj

	stat:
	  wc src/* test/*

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. for float number test, you should use ASSERT_NEAR(EXPCET, ACTUAL, ALPHA) instead of ASSERT_EQ(EXPCET, ACTUAL)
2. _TA project will be used in this assignment
