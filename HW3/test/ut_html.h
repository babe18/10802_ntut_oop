#include "../src/html.h"
#include "../src/text.h"

TEST(HTML_Main,render){
  Html h;
  ASSERT_EQ("<HTML><body></body></HTML>",h.render());
}

TEST(HTML_Main,appendChild){
  Html h;
  Text t;
  t.setText("test");
  h.appendChild(t);
  ASSERT_EQ("<HTML><body><p>test</p></body></HTML>",h.render());
}

TEST(HTML_Main,appendMultiChild){
  Html h;
  Text t1;
  Text t2;
  Text t3;
  t1.setText("test1");
  t2.setText("test2");
  t3.setText("test3");
  h.appendChild(t1);
  h.appendChild(t2);
  h.appendChild(t3);
  ASSERT_EQ("<HTML><body><p>test1</p><p>test2</p><p>test3</p></body></HTML>",h.render());
}
