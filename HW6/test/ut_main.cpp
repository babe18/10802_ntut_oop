#define TEST
#include <gtest/gtest.h>

#include "./ut_queue.h"

int main(int argc, char * argv[]) {
  testing::InitGoogleTest( &argc, argv);
  return RUN_ALL_TESTS();
}
