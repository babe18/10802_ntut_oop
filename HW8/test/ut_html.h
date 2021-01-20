#include "../src/html.h"
#include "../src/text.h"
#include "../src/image.h"

TEST(HTML, render){
  Html h;
  ASSERT_EQ("<HTML><body></body></HTML>",h.render());
}

TEST(HTML, append_text){
  Html h;
  Text t;
  t.setText("test");
  h.appendTag(&t);
  ASSERT_EQ("<HTML><body><p id='' style='color:#000000;font-size:16px;'>test</p></body></HTML>",h.render());
}

TEST(HTML, append_image){
  Html h;
  Image i;
  i.setSrc("image1.png");
  h.appendTag(&i);
  ASSERT_EQ("<HTML><body><img id='' src='image1.png' style='top:0px;left:0px;position:absolute;'/></body></HTML>",h.render());
}

TEST(HTML, append_multiChild){
  Html h;
  Text t1;
  Text t2;
  Image i1;
  t1.setText("test1");
  t2.setText("test2");
  i1.setSrc("image1.png");
  h.appendTag(&t1);
  h.appendTag(&t2);
  h.appendTag(&i1);
  ASSERT_EQ("<HTML><body><p id='' style='color:#000000;font-size:16px;'>test1</p><p id='' style='color:#000000;font-size:16px;'>test2</p><img id='' src='image1.png' style='top:0px;left:0px;position:absolute;'/></body></HTML>",h.render());
}
