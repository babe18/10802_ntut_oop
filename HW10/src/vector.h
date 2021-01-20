#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>
#include <sstream>

class Vector{
public:
	//default constructor
	Vector():_dim(-1), _v(nullptr) {}

	Vector(double v[], int dim)
  :_dim(dim), _v(nullptr){
		this->copy(v);
	}

  Vector(int dim)
	:_dim(dim){
		double v[dim] = {0};
		this->copy(v);
	}

	//copy constructor
	Vector(Vector const &v)
  :_dim(v._dim), _v(nullptr){
		this->copy(v._v);
	}

	// destructor
	~Vector(){
		if (_v != nullptr)
			delete[] _v;
	}

	// constant member function
	int dim() const{
		return _dim;
	}

	double at(int i) const{
		if(i > this->_dim)
			throw "index out of range";
		return _v[i];
	}

	Vector &operator=(Vector const &u){
		this->_dim = u._dim;
		this->copy(u._v);
		return *this;
	}

	Vector operator-(Vector const &v) const{
    if(this->_dim != v._dim)
      throw "dimension error";
		Vector u(*this);
		for (int i=0; i<u._dim; i++)
			u._v[i] -= v._v[i];
		return u;
	}

	Vector operator+(Vector const &v) const{
    if(this->_dim != v._dim)
      throw "dimension error";
		Vector u(*this);
		for (int i=0; i<u._dim; i++)
			u._v[i] += v._v[i];
		return u;
	}

  double operator[](int index) const{
    if(index >= this->_dim)
      throw "index out of range";
    return this->_v[index];
  }

	double length() const{
		double temp = 0;
		for (int i=0; i<this->_dim; i++)
			temp += pow(_v[i], 2);
		return sqrt(temp);
	}

  double dot(Vector u) const{
    double result = 0;
    for (int i=0; i<u.dim(); i++)
			result += this->_v[i] * u._v[i];
    return result;
  }

	double angle(Vector u) const{
    double result = dot(u)/(length()*u.length());
		double cross = this->_v[0] * u._v[1] - this->_v[1] * u._v[0];
		if(cross >= 0)
			return acos(result);
		else
			return 2 * M_PI - acos(result);
	}

	double area(Vector u){
		return 0.5*sqrt(pow(this->length(), 2)*pow(u.length(), 2) - pow(this->dot(u), 2));
	}

  std::string toString() const{
    std::stringstream ss;
    ss << "(";
    for(int i=0; i<this->_dim; i++){
      ss << this->_v[i];
      if(i < this->_dim-1)
        ss << ",";
    }
    ss << ")";
    return ss.str();
  }

private:
	void copy(double v[]){
		_v = new double[_dim];
		for (int i=0; i< _dim; i++)
			_v[i] = v[i];
	}

private:
	int _dim;
	double *_v;

};

#endif
