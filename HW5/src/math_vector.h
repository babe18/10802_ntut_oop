#ifndef MATH_VECTOR_H
#define MATH_VECTOR_H

class MathVector {
public:
  MathVector(){
    this->_vec = nullptr;
    this->_dim = 0;
  }

  MathVector(double a[], int dim){
    initialize(a, dim);    // refactoring
  }

  MathVector(int dim){
    double a[dim] = {0};
    initialize(a, dim);
  }

  MathVector(MathVector const & u){
    initialize(u._vec, u._dim);
  }

  MathVector & operator = (MathVector const & v) {
    if(_vec != nullptr){
      delete [] _vec;
    }
    initialize(v._vec, v._dim);
    return *this;
  }

  ~MathVector(){
    if(_vec != nullptr)
      delete [] _vec;
  }

  double & operator [] (int index){
    return _vec[index];
  }


  int dimension() const {
    return _dim;
  }

  MathVector operator + (MathVector & v) {
    if(this->dimension() != v.dimension()){
      throw(std::string("dimension not match"));
    }
    MathVector result = *this;
    for(int i=0 ; i<result.dimension() ; i++){
      result[i] += v[i];
    }
    return result;
  }

  MathVector scale(double scale){
    MathVector result(*this);
    for(int i=0 ; i<this->dimension() ; i++){
      result[i] = this->_vec[i] * scale;
    }
    return result;
  }

private:
  void initialize(double * a, int dim){
    _dim = dim;
    _vec = new double[_dim];
    for(int i=0 ; i<_dim ; i++){
      _vec[i] = a[i];
    }
  }
  double * _vec;
  int _dim;
};

#endif
