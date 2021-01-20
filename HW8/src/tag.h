#ifndef TAG_H
#define TAG_H

#include <cstring>

class Tag{
public:
  virtual std::string render() const = 0;

  Tag(){
    this->id = "";
  }

  Tag(std::string id){
    this->id = id;
  }

  std::string getId() const{
    return this->id;
  }

private:
  std::string id;

};

#endif
