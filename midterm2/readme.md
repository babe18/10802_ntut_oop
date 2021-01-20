# OOP midterm exam 2
#### Spring 2020
#### 23 May 2020, 1:30pm - 17:30pm
----------------------------------------
**For this exam, use the given code template to implement your classes and functions. You will implement four classes in folder ```src\```: ```Binary```, ```uChar```, ```uShort```, and ```uInt``` and some utility functions. Partial test code has been written for you and can be found in the folder ```test/``` with ```ut_binary.h``` for testing  ```Binary```,  ```ut_numeric.h``` for ```uChar,``` ```uShort,``` and ```uInt,``` and ```ut_util.h``` for the utility functions.**

### Problem:

In this exam, you will implement a basic numeric systems that includes binary in class ```Binary```, unsigned char in ```uChar```, unsigned short integers in ```uShort```, and unsigned integers in ```uInt```.

Where:

- ```Binary``` numbers only use _binary digits (bits)_ 0 and 1. A binary number can have any number of bits, for example 01001 is a binary number of 5 bits.

- ```uChar``` represents positive decimal numbers with a length of 8-bits.

- ```uShort``` represents positive decimal numbers with a length of 16-bits.

- ```uInt``` represents positive decimal numbers with a length of 32-bits.

### Program Specification:

Here are the main points:

- Class ```Binary``` has a constructor that takes an array of integers and its length, and throws an exception if any bit is not 0 or 1:
```c++
int b1[] = {1,0,0,0,1,1,0};
Binary b(bi, 7);
```

- The decimal classes ```uChar, uShort``` and ```uInt``` each has a constructor that takes a ```Binary``` as input, and throws an exception if the length of ```Binary``` is _too long_ to fit in the decimal number. To do this, each of decimal classes has a public static function ```canConvert``` that returns true if input ```Binary``` can be converted to that type;

- You will implement a template function ```findAll``` that finds binary numbers in a random access container that matches the given condition;
```c++
std::vector<Binary*> bin = {...};
//example 1
std::vector<Binary*> result = findAll(bins.begin(), bins.end(), [](Binary *b){
  return b->toDec()<=29555;
});//fina binarys that decimal value less or equal to 29555
//example 2
std::vector<Binary*> result = findAll(bins.begin(), bins.end(), [](Binary *b){
  return uShort::canConvert(*b);
});//fina binarys that can be convert to uShort
```
- You will also implement a template function ```convertAll``` that converts any matched binary numbers in a ```std::vector``` to the specified type;
```c++
//example
std::vector<Binary*> bin = {...};
std::vector<uShort> result = convertAll<uShort>(bins); //convert all binary that match the requirement of uShort to uShort
```
- Your **destructors** must keep **memory leak** from occurring.

- You must use **test fixtures** for the tests you write.

### Detailed grading rubrics and test scenarios:

**class Binary**

```Binary::Binary()```
  - the default constructor of class Binary(bits = nullptr and size = 0)

```Binary::Binary(int bits[], int size)```
  - the required constructor of class Binary
  - throw exception if any input number is not 0 or 1(2%)

```Binary(Binary const & b), Binary & operator=(Binary const & b)```
  - copy constructor and copy assignment.

```Binary::~Binary()```
  - the destructor of class Binary

```int Binary::at(int i) const```
  - get the bit at location i
  - throw if input i is out of range(2%)

```unsigned int Binary::toDec() const```
  - convert binary to decimal(6%)

```Binary Binary::fillWithZero(int n) const```
  - Fill zero in front of binary to given size(5%), for example,

```
{0,1,1,0}.fillWithZero(8) => {0,0,0,0,0,1,1,0}
```
  - throw exception if given size is smaller then original binary size(5%)

**class uChar**

```static bool uChar::canConvert(Binary const & bits)```
  - check if input binary matches the requirement of uChar(size<=8)(5%)

```uChar::uChar(Binary const & bits)```
  - accept a binary (5%)
  - throw exception if binary does not meet the specification (5%)

```char Char::toChar()```
  - convert to the type char of C/C++ (5%)

**class uShort**

```static bool uShort::canConvert(Binary const & bits)```
  - check if input binary matches the requirement of uShort(size<=16)(5%)

```uShort::uShort(Binary const & bits)```
  - accept a binary (5%)
  - throw exception if binary does not meet the specification (5%)

```unsigned short uShort::toDec()```
  - convert to unsigned short(5%)

**class uInt**

```static bool uInt::canConvert(Binary const & bits)```
  - check if input binary matches the requirement of uInt(size<=32)(5%)

```uInt::uInt(Binary const & bits)```
  - accept a binary (5%)
  - throw exception if binary does not meet the specification (5%)

```unsigned int uInt::toDec()```
  - convert to unsigned int(5%)

**util**

```C++
template <class RandomAccessIterator, class Condition>
std::vector<Binary*> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond)
```
 - find all binaries that meet the given condition(10%)
 - you should test at last two different conditions

```C++
template <class T>
std::vector<T> convertAll(std::vector<Binary*> const & bins)
```

  - convert the binaries to the given type(10%)
  - you should test conversion to at last two different types

### Hints:
- You should use **ASSERT_ANY_THROW(statement)** to test your exceptions, don't use try catch or you will get 0 point for that sub-problem.
- Use of lambda to test your ```findAll``` is encouraged but not required. You can still use pointer to function or object covered in class.

### Notes:
- Please implement your test cases reasonably and use the correct syntax, or you will get 0 point for that sub-problem.
- There are only four websites allowed to visit: [cplusplus.com](https://www.cplusplus.com/) [cambridge dictionary](https://dictionary.cambridge.org/zht/) [code in class](https://ssl-gitlab.csie.ntut.edu.tw/yccheng/oop2020s) and your homework repo. You will be considered as cheating if you visit other websites.
