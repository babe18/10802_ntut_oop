#ifndef TEXT_H
#define TEXT_H

#include "tag.h"

class Text : public Tag{
public:
  Text(std::string id = ""):Tag(id){}

  std::string render() const override{
    return "<p id='"+this->getId()+"' "+this->getStyle()+">"+content+"</p>";
  }

  void setText(std::string content){
    this->content=content;
  }

private:
  std::string content;
};

#endif
