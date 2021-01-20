#include<cmath>

#include"../src/polynomial.h"

TEST(polynomial, test_constructor){
    Term t[] = {Term(10, 0), Term(11, 1), Term(12, 2)};
    Polynomial p(t, 2);

    ASSERT_EQ(10, p.getTermByExponent(0).getCoefficient());
    ASSERT_EQ(11, p.getTermByExponent(1).getCoefficient());
    ASSERT_EQ(12, p.getTermByExponent(2).getCoefficient());
}

TEST(polynomial, test_copy_constructor){
    Term t[] = {Term(-68, 0), Term(4, 1)};
    Polynomial p0(t, 1);
    Polynomial p1 = p0;
    ASSERT_EQ(-68, p1.getTermByExponent(0).getCoefficient());
    ASSERT_EQ(4, p1.getTermByExponent(1).getCoefficient());
}

TEST(polynomial, test_copy_constructor_error_handel){
    Term t1[] = {Term(-68, 0), Term(4, 1)};
    Term t2[] = {Term(10, 0), Term(4, 1)};
    Polynomial p0(t1, 1);
    Polynomial p1(t2, 2);
    p1 = p0;
    ASSERT_EQ(-68, p0.getTermByExponent(0).getCoefficient());
    ASSERT_EQ(4, p0.getTermByExponent(1).getCoefficient());
    ASSERT_EQ(-68, p1.getTermByExponent(0).getCoefficient());
    ASSERT_EQ(4, p1.getTermByExponent(1).getCoefficient());
}

TEST(polynomial, test_operation_add){
    Term t0[] = {Term(0, 0)   , Term(1, 1)  , Term(-7, 2), Term(0, 3)  ,
                 Term(0, 4)   , Term(0.2, 5), Term(50, 6), Term(5.9, 7) };
    Term t1[] = {Term(8, 0)   , Term(6, 1)  , Term(6, 2) , Term(0, 3)  ,
                 Term(-1.7, 4), Term(0, 5)  , Term(-7, 6)               };
    Polynomial p0(t0, 7);
    Polynomial p1(t1, 6);
    Polynomial p2 = p0 + p1;

    ASSERT_EQ(8, p2.getTermByExponent(0).getCoefficient());
    ASSERT_EQ(7, p2.getTermByExponent(1).getCoefficient());
    ASSERT_EQ(-1, p2.getTermByExponent(2).getCoefficient());
    ASSERT_EQ(0, p2.getTermByExponent(3).getCoefficient());
    ASSERT_EQ(-1.7, p2.getTermByExponent(4).getCoefficient());
    ASSERT_EQ(0.2, p2.getTermByExponent(5).getCoefficient());
    ASSERT_EQ(43, p2.getTermByExponent(6).getCoefficient());
    ASSERT_EQ(5.9, p2.getTermByExponent(7).getCoefficient());
}

TEST(polynomial, test_operation_assignment){
    Term t0[] = {Term(1, 0)   , Term(3.5, 1),
                 Term(0, 2)   , Term(0, 3)  ,
                 Term(-2.4, 4), Term(91, 5)  };
    Term t1[] = {Term(-0.5, 0), Term(0, 1)  ,
                 Term(4, 2)   , Term(0, 3)  ,
                 Term(3.6, 4) , Term(-90, 5),
                 Term(0, 6)   , Term(1, 7)   };
    Polynomial p0(t0, 5);
    {
        Polynomial p1(t1, 7);
        p1 = p0;

        ASSERT_EQ(1  , p1.getTermByExponent(0).getCoefficient());
        ASSERT_EQ(3.5, p1.getTermByExponent(1).getCoefficient());
        ASSERT_EQ(0  , p1.getTermByExponent(2).getCoefficient());
        ASSERT_EQ(0, p1.getTermByExponent(3).getCoefficient());
        ASSERT_EQ(-2.4, p1.getTermByExponent(4).getCoefficient());
        ASSERT_EQ(91, p1.getTermByExponent(5).getCoefficient());
    }
    ASSERT_EQ(1, p0.getTermByExponent(0).getCoefficient());
    ASSERT_EQ(3.5, p0.getTermByExponent(1).getCoefficient());
    ASSERT_EQ(0, p0.getTermByExponent(2).getCoefficient());
    ASSERT_EQ(0, p0.getTermByExponent(3).getCoefficient());
    ASSERT_EQ(-2.4, p0.getTermByExponent(4).getCoefficient());
    ASSERT_EQ(91, p0.getTermByExponent(5).getCoefficient());
}

TEST(polynomial, test_get_term_from_polynomial){
    Term t[] = {Term(1.4, 0), Term(-0.8, 1), Term(0, 2), Term(10, 3),
                Term(3.5, 4), Term(0, 5)   , Term(0, 6), Term(1, 7)  };
    Polynomial p(t, 7);

    ASSERT_EQ(1.4, p.getTermByExponent(0).getCoefficient());
    ASSERT_EQ(-0.8, p.getTermByExponent(1).getCoefficient());
    ASSERT_EQ(0, p.getTermByExponent(2).getCoefficient());
    ASSERT_EQ(10, p.getTermByExponent(3).getCoefficient());
    ASSERT_EQ(3.5, p.getTermByExponent(4).getCoefficient());
    ASSERT_EQ(0, p.getTermByExponent(5).getCoefficient());
    ASSERT_EQ(0, p.getTermByExponent(6).getCoefficient());
    ASSERT_EQ(1, p.getTermByExponent(7).getCoefficient());
    ASSERT_ANY_THROW(p.getTermByExponent(8));
    ASSERT_ANY_THROW(p.getTermByExponent(9));
}

TEST(polynomial, test_degree){
    Term t0[] = {Term(-0.9, 0), Term(91, 1), Term(0, 2),
                 Term(0, 3)   , Term(0, 4) , Term(1.5, 5)};
    Term t1[] = {Term(-0.9, 0)};
    Polynomial p0(t0, 5);
    Polynomial p1(t1, 0);

    ASSERT_EQ(5, p0.getDegree());
    ASSERT_EQ(0, p1.getDegree());
}

TEST(polynomial, test_degree_zero){
    Term t[] = {Term(5, 0)};
    Polynomial p(t, 0);

    ASSERT_EQ(0, p.getDegree());
}

TEST(polynomial, test_evaluate){
    Term t0[] = {Term(5, 0), Term(-2, 1), Term(1, 2)};
    Term t1[] = {Term(5, 0), Term(0, 1), Term(0, 2), Term(-2, 3)};
    Polynomial p0(t0, 2);
    Polynomial p1(t1, 3);

    ASSERT_EQ(8, p0.evaluate(-1));
    ASSERT_EQ(5, p0.evaluate(0));
    ASSERT_EQ(4.49, p0.evaluate(1.7));
    ASSERT_EQ(21, p1.evaluate(-2));
    ASSERT_EQ(5, p1.evaluate(0));
    ASSERT_EQ(-1995, p1.evaluate(10));
    ASSERT_EQ(4.998, p1.evaluate(0.1));
    ASSERT_NEAR(4.999999999984, p1.evaluate(0.0002), 0.001);
}
