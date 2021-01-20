#ifndef TERM_H
#define TERM_H

#include<cmath>

class Term {
public:
    // default constuctor
    Term(){
        _coefficient = 0;
        _exponent = 0;
    }

    // constructor
    Term(double coefficient, int exponent){
        _coefficient = coefficient;
        _exponent = exponent;
    }

    // operator assignment
    Term & operator=(Term const &t){
        this->_coefficient = t._coefficient;
        this->_exponent = t._exponent;
        return *this;
    }

    // operator add
    Term operator+(Term const &t){
        if(this->_exponent != t._exponent)
            throw "terms with different exponents can not be added.";
        return Term(this->_coefficient + t._coefficient, this->_exponent);
    }

    // operator multiply
    Term operator*(Term const &t){
        return Term(this->_coefficient * t._coefficient, this->_exponent + t._exponent);
    }

    // operator equal
    bool operator==(Term const &t){
        return this->_coefficient == t._coefficient &&
            this->_exponent == t._exponent;
    }

    // access coefficient of a term
    double getCoefficient() const {
        return _coefficient;
    }

    // access exponent of a term
    int getExponent() const {
        return _exponent;
    }

    // get value by a given x
    double evaluate(double x){
        return this->_coefficient * pow(x, this->_exponent);
    }

private:
    double _coefficient;
    int _exponent;
};

#endif
