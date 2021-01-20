#ifndef TEXT_H
#define TEXT_H

#include "tag.h"

class Text : public Tag{
public:
  Text():
    content(""),color("#000000"),fontSize("16px"){
  }

  Text(std::string id):
    content(""),color("#000000"),fontSize("16px"), Tag(id){
  }

  std::string render() const override{
    return "<p id='"+this->getId()+"' style='color:"+color+";font-size:"+fontSize+";'>"+content+"</p>";
  }

  void setColor(std::string color){
    this->color=color;
  }

  void setFontSize(std::string fontSize){
    this->fontSize=fontSize;
  }

  void setText(std::string content){
    this->content=content;
  }

private:
  std::string content;
  std::string color;
  std::string fontSize;
};

#endif
