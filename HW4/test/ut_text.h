#include "../src/text.h"

TEST(TEXT,render){
  Text t;
  ASSERT_EQ("<p style='color:#000000;font-size:16px;'></p>",t.render());
}

TEST(TEXT,setText){
  Text t;
  t.setText("test content");
  ASSERT_EQ("<p style='color:#000000;font-size:16px;'>test content</p>",t.render());
}

TEST(TEXT,setColor){
  Text t;
  t.setColor("#FF0800");
  ASSERT_EQ("<p style='color:#FF0800;font-size:16px;'></p>",t.render());
}

TEST(TEXT,setFontSize){
  Text t;
  t.setFontSize("20px");
  ASSERT_EQ("<p style='color:#000000;font-size:20px;'></p>",t.render());
}
