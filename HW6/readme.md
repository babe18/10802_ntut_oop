# OOP with C++ (and more)
#### Spring, 2020
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 6

### Due: 11:59 p.m., 13 May 2020

**For this assignment, please put class Queue in src/queue.h. Test class Queue in test/ut_queue.h.**

### Purpose of this assignment:
Let student parctice template class.

### Problems:
In this assignment, you are asked to implement a queue with basic push and pop method, both push and pop operate with O(n) time complexity(). Size of the allocated array in queue always match the size of queue after push and pop, you need to manage memory by yourself and you are not allow to use any stl container(ex. std::vector or std::array ...) or you will get 0 point. We provide part of TA test for you to design class interface but **you still need to test it by yourself**.

Please implement these class and methods("?" means do it yourself):

- Queue::Quene()
- Queue::~Queue()
- ? Queue::push(?)
- ? Queue::pop(?)
- ? Queue::at(?)
- ? Queue::size(?)
- ? Queue::clear(?)

### Grading standard and test senrio:

Queue::Quene()
- constructor of queue(10%)

Queue::~Queue()
- release all allocated memory(10%)

? Queue::push(?)
- push an object at the back of queue(15%)

? Queue::pop(?)
- pop object in front of queue(15%)
- throw exception when queue is empty(10%)

? Queue::at(?)
- random access object store at the queue(start with 0)(10%)
- throw exception when index out of range of queue(10%)

? Queue::size(?)
- get size of queue(10%)

? Queue::clear(?)
- clear the queue(10%)

### Sample code:

**src/queue.h**

    #ifndef QUEUE_H
    #define QUEUE_H

    template<class T>
    class Queue{
      //do it yourself
    };

    #endif

**test/ut_queue.h**

    #include "../src/queue.h"
    //do it yourself

**test/ta_ut_queue.h**

    #include "../src/queue.h"

    TEST(QueueTest, defaultConstructor){
      Queue<int> q;
      ASSERT_EQ(0, q.size());
    }

    TEST(QueueTest, push_int){
      Queue<int> q;
      q.push(1);
      ASSERT_EQ(1, q.size());
      ASSERT_EQ(1, q.at(0));
    }

    TEST(QueueTest, push_double){
      Queue<double> q;
      q.push(3.1415);
      ASSERT_EQ(1, q.size());
      ASSERT_NEAR(3.1415, q.at(0), 0.0001);
    }

    TEST(QueueTest, push_char){
      Queue<double> q;
      q.push('a');
      ASSERT_EQ(1, q.size());
      ASSERT_EQ('a', q.at(0));
    }

    TEST(QueueTest, pop_int){
      Queue<int> q;
      q.push(1);
      ASSERT_EQ(1, q.pop());
      ASSERT_EQ(0, q.size());
    }

    TEST(QueueTest, pop_double){
      Queue<double> q;
      q.push(3.1415);
      ASSERT_NEAR(3.1415, q.pop(), 0.0001);
      ASSERT_EQ(0, q.size());
    }

    TEST(QueueTest, pop_char){
      Queue<double> q;
      q.push('a');
      ASSERT_EQ('a', q.pop());
      ASSERT_EQ(0, q.size());
    }

    TEST(QueueTest, pop_empty_exception){
      Queue<std::string> q;
      ASSERT_THROW(q.pop(), std::string);
    }

    TEST(QueueTest, push_10_int_and_pop_them){
      Queue<int> q;
      for(int i=0 ; i<10 ; i++){
        q.push(i);
        ASSERT_EQ(i+1, q.size());
      }
      for(int i=0 ; i<10 ; i++){
        ASSERT_EQ(i, q.pop());
        ASSERT_EQ(9-i, q.size());
      }
    }

    TEST(QueueTest, at_out_of_range_exception){
      Queue<int> q;
      q.push(1);
      q.push(2);
      ASSERT_THROW(q.at(-1), std::string);
      ASSERT_THROW(q.at(2), std::string);
    }

    TEST(QueueTest, clear){
      Queue<int> q;
      q.push(1);
      q.push(2);
      ASSERT_EQ(2, q.size());
      q.clear();
      ASSERT_EQ(0, q.size());
    }

**test/ut_main.h**

    #include <gtest/gtest.h>

    #include "./ta_ut_queue.h"
    #include "./ut_queue.h"

    int main(int argc, char * argv[]) {
      testing::InitGoogleTest( &argc, argv);
      return RUN_ALL_TESTS();
    }

**makefile**

    .PHONY: directories clean

    all: directories bin/ut_all

    bin/ut_all: test/ut_main.cpp test/ut_queue.h src/queue.h
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
