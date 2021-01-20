#include "../src/math_vector.h"

class VectorTest : public ::testing::Test { // "test fixture"
protected:
    double z[2] = {5, 7};
    double u[2] = {1, 2};
    double v[2] = {3, 4};
    double x[3] = {1, 2, 3};
};

TEST_F(VectorTest, MathVector_default_constructor) {
  MathVector v;
  ASSERT_EQ(0, v.dimension());
}

TEST_F(VectorTest, MathVector_normal_constructor) {
  MathVector v(z, 2);
  ASSERT_EQ(5, v[0]);
  ASSERT_EQ(7, v[1]);
}

TEST_F(VectorTest, MathVector_zero_constructor) {
  MathVector v(10);
  ASSERT_EQ(10, v.dimension());
  for(int i=0 ; i<10 ; i++){
    ASSERT_EQ(0, v[i]);
  }
}

TEST_F(VectorTest, copy_constructor){
  MathVector a(u, 2);
  MathVector b(a);
  ASSERT_EQ(1, b[0]);
  ASSERT_EQ(2, b[1]);
}

TEST_F(VectorTest, object_assignment){
  MathVector a(u, 2);
  {
    MathVector b(v, 2);
    a = b;
  }
  ASSERT_EQ(3, a[0]);
  ASSERT_EQ(4, a[1]);
}

TEST_F(VectorTest, object_assignment2){
  MathVector a(u, 2);
  MathVector b(v, 2);
  MathVector c(z, 2);
  a = b = c;

  ASSERT_EQ(5, a[0]);
  ASSERT_EQ(7, a[1]);
}

TEST_F(VectorTest, operator_add){
  MathVector a(u, 2);
  MathVector b(x, 3);
  ASSERT_ANY_THROW(a+b);
}

TEST_F(VectorTest, add_normal){
  MathVector a(u, 2);
  MathVector b(v, 2);
  ASSERT_EQ(4, (a+b)[0]);
  ASSERT_EQ(6, (a+b)[1]);
}

TEST_F(VectorTest, add_exception){
  MathVector a(u, 2);
  MathVector b(x, 3);
  ASSERT_ANY_THROW(a+b);
}

TEST_F(VectorTest, scale){
  MathVector a(u, 2);
  a = a.scale(2);
  ASSERT_EQ(2, a[0]);
  ASSERT_EQ(4, a[1]);

  MathVector b(x, 3);
  b = b.scale(3);
  ASSERT_EQ(3, b[0]);
  ASSERT_EQ(6, b[1]);
  ASSERT_EQ(9, b[2]);
}
