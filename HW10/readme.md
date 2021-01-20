# OOP with C++ (and more)
#### Spring, 2020
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 10

### Due: 11:59 p.m., 25 June 2020
-------

### IMPORTANT
**To improve your ability to read and understand codes written by others, for**
**this assignment, you must complete all the production code without any**
**provided code template, including `./src/circle.h`, `./src/convexPolygon.h`,**
**`./src/shape.h`, `./src/util.h`, and `./src/vector.h`. In addition, we will**
**provide all the TA tests and you DON'T need write any unit test yourself, in**
**addition, main program is also provided.**

**You will have 3 output files:**
1. bin/ut_all for all testing
2. bin/main for main executable
3. output of handleOutput() function


### Purpose of this assignment:
Learn how to handle I/O task.


### Problems:
In class, we read data from a plain text file and build a `Circle` object into
our program. For this assignment, you have to implement class `ConvexPolygon`
and make it inherit class `Shape` as well. In addition to input, you have to
output a list of shape to correct format. Moreover, you need to design class
interface yourself by investigating unit tests we provide, any design that pass
the test are accepted. However, please make your class interface as small as
possible and easy to extend. Don't just output string that we want or you will
get 0 point.

Please complete or modify these class/file:
- class ConvexPolygon
- class Circle
- class Shape
- file util.h

The format of output file:
```
circle {
big_circle          // name of this circle
(x,y)               // origin of this circle
r                   // radius of this circle
}
convex polygon {
polygon             // name of this convex polygon
(x1,y1)             // vertices of the polygon below
(x2,y2)
(x3,y3)
...
...
}
```

### Design concept:
Each concrete shape class must inherit the base class `Shape`, and any functions
that handle I/O task must be put in the file `util.h`


### Note:
1. You DON'T need to write your own unit test for this assignment.
2. You have to follow the main.cpp we provide to complete this assignment.
3. Please refer to sample I/O files we provided(i.e., shape_data_1-shape_data_3).
4. You can compile your main.cpp by `make bin/main`, and run `bin/main` will
output a text file that contains sorted shapes data in your working directory.
5. \_TA project will be used in this assignment.
