#include<iostream>

#include "html.h"
#include "text.h"
#include "image.h"
#include "color.h"
#include "size.h"
#include "color.h"
#include "fontsize.h"
#include "position.h"

int main(){
  Html h;
  Text t1;
  Text t2;
  Image i;
  t1.setText("Hello, World");
  t1.addStyle(new Color("#FF0800"));
  t2.setText("This is a Hash Browns :D");
  t2.addStyle(new FontSize(32));
  i.setSrc("Hash Browns.png");
  i.addStyle(new Size(200, 200));
  i.addStyle(new Position(200));
  h.appendTag(&t1);
  h.appendTag(&t2);
  h.appendTag(&i);
  h.outputHtml();
  std::cout << "output successful" << std::endl;
  return 0;
}
