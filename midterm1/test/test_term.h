#include"../src/term.h"

#include<iostream>

TEST(term, test_default_constructor){
    Term t;
    ASSERT_EQ(0, t.getCoefficient());
    ASSERT_EQ(0, t.getExponent());
}

TEST(term, test_normal_constructor){
    Term t0(5, 1);
    ASSERT_EQ(5, t0.getCoefficient());
    ASSERT_EQ(1, t0.getExponent());
    Term t1(1.9, 10);
    ASSERT_EQ(1.9, t1.getCoefficient());
    ASSERT_EQ(10, t1.getExponent());
}

TEST(term, test_operator_assignment){
    Term t0(1, 3);
    Term t1(3, 5);
    ASSERT_NE(t0.getExponent(), t1.getExponent());
    ASSERT_NE(t0.getCoefficient(), t1.getCoefficient());
    t0 = t1;
    ASSERT_EQ(t0.getExponent(), t1.getExponent());
    ASSERT_EQ(t0.getCoefficient(), t1.getCoefficient());
}

TEST(term, test_operator_add){
    Term t0(6, 2);
    Term t1(8.2, 2);
    ASSERT_NEAR(14.2, (t0+t1).getCoefficient(), 0.001);
}

TEST(term, test_add_with_different_exponent){
    Term t0(1, 2);
    Term t1(5, 3);
    ASSERT_ANY_THROW(t0 + t1);
}

TEST(term, test_operator_multiply){
    Term t0(-0.5, 1);
    Term t1(4, 2);
    Term t2 = t0 * t1;
    ASSERT_EQ(-0.5, t0.getCoefficient());
    ASSERT_EQ(1, t0.getExponent());
    ASSERT_EQ(4, t1.getCoefficient());
    ASSERT_EQ(2, t1.getExponent());
    ASSERT_EQ(-2, t2.getCoefficient());
    ASSERT_EQ(3, t2.getExponent());
}

TEST(term, test_operator_multiply_2){
    Term t0(0, 1);
    Term t1(4, 2);
    Term t2 = t0 * t1;
    ASSERT_EQ(0, t0.getCoefficient());
    ASSERT_EQ(1, t0.getExponent());
    ASSERT_EQ(4, t1.getCoefficient());
    ASSERT_EQ(2, t1.getExponent());

    ASSERT_EQ(0, t2.getCoefficient());
    ASSERT_EQ(3, t2.getExponent());
}

TEST(term, test_operator_equal){
    Term t0(5, 7);
    Term t1(5, 7);
    Term t3(6, 7);
    ASSERT_TRUE(t0 == t1);
    ASSERT_FALSE(t0 == t3);
}

TEST(term, test_evaluate){
    Term t0(2.2, 2);
    Term t1(-0.25, 3);

    ASSERT_EQ(0, t0.evaluate(0));
    ASSERT_EQ(2.2, t0.evaluate(1));
    ASSERT_EQ(8.8, t0.evaluate(2));
    ASSERT_EQ(0.198, t0.evaluate(0.3));
    ASSERT_EQ(-16, t1.evaluate(4));
    ASSERT_NEAR(297.754, t1.evaluate(-10.6), 0.001);
    ASSERT_EQ(0.03125, t1.evaluate(-0.5));
}
