#include "../src/image.h"

TEST(IMAGE, default_constructor){
  Image i;
  ASSERT_EQ("<img id='' src='' style='top:0px;left:0px;position:absolute;'/>",i.render());
}

TEST(IMAGE, constructor){
  Image i("oop_img_001");
  ASSERT_EQ("<img id='oop_img_001' src='' style='top:0px;left:0px;position:absolute;'/>",i.render());
}

TEST(IMAGE, render){
  Image i;
  ASSERT_EQ("<img id='' src='' style='top:0px;left:0px;position:absolute;'/>",i.render());
}

TEST(IMAGE, set_href){
  Image i;
  i.setSrc("Hash Browns.png");
  ASSERT_EQ("<img id='' src='Hash Browns.png' style='top:0px;left:0px;position:absolute;'/>",i.render());
}

TEST(IMAGE, add_position_style){
  Image i;
  i.setSrc("Hash Browns.png");
  i.setPosition("100px","100px");
  ASSERT_EQ("<img id='' src='Hash Browns.png' style='top:100px;left:100px;position:absolute;'/>",i.render());
}
