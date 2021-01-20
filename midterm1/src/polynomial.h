#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include"term.h"

class Polynomial {
public:
    // consturctor
    Polynomial(Term *terms, int degree){
        this->_degree = degree;
        this->_terms = new Term[degree+1];
        for(int i=0; i<=degree; i++)
            this->_terms[i] = terms[i];
    }

    // copy constructor
    Polynomial(Polynomial const &p){
        this->_degree = p._degree;
        this->_terms = new Term[p._degree+1];
        for(int i=0; i<=p._degree; i++)
            this->_terms[i] = p._terms[i];
    }

    ~Polynomial(){
        delete [] this->_terms;
    }

    // operator assignment
    Polynomial & operator=(const Polynomial &p){
        if(!this->_terms){
          delete [] this->_terms;
        }
        this->_degree = p._degree;
        this->_terms = new Term[p._degree+1];
        for(int i=0; i<=p._degree; i++)
            this->_terms[i] = p._terms[i];
        return *this;
    }

    // operator add
    Polynomial operator+(const Polynomial &p){
        int degree;
        if(this->_degree >= p._degree)
            degree = this->_degree;
        else
            degree = p._degree;
        Term t[degree];
        for(int i=0; i<=this->_degree; i++)
            t[i] = Term(this->_terms[i].getCoefficient() + p._terms[i].getCoefficient(), i);
        return Polynomial(t, degree);
    }

    // get designate term by exponent
    Term getTermByExponent(int exponent){
        if(exponent > this->_degree || exponent < 0)
            throw "invalid";
        return this->_terms[exponent];
    }

    // degree of polynomial
    int getDegree(){
        return this->_degree;
    }

    // get value by a given x
    double evaluate(double x){
        double result;
        for(int i=0; i<=this->_degree; i++)
            result += this->_terms[i].evaluate(x);
        return result;
    }

private:
    Term *_terms;
    int _degree;
};

#endif
