#include "../src/matrix.h"
#include "../src/math_vector.h"

class MatrixTest : public ::testing::Test { // "test fixture"
protected: // test data
    void SetUp() override {
      a[0] = MathVector(a_r1, 3);
      a[1] = MathVector(a_r2, 3);

      b[0] = MathVector(b_r1, 3);
      b[1] = MathVector(b_r2, 2);

      c[0] = MathVector(c_r1, 4);
      c[1] = MathVector(c_r2, 4);
      c[2] = MathVector(c_r3, 4);

      d[0] = MathVector(d_r1, 4);
      d[1] = MathVector(d_r2, 4);
      d[2] = MathVector(d_r3, 4);

      e[0] = MathVector(e_r1, 4);
      e[1] = MathVector(e_r2, 4);
      e[2] = MathVector(e_r3, 4);
    }

    int a_row = 2;
    int a_col = 3;
    double a_r1[3] = {1, 2, 3};
    double a_r2[3] = {4, 5, 6};
    MathVector a[2];

    int b_row = 2;
    int b_col = 3;
    double b_r1[3] = {1, 2, 3};
    double b_r2[2] = {4, 5};
    MathVector b[2];

    int c_row = 3;
    int c_col = 4;
    double c_r1[4] = {2, 1, -1, 8};
    double c_r2[4] = {-3, -1, 2, -11};
    double c_r3[4] = {-2, 1, 2, -3};
    MathVector c[3];

    int d_row = 3;
    int d_col = 4;
    double d_r1[4] = {1, 1, 2, 5};
    double d_r2[4] = {1, -1, 1, 2};
    double d_r3[4] = {1, 1, 2, 5};
    MathVector d[3];

    int e_row = 3;
    int e_col = 4;
    double e_r1[4] = {1, 1, 2, 5};
    double e_r2[4] = {1, -1, 1, 2};
    double e_r3[4] = {1, 1, 2, 8};
    MathVector e[3];
};

TEST_F(MatrixTest, Matrix_constructor) {
  Matrix m(a, a_row, a_col);
  ASSERT_EQ(1, m.at(1, 1));
  ASSERT_EQ(2, m.at(1, 2));
  ASSERT_EQ(3, m.at(1, 3));
  ASSERT_EQ(4, m.at(2, 1));
  ASSERT_EQ(5, m.at(2, 2));
  ASSERT_EQ(6, m.at(2, 3));
}

TEST_F(MatrixTest, Matrix_constructor_exception) {
  ASSERT_ANY_THROW(Matrix m(b, b_row, b_col));
}

TEST_F(MatrixTest, copy_constructor) {
  Matrix m(a, a_row, a_col);
  Matrix n(m);
  ASSERT_EQ(1, n.at(1, 1));
  ASSERT_EQ(2, n.at(1, 2));
  ASSERT_EQ(3, n.at(1, 3));
  ASSERT_EQ(4, n.at(2, 1));
  ASSERT_EQ(5, n.at(2, 2));
  ASSERT_EQ(6, n.at(2, 3));
}

TEST_F(MatrixTest, row_reduction) {
  Matrix m(c, c_row, c_col);
  m.rowReduction();
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(0.5, m.at(1, 2), 0.001);
  ASSERT_NEAR(-0.5, m.at(1, 3), 0.001);
  ASSERT_NEAR(4, m.at(1, 4), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(1, m.at(2, 2), 0.001);
  ASSERT_NEAR(1, m.at(2, 3), 0.001);
  ASSERT_NEAR(2, m.at(2, 4), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(3, 2), 0.001);
  ASSERT_NEAR(1, m.at(3, 3), 0.001);
  ASSERT_NEAR(-1, m.at(3, 4), 0.001);
}

TEST_F(MatrixTest, back_substitution) {
  Matrix m(c, c_row, c_col);
  m.rowReduction();
  m.backSubstitution();
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(0, m.at(1, 2), 0.001);
  ASSERT_NEAR(0, m.at(1, 3), 0.001);
  ASSERT_NEAR(2, m.at(1, 4), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(1, m.at(2, 2), 0.001);
  ASSERT_NEAR(0, m.at(2, 3), 0.001);
  ASSERT_NEAR(3, m.at(2, 4), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(3, 2), 0.001);
  ASSERT_NEAR(1, m.at(3, 3), 0.001);
  ASSERT_NEAR(-1, m.at(3, 4), 0.001);
}

TEST_F(MatrixTest, gaussian_elimination_normal1) {
  Matrix m(c, c_row, c_col);
  MathVector result = m.gaussianElimination();
  ASSERT_NEAR(2, result[0], 0.001);
  ASSERT_NEAR(3, result[1], 0.001);
  ASSERT_NEAR(-1, result[2], 0.001);
}

TEST_F(MatrixTest, gaussian_elimination_normal2) {
  Matrix m(a, a_row, a_col);
  MathVector result = m.gaussianElimination();
  ASSERT_NEAR(-1, result[0], 0.001);
  ASSERT_NEAR(2, result[1], 0.001);
}

TEST_F(MatrixTest, gaussian_elimination_infinite_solution) {
  Matrix m(d, d_row, d_col);
  ASSERT_ANY_THROW(m.gaussianElimination());
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(1, m.at(1, 2), 0.001);
  ASSERT_NEAR(2, m.at(1, 3), 0.001);
  ASSERT_NEAR(5, m.at(1, 4), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(1, m.at(2, 2), 0.001);
  ASSERT_NEAR(0.5, m.at(2, 3), 0.001);
  ASSERT_NEAR(1.5, m.at(2, 4), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(3, 2), 0.001);
  ASSERT_NEAR(0, m.at(3, 3), 0.001);
  ASSERT_NEAR(0, m.at(3, 4), 0.001);
}

TEST_F(MatrixTest, gaussian_elimination_no_solution) {
  Matrix m(e, e_row, e_col);
  ASSERT_ANY_THROW(m.gaussianElimination());
  ASSERT_NEAR(1, m.at(1, 1), 0.001);
  ASSERT_NEAR(1, m.at(1, 2), 0.001);
  ASSERT_NEAR(2, m.at(1, 3), 0.001);
  ASSERT_NEAR(5, m.at(1, 4), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(1, m.at(2, 2), 0.001);
  ASSERT_NEAR(0.5, m.at(2, 3), 0.001);
  ASSERT_NEAR(1.5, m.at(2, 4), 0.001);
  ASSERT_NEAR(0, m.at(2, 1), 0.001);
  ASSERT_NEAR(0, m.at(3, 2), 0.001);
  ASSERT_NEAR(0, m.at(3, 3), 0.001);
  ASSERT_NEAR(3, m.at(3, 4), 0.001);
}
