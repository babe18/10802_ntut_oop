#include<iostream>

#include "./html.h"
#include "./text.h"

int main(){
  Html h;
  Text t1;
  Text t2;
  t1.setText("Hello, World");
  t2.setText("This is a simple ui output");
  h.appendChild(t1);
  h.appendChild(t2);
  h.outputHtml();
  std::cout << "output successful" << std::endl;
  return 0;
}
