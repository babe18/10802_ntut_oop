#include<iostream>

#include "./html.h"
#include "./text.h"
#include "./image.h"

int main(){
  Html h;
  Text t1;
  Text t2;
  Image i;
  t1.setText("Hello, World");
  t1.setColor("#FF0800");
  t2.setText("This is a Hash Browns :D");
  t2.setFontSize("32px");
  i.setSrc("Hash Browns.png");
  i.setPosition("200px","0px");
  h.appendTag(&t1);
  h.appendTag(&t2);
  h.appendTag(&i);
  h.outputHtml();
  std::cout << "output successful" << std::endl;
  return 0;
}
