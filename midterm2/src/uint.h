#ifndef U_INT_H
#define U_INT_H

#include "binary.h"

class uInt{
public:
  static bool canConvert(Binary const & bits){
    return bits.size() <= 32;
  }

  uInt(Binary const & bits){
    if(uInt::canConvert(bits)){
      this->_b = bits.fillWithZero(32);
    }else{
      throw(std::runtime_error("the size is not suitable"));
    }
  }

  unsigned int toDec(){
    return _b.toDec();
  }

private:
  Binary _b;
};

#endif
