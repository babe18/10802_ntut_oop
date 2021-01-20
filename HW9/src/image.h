#ifndef IMAGE_H
#define IMAGE_H

#include "tag.h"

class Image : public Tag{
public:
  Image(std::string id = ""):Tag(id){}

  std::string render() const override{
    return "<img id='"+this->getId()+"' src='"+imageSrc+"' "+this->getStyle()+"/>";
  }

  void setSrc(std::string imageSrc){
    this->imageSrc=imageSrc;
  }

private:
  std::string imageSrc;
};

#endif
