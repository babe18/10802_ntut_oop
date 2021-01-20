#include "../src/image.h"

TEST(IMAGE,render){
  Image i;
  ASSERT_EQ("<img src='' style='top:0px;left:0px;position:absolute;'/>",i.render());
}

TEST(IMAGE,setHref){
  Image i;
  i.setSrc("Hash Browns.png");
  ASSERT_EQ("<img src='Hash Browns.png' style='top:0px;left:0px;position:absolute;'/>",i.render());
}

TEST(IMAGE,addStyle_Position){
  Image i;
  i.setSrc("Hash Browns.png");
  i.setPosition("100px","100px");
  ASSERT_EQ("<img src='Hash Browns.png' style='top:100px;left:100px;position:absolute;'/>",i.render());
}
