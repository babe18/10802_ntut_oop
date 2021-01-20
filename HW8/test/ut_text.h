#include "../src/text.h"

TEST(TEXT, default_constructor){
  Text t;
  ASSERT_EQ("<p id='' style='color:#000000;font-size:16px;'></p>", t.render());
}

TEST(TEXT, constuctor){
  Text t("oop_text_001");
  ASSERT_EQ("<p id='oop_text_001' style='color:#000000;font-size:16px;'></p>", t.render());
}

TEST(TEXT, render){
  Text t;
  ASSERT_EQ("<p id='' style='color:#000000;font-size:16px;'></p>",t.render());
}

TEST(TEXT, set_text){
  Text t;
  t.setText("test content");
  ASSERT_EQ("<p id='' style='color:#000000;font-size:16px;'>test content</p>",t.render());
}

TEST(TEXT, set_color){
  Text t;
  t.setColor("#FF0800");
  ASSERT_EQ("<p id='' style='color:#FF0800;font-size:16px;'></p>",t.render());
}

TEST(TEXT, set_fontSize){
  Text t;
  t.setFontSize("20px");
  ASSERT_EQ("<p id='' style='color:#000000;font-size:20px;'></p>",t.render());
}
