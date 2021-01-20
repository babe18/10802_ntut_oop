#ifndef IMAGE_H
#define IMAGE_H

#include "tag.h"

class Image : public Tag{
public:
  Image():
    imageSrc(""),top("0px"),left("0px"){
  }

  Image(std::string id):
    imageSrc(""),top("0px"),left("0px"), Tag(id){
  }

  std::string render() const override{
    return "<img id='"+this->getId()+"' src='"+imageSrc+"' style='top:"+top+";left:"+left+";position:absolute;'/>";
  }

  void setPosition(std::string top, std::string left){
    this->top=top;
    this->left=left;
  }

  void setSrc(std::string imageSrc){
    this->imageSrc=imageSrc;
  }

private:
  std::string imageSrc;
  std::string top;
  std::string left;
};

#endif
