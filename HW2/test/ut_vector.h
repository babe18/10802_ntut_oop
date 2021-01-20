#include "../src/math_vector.h"
#include "../src/dot.h"
#include <cmath>

TEST(InnerProduct, Dot1) {
  double u[]={1, 0, 2};
  double v[]={1, 1, 3};

  ASSERT_EQ(7, dot(u, 3, v, 3));
}

TEST(InnerProduct, Dot2) {
  double u[]={5, 0, 0};
  double v[]={-2, 3, 0};

  ASSERT_EQ(-10, dot(u, 3, v, 3));
}

TEST(InnerProduct, Exception1) {
  double u[]={1, 0, 2, 4};
  double v[]={1, 1, 3};

  ASSERT_ANY_THROW(dot(u, 4, v, 3));
}

TEST(InnerProduct, Exception2) {
  double u[]={1, 1, 3};
  double v[]={1, 0, 2, 4};

  ASSERT_ANY_THROW(dot(u, 3, v, 4));
}

TEST(VectorTest, constructor){
  double u[]={1, 1, 3};
  MathVector v(u,3);
  ASSERT_EQ(3, v.getDim());
  ASSERT_EQ(1, v.component(1));
  ASSERT_EQ(1, v.component(2));
  ASSERT_EQ(3, v.component(3));
}

TEST(VectorTest, component){
    double data[3] = {2, 3, 4};
    MathVector vector(data, 3);

    ASSERT_EQ(2, vector.component(1));
    ASSERT_EQ(3, vector.component(2));
    ASSERT_EQ(4, vector.component(3));
}

TEST(VectorTest, GetDim1){
    double data[3] = {2, 3, 4};
    MathVector vector(data, 3);

    ASSERT_EQ(3, vector.getDim());
}

TEST(VectorTest, GetDim2){
    double data[5] = {2, 3, 4, 7, 11};
    MathVector vector(data, 5);

    ASSERT_EQ(5, vector.getDim());
}

TEST(VectorTest, IsZero1){
    double data[3] = {2.5, 3.4, 4.2};
    MathVector vector(data, 3);

    ASSERT_FALSE(vector.isZero());
}

TEST(VectorTest, IsZero2){
    double data[3] = {0, 0, 0};
    MathVector vector(data, 3);

    ASSERT_TRUE(vector.isZero());
}

TEST(VectorTest, Length1){
    double data[3] = {3, 4, 5};
    MathVector vector(data, 3);

    ASSERT_NEAR(sqrt(50), vector.length(), 0.001);
}

TEST(VectorTest, Length2){
    double data[3] = {-3, 4};
    MathVector vector(data, 2);

    ASSERT_NEAR(5, vector.length(), 0.001);
}
