#include <gtest/gtest.h>
#include <cmath>

#include "../src/vector.h"

TEST(Vector,defaultConstructorTest){
    Vector v;
    ASSERT_EQ(-1,v.dim());
}

TEST(Vector,constructorTest){
    double v[]={1,4,2,34,2};
    Vector vec(v,5);
    ASSERT_EQ(1, vec.at(1));
    ASSERT_EQ(4, vec.at(2));
    ASSERT_EQ(2, vec.at(3));
    ASSERT_EQ(34, vec.at(4));
    ASSERT_EQ(2, vec.at(5));
}

TEST(Vector,copyConstructorTest){
    double v[]={1,4,2,34,2};
    Vector vec2(v,5);
    Vector vec(vec2);
    ASSERT_EQ(1, vec.at(1));
    ASSERT_EQ(4, vec.at(2));
    ASSERT_EQ(2, vec.at(3));
    ASSERT_EQ(34, vec.at(4));
    ASSERT_EQ(2, vec.at(5));
}

TEST(Vector,atTest){
    double a[] = {26,3,4};
    Vector v(a,3);
    ASSERT_EQ(3,v.at(2));
}

TEST(Vector,assignmentOperatorTest){
    double v[]={1,4,2,34,2};
    Vector vec2(v,5);
    Vector vec=vec2;
    ASSERT_EQ(1, vec.at(1));
    ASSERT_EQ(4, vec.at(2));
    ASSERT_EQ(2, vec.at(3));
    ASSERT_EQ(34, vec.at(4));
    ASSERT_EQ(2, vec.at(5));
}

TEST(Vector,addTest){
    double v[]={1,4,2,34,2};
    double v2[]={3,4,2,4,2};
    Vector vec(v,5);
    Vector vec2(v2,5);
    ASSERT_EQ(4, (vec+vec2).at(1));
    ASSERT_EQ(8, (vec+vec2).at(2));
    ASSERT_EQ(4, (vec+vec2).at(3));
    ASSERT_EQ(38, (vec+vec2).at(4));
    ASSERT_EQ(4, (vec+vec2).at(5));
}

TEST(Vector,substractTest){
    double v[]={1,4,2,34,2};
    double v2[]={3,4,2,4,2};
    Vector vec(v,5);
    Vector vec2(v2,5);
    ASSERT_EQ(-2, (vec-vec2).at(1));
    ASSERT_EQ(0, (vec-vec2).at(2));
    ASSERT_EQ(0, (vec-vec2).at(3));
    ASSERT_EQ(30, (vec-vec2).at(4));
    ASSERT_EQ(0, (vec-vec2).at(5));
}

TEST(VectorTest, lengthTest){
    double a[]={3,2};
    Vector v(a,2);
    ASSERT_EQ(sqrt(13),v.length());
}

TEST(VectorTest, angleTest){
	double a1[] = {1, 0};
	double b1[] = {1, 1};
	double a2[] = {1, 0};
	double b2[] = {1, 1};
	double a3[] = {1, 0};
	double b3[] = {-1, -1};
	Vector x1(a1, 2);
	Vector y1(b1, 2);
	Vector x2(a2, 2);
	Vector y2(b2, 2);
	Vector x3(a3, 2);
	Vector y3(b3, 2);
	ASSERT_NEAR(M_PI / 4, x1.angle(y1), 0.01);
	ASSERT_NEAR(7 * M_PI / 4, y2.angle(x2), 0.01);
	ASSERT_NEAR(5 * M_PI / 4, x3.angle(y3), 0.01);
}
