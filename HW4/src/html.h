#ifndef HTML_H
#define HTML_H

#include "text.h"
#include "image.h"

#include<fstream>
#include<cstring>
#include<vector>

class Html{
public:

  void appendText(Text child){
    texts.push_back(child);
  }

  void appendImage(Image child){
    images.push_back(child);
  }

  std::string render(){
    std::string content="";
    for(Image i : images){
      content = content + i.render();
    }
    for(Text t : texts){
      content = content + t.render();
    }
    return html_head+content+html_end;
  }

  void outputHtml(){
     std::ofstream file;
     file.open("main.html");
     file<<this->render();
     file.close();
  }

private:
  std::vector<Text> texts;
  std::vector<Image> images;
  const std::string html_head="<HTML><body>";
  const std::string html_end="</body></HTML>";
};

#endif
