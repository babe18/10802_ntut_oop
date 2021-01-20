# OOP with C++ (and more)
#### Spring, 2020
#### Prof Y C Cheng
#### Dept of Computer Science and Information Engineering
#### Taipei Tech

## Assignment 3

### Due: 11:59 p.m., 31 March 2020


**For this assignment, please put class html in src/html.h, class text in src/text.h. Test class html in test/ut_html.h, test class text in test/ut_text.h. You will have 3 output files: bin/ut_all for all testing, bin/ui_main for ui exectuable and main.html is your ui output product**


### Purpose of this assignment:
constructing UI framework from the scratch by using html

### Problems:

There are many UI framework like QT or .NET now a day. From this assignment, we want you to develop an UI framework using html by your self. Let's start from the most basic tags, < html > and < p >, and test it.

Please implement these class and methods:

- class Html
- class Text
- Html.appendChild(Text child)
- Html.render()
- Html.outputHtml()
- Text.render()
- Text.setText(std::string content)

### Design concept:

This UI framework is capable with adding multiple child tag (ie. text) to the body html, and output all child in string with proper html tag formate. The following is an example.

main.cpp

	int main(){
	  Html h; <-main body tag
	  Text t1;
	  Text t2; <-two <p> tag
	  t1.setText("Hello, World"); <-first tag with "Hello, World" content
	  t2.setText("This is a simple ui output"); <-second tag with "This is a simple ui output" content
	  h.appendChild(t1);
	  h.appendChild(t2); <-put two children into body
	  h.outputHtml(); <-output content to main.html
	  return 0;
	}


main.html (輸出成一行即可， 這邊換行是幫助閱讀)

	<HTML> //<- <html>, <body> render by class html
		<body>
			<p>Hello, World</p> //<-first tag
			<p>This is a simple ui output</p> //<-second tag
		</body>
	</HTML>

![main_example](./main_example.jpg)

### Grading standard:

Html.appendChild(Text child)
- add a text tag, should render in adding order.(20%)

Html.render()
- return the content with proper < html >, < body > tag pair.(10%)
- return the empty body if no child append.(10%)

Html.outputHtml()
- grading by your main.cpp output, should appear like example.(20%)

Text.render()
- return the content with proper < p > tag pair.(10%)
- return the empty < P > tag if content not set.(10%)

Text.setText(std::string content)
- set the content to the text.(20%)


### Sample code:
we will provide sample code for this assignment.

**src/html.h**

	#ifndef HTML_H
	#define HTML_H

	#include "text.h"

	#include<fstream>
	#include<cstring>
	#include<vector>

	class Html{
	public:

	  void appendChild(Text child){...}

	  std::string render(){...}

	  void outputHtml(){
	     std::ofstream file;
	     file.open("main.html");
	     file<<this->render();
	     file.close();
	  }

	private:
	  std::vector<Text> tags;
	  const std::string html_head="<HTML><body>";
	  const std::string html_end="</body></HTML>";
	};

	#endif

**src/text.h**

	#ifndef TEXT_H
	#define TEXT_H

	class Text{
	public:
	  std::string render(){...}

	  void setText(std::string content){...}

	private:
	  std::string content;
	};

	#endif

**src/main.cpp**

	#include<iostream>

	#include "./html.h"
	#include "./text.h"
	//dont't modify
	int main(){
	  Html h;
	  Text t1;
	  Text t2;
	  t1.setText("Hello, World");
	  t2.setText("This is a simple ui output");
	  h.appendChild(t1);
	  h.appendChild(t2);
	  h.outputHtml();
	  std::cout << "output successful" << std::endl;
	  return 0;
	}

**test/ut_main.cpp**

	#include <gtest/gtest.h>

	#include "./ut_html.h"
	#include "./ut_text.h"

	int main(int argc, char **argv){
	  testing ::InitGoogleTest(&argc, argv);
	  return RUN_ALL_TESTS();
	}

**test/ut_html.h**

	#include "../src/html.h"
	#include "../src/text.h"

	...add your test here...

**test/ut_text.h**

	#include "../src/text.h"

	...add your test here...

**makefile**

.PHONY: directories clean stat

	all: directories bin/ut_all

	bin/ui_main: src/main.cpp src/html.h src/text.h
		g++ -std=c++11 -o bin/ui_main src/main.cpp

	bin/ut_all: obj/ut_main.o
		g++ -std=c++11 -o bin/ut_all obj/ut_main.o -lgtest -lpthread

	obj/ut_main.o: test/ut_main.cpp test/ut_html.h test/ut_text.h src/html.h src/text.h
		g++ -std=c++11 -c test/ut_main.cpp -o obj/ut_main.o

	directories:
		mkdir -p bin obj

	clean:
		rm -rf bin obj

	stat:
		wc src/* test/*

Note:
1. Please implement your test cases reasonably, or you will get no point for that sub-problem.
2. You can compile your main.cpp by "make bin/ui_main", and run "bin/ui_main" will output main.html into yout working directorie.
3. It is great for you to study std::vector and std::string usage first
4. _TA project will be used in this assignment
