#ifndef VECTOR_H
#define VECTOR_H

#include <cmath>

class Vector{
  public:
	//default constructor
	Vector() : _dim(-1), _v(nullptr) {}

	Vector(double v[], int dim) : _dim(dim), _v(nullptr){	//5%
		copy(v);
	}

	//copy constructor
	Vector(Vector const &v) : _dim(v._dim), _v(nullptr){		//5%
		copy(v._v);
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

	double &at(int i) const{
		return _v[i - 1];
	}

	Vector &operator=(Vector const &u){	//10%
		_dim = u._dim;
		copy(u._v);
		return *this;
	}

	Vector operator-(Vector const &v) const{	//10%
		Vector u(*this);
		for (int i = 0; i < u._dim; i++)
			u._v[i] -= v._v[i];
		return u;
	}

	Vector operator+(Vector const &v) const{	// 10%
		Vector u(*this);
		for (int i = 0; i < u._dim; i++)
			u._v[i] += v._v[i];
		return u;
	}

	double length() const{
		double temp = 0;
		for (int i = 0; i < _dim; i++)
			temp += pow(_v[i], 2);
		return sqrt(temp);
	}

	double angle(Vector u) const {		//10%
		double dot = 0;
		for (int i = 1; i <= u.dim(); i++)
			dot += this->_v[i-1] * u.at(i);
		double cross = _v[0] * u.at(2) - _v[1] * u.at(1);
		if (cross >= 0)
			return acos(dot / (this->length() * u.length()));
		else
			return 2 * M_PI - acos(dot / (this->length() * u.length()));
	}

  private:
	int _dim;
	double *_v;
	void copy(double v[]){
		_v = new double[_dim];
		for (int i = 0; i < _dim; i++)
			_v[i] = v[i];
	}
};

#endif
