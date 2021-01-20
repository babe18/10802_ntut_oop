#ifndef TEXT_H
#define TEXT_H

class Text{
public:
  Text():
    content(""),color("#000000"),fontSize("16px"){
  }

  std::string render(){
    return "<p style='color:"+color+";font-size:"+fontSize+";'>"+content+"</p>";
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
