#ifndef U_SHORT_H
#define U_SHORT_H

#include "binary.h"

class uShort{
public:
  static bool canConvert(Binary const & bits){
    return bits.size() <= 16;
  }

  uShort(Binary const & bits){
    if(canConvert(bits)){
      this->_b = bits.fillWithZero(16);
    }else{
      throw(std::runtime_error("the size is not suitable"));
    }
  }

  unsigned short toDec(){
      return _b.toDec();
  }

private:
    Binary _b;
};

#endif
