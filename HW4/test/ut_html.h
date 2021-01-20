#include "../src/html.h"
#include "../src/text.h"
#include "../src/image.h"

TEST(HTML_Main,render){
  Html h;
  ASSERT_EQ("<HTML><body></body></HTML>",h.render());
}

TEST(HTML_Main,appendText){
  Html h;
  Text t;
  t.setText("test");
  h.appendText(t);
  ASSERT_EQ("<HTML><body><p style='color:#000000;font-size:16px;'>test</p></body></HTML>",h.render());
}

TEST(HTML_Main,appendImage){
  Html h;
  Image i;
  i.setSrc("image1.png");
  h.appendImage(i);
  ASSERT_EQ("<HTML><body><img src='image1.png' style='top:0px;left:0px;position:absolute;'/></body></HTML>",h.render());
}

TEST(HTML_Main,appendMultiChild){
  Html h;
  Text t1;
  Text t2;
  Image i1;
  t1.setText("test1");
  t2.setText("test2");
  i1.setSrc("image1.png");
  h.appendText(t1);
  h.appendText(t2);
  h.appendImage(i1);
  ASSERT_EQ("<HTML><body><img src='image1.png' style='top:0px;left:0px;position:absolute;'/><p style='color:#000000;font-size:16px;'>test1</p><p style='color:#000000;font-size:16px;'>test2</p></body></HTML>",h.render());
}
