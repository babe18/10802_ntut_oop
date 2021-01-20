#include "../src/binary.h"

class BinaryTest : public ::testing::Test {
protected:
  void SetUp() {
    int b1[] = {1,0,0,0,1,1,0};
    int b2[] = {0,1,1,1,0,0,1};
    int b3[] = {1,1,1,1,0,0,1};
    int b4[] = {1,0,0,1,0,0,1};
    int b5[] = {1,0,1,1,0,0,1};
    bin1 = new Binary(b1,7);
    bin2 = new Binary(b2,7);
    bin3 = new Binary(b3,7);
    bin4 = new Binary(b4,7);
    bin5 = new Binary(b5,7);
  }
  void TearDown(){
    delete bin1;
    delete bin2;
    delete bin3;
    delete bin4;
    delete bin5;
  }
  Binary *bin1, *bin2, *bin3, *bin4, *bin5;
};

TEST_F(BinaryTest, defaultConstructor){
  Binary b;
  ASSERT_ANY_THROW(b.at(0));
}

TEST_F(BinaryTest, constructor){
  ASSERT_EQ(1, bin1->at(0));
}

TEST_F(BinaryTest, constructorException){
  int b[]={1,2,1,1,0};
  ASSERT_ANY_THROW(Binary(b,5));
}

TEST_F(BinaryTest, copyConstructor){
  Binary b(*bin1);
  ASSERT_EQ(7, b.size());
  ASSERT_EQ(1, b.at(0));
  ASSERT_EQ(0, b.at(1));
  ASSERT_EQ(0, b.at(2));
  ASSERT_EQ(0, b.at(3));
  ASSERT_EQ(1, b.at(4));
  ASSERT_EQ(1, b.at(5));
  ASSERT_EQ(0, b.at(6));
}

TEST_F(BinaryTest, operatorAssignment){
  Binary b = *bin1;
  ASSERT_EQ(7, b.size());
  ASSERT_EQ(1, b.at(0));
  ASSERT_EQ(0, b.at(1));
  ASSERT_EQ(0, b.at(2));
  ASSERT_EQ(0, b.at(3));
  ASSERT_EQ(1, b.at(4));
  ASSERT_EQ(1, b.at(5));
  ASSERT_EQ(0, b.at(6));
}

TEST_F(BinaryTest, atExceptionTest){
  ASSERT_ANY_THROW(bin1->at(8));
  ASSERT_ANY_THROW(bin1->at(-1));
}

TEST_F(BinaryTest, toDemicalTest){
  ASSERT_EQ(70, bin1->toDec());
  ASSERT_EQ(57, bin2->toDec());
  ASSERT_EQ(121, bin3->toDec());
  ASSERT_EQ(73, bin4->toDec());
  ASSERT_EQ(89, bin5->toDec());
}

TEST_F(BinaryTest, sizeTest){
  ASSERT_EQ(7, bin1->size());
}

TEST_F(BinaryTest, fillWithZeroTest){
  Binary b = bin1->fillWithZero(10);
  ASSERT_EQ(10, b.size());
  ASSERT_EQ(0, b.at(0));
  ASSERT_EQ(0, b.at(1));
  ASSERT_EQ(0, b.at(2));
  ASSERT_EQ(1, b.at(3));
  ASSERT_EQ(0, b.at(4));
  ASSERT_EQ(0, b.at(5));
  ASSERT_EQ(0, b.at(6));
  ASSERT_EQ(1, b.at(7));
  ASSERT_EQ(1, b.at(8));
  ASSERT_EQ(0, b.at(9));
}

TEST_F(BinaryTest, fillWithZeroExceptionTest){
  ASSERT_ANY_THROW(bin1->fillWithZero(3));
}
