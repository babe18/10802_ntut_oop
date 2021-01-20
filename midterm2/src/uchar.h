#ifndef U_CHAR_H
#define U_CHAR_H

#include "binary.h"

class uChar{
public:
  static bool canConvert(Binary const & bits){
    return bits.size() <= 8;
  }

  uChar(Binary const & bits){
    if(canConvert(bits)){
      this->_b = bits.fillWithZero(8);
    }else{
      throw(std::runtime_error("the size is not suitable"));
    }
  }

  char toChar(){
      return (char)_b.toDec();
  }

private:
  Binary _b;
};

#endif
