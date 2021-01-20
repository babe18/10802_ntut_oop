#ifndef HTML_H
#define HTML_H

#include "tag.h"

#include<fstream>
#include<cstring>
#include<vector>

class Html{
public:
  void appendTag(Tag *child){
    tags.push_back(child);
  }

  std::string render(){
    std::string content="";
    for(Tag *t : tags){
      content = content + t->render();
    }
    return html_head + content + html_end;
  }

  void outputHtml(){
     std::ofstream file;
     file.open("main.html");
     file << this->render();
     file.close();
  }

private:
  std::vector<Tag*> tags;
  const std::string html_head="<HTML><body>";
  const std::string html_end="</body></HTML>";
};

#endif
