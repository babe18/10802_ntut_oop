#ifndef QUEUE_H
#define QUEUE_H

template<class T>
class Queue{

public:
  Queue(){
    this->_size = 0;
    this->_data = new T[this->_size];
  }

  ~Queue(){
    if(this->_data != nullptr){
      delete [] this->_data;
    }
  }

  void push(T const a){
    T *temp = this->_data;
    this->_data = new T[this->_size+1];
    for(int i=0 ; i<this->_size ; i++){
      this->_data[i] = temp[i];
    }
    this->_data[this->_size++] = a;
    delete [] temp;
  }

  T pop(){
    if(this->_size == 0){
      throw(std::string("empty queue"));
    }
    T *temp = this->_data;
    T result = temp[0];
    this->_data = new T[--this->_size];
    for(int i=0 ; i<this->_size ; i++){
      this->_data[i] = temp[i+1];
    }
    delete [] temp;
    return result;
  }

  T at(int index) const{
    if(0>index || index>this->_size-1){
      throw(std::string("out of range"));
    }
    return this->_data[index];
  }

  int size() const{
    return this->_size;
  }

  void clear(){
    if(this->_data != nullptr){
      delete [] this->_data;
    }
    this->_size = 0;
    this->_data = new T[this->_size];
  }
private:
  int _size;
  T *_data;
};

#endif
