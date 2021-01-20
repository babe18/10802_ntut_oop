#include "../src/text.h"

TEST(TEXT,render){
  Text t;
  ASSERT_EQ("<p></p>",t.render());
}

TEST(TEXT,setText){
  Text t;
  t.setText("test content");
  ASSERT_EQ("<p>test content</p>",t.render());
}
