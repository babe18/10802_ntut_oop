#ifndef TEXT_H
#define TEXT_H

class Text{
public:
  Text():
    content(""){
  }

  std::string render(){
    return "<p>"+content+"</p>";
  }

  void setText(std::string content){
    this->content=content;
  }

private:
  std::string content;
};

#endif
