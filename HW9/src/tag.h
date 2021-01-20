#ifndef TAG_H
#define TAG_H

#include "style.h"

#include <vector>
#include <cstring>

class Tag{
public:
  virtual std::string render() const = 0;
  void addStyle(Style *s){
    styles.push_back(s);
  };

  Tag(){
    this->id = "";
  }

  Tag(std::string id){
    this->id = id;
  }

  ~Tag(){
    for(Style *s : styles){
      delete s;
    }
  }

  std::string getId() const{
    return this->id;
  }

protected:
  std::string getStyle() const{
    std::string style="";
    for(Style *s : styles){
      style = style + s->renderStyle();
    }
    return "style='"+style+"'";
  }

private:
  std::string id;
  std::vector<Style*> styles;
};

#endif
