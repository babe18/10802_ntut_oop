#include <cmath>

class MathVector {
  double * _vec;
  int _dim;

public:
  MathVector(double a[], int dim){
    _dim = dim;
    _vec = new double[_dim];
    for( int i = 0; i < _dim; i++){
      _vec[i] = a[i];
    }
  }

  double component(int index){
    return _vec[index-1];
  }

  bool isZero(){
      for (int i = 0; i < this->_dim; i++){
          if (this->_vec[i] != 0)
              return false;
      }
      return true;
  }

  double length(){
      double length = 0;
      for (int i = 0; i < this->_dim; i++){
          length += this->_vec[i] * this->_vec[i];
      }
      return sqrt(length);
  }

  int getDim(){
      return this->_dim;
  }
};
