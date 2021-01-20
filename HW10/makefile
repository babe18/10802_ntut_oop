.PHONY: directories clean stat

HEADERS = src/circle.h src/convexPolygon.h src/shape.h src/vector.h src/util.h
TESTS   = test/ut_circle.h test/ut_convexPolygon.h test/ut_vector.h test/ut_util.h

all: directories bin/ut_all bin/main

bin/main: src/main.cpp $(HEADERS)
	g++ -std=c++11 src/main.cpp -o bin/main

bin/ut_all: test/ut_main.cpp $(TESTS) $(HEADERS)
	g++ -std=c++11  test/ut_main.cpp -o bin/ut_all -lgtest -lpthread

directories:
	mkdir -p bin obj

clean:
	rm -rf bin obj

stat:
	wc src/* test/*
