#ifndef POLYGON_H
#define POLYGON_H

#include "vector.h"

class Polygon{
  public:
	Polygon() : _sides(-1), _vec(nullptr) {}	//5%

	Polygon(Vector vec[], int sides) : _sides(sides), _vec(nullptr){	//5%
		copy(vec);
	}

	~Polygon(){
		if (_vec != nullptr)
			delete[] _vec;
	}

	Vector point(int i){	//10% (test+exception)
		if(i>_sides || i<=0)
			throw("Overflow");
		return _vec[i-1];
	}

	int sides(){
		return _sides;
	}

	double perimeter(){		//15% (5% for normal test, 10% for findAll test)
		pointsInOrder();
		double temp = 0;
		for (int i = 1; i < _sides; i++)
			temp += (_vec[i - 1] - _vec[i]).length();
		temp += (_vec[0] - _vec[_sides - 1]).length();
		return temp;
	}

	double area(){			//15% (5% for normal test, 10% for findAll test)
		pointsInOrder();
		double temp = 0;
		double a, b, c, s;
		for (int i = 2; i < _sides; i++){
			a= (_vec[0] - _vec[i - 1]).length();
			b= (_vec[i - 1] - _vec[i]).length();
			c= (_vec[0] - _vec[i]).length();
			s= (a+b+c)/2;
			temp += sqrt(s * (s - a) * (s - b) * (s - c));
		}
		return temp;
	}

  private:
	Vector *_vec;
	int _sides;
	void copy(Vector vec[]){
		_vec = new Vector[_sides];
		for (int i = 0; i < _sides; i++)
			_vec[i] = vec[i];
	}

	void pointsInOrder(){
		int dim = _vec[0].dim();
		double data[dim];
		for (int i = 0; i < dim; i++)
			data[i] = 0;
		Vector center(data, dim);
		for (int i = 0; i < _sides; i++)
			center = center + _vec[i];
		for (int i = 1; i <= dim; i++)
			center.at(i) /= _sides;
		for (int i = 0; i < _sides; i++)
			_vec[i] = _vec[i] - center;
		std::sort(_vec + 1, _vec + _sides, [this](Vector u, Vector v) {
			 return _vec->angle(u) < _vec->angle(v); });
	}
};

template <class RandomAccessIterator, class Condition>
std::vector<Polygon *> findAll(RandomAccessIterator begin, RandomAccessIterator end, Condition cond){
	std::vector<Polygon *> vec;
	for (RandomAccessIterator i = begin; i < end; i++)
		if (cond(*i))
			vec.push_back(*i);
	return vec;
}

#endif