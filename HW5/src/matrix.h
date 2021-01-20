#ifndef MATRIX_H
#define MATRIX_H
#include "math_vector.h"

class Matrix {
public:
  Matrix(MathVector a[], int row, int col){
    this->_row = row;
    this->_col = col;
    this->_m = new MathVector[_row];
    for(int i=0 ; i<_row ; i++){
      if(a[i].dimension() != this->_col){
        throw(std::string("dimension not match"));
      }
      this->_m[i] = a[i];
    }
  }

  Matrix(Matrix const & a){
    this->_row = a._row;
    this->_col = a._col;
    this->_m = new MathVector[_row];
    for(int i=0 ; i<_row ; i++){
      this->_m[i] = a._m[i];
    }
  }

  ~Matrix() {
    if(_m){
      delete [] _m;
    }
  }

  double at(int row, int col) const {
    return this->_m[row-1][col-1];
  }

  void rowReduction(){
    for(int i=0 ; i<this->_row ; i++){
      if(this->_m[i][i] == 0) continue;
      this->_m[i] = this->_m[i].scale(1/this->_m[i][i]);
      for(int j=i+1 ; j<this->_row ; j++){
        MathVector sub = this->_m[i].scale(-1*this->_m[j][i]);
        this->_m[j] = this->_m[j] + sub;
      }
    }
  }

  void backSubstitution(){
    for(int i=this->_row-1 ; i>=0 ; i--){
      for(int j=i-1 ; j>=0 ; j--){
        MathVector sub = this->_m[i].scale(-1*this->_m[j][i]);
        this->_m[j] = this->_m[j] + sub;
      }
    }
  }

  MathVector gaussianElimination(){
    this->rowReduction();

    if(this->at(this->_row, this->_col-1) == 0){
      if(this->at(this->_row, this->_col) == 0){
        throw(std::string("infinite solution"));
      }else{
        throw(std::string("no solution"));
      }
    }

    this->backSubstitution();

    MathVector result(this->_row);
    for(int i = 0; i < this->_row; i++) {
      result[i] = this->_m[i][this->_col-1];
    }
    return result;
  }


private:
  int _row;
  int _col;
  MathVector *_m;
};

#endif
