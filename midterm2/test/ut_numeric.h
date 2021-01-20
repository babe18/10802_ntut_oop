#include "../src/binary.h"
#include "../src/uint.h"
#include "../src/ushort.h"
#include "../src/uchar.h"

class NumericTest : public ::testing::Test {
protected:
    void SetUp() {
      int b1[] = {1,0,0,0};
      int b2[] = {1,1,1,1,0,0,1,1};
      int b3[] = {0,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1};
      int b4[] = {0,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1};
      int b5[] = {0,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1,1,1,0,0,1,1,0,1};
      bin1 = new Binary(b1,4);
      bin2 = new Binary(b2,8);
      bin3 = new Binary(b3,16);
      bin4 = new Binary(b4,32);
      bin5 = new Binary(b5,34);
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

TEST_F(NumericTest, uIntCanConvertTest){
  ASSERT_TRUE(uInt::canConvert(*bin1));
  ASSERT_TRUE(uInt::canConvert(*bin2));
  ASSERT_TRUE(uInt::canConvert(*bin3));
  ASSERT_TRUE(uInt::canConvert(*bin4));
  ASSERT_FALSE(uInt::canConvert(*bin5));
}

TEST_F(NumericTest, uShortCanConvertTest){
  ASSERT_TRUE(uShort::canConvert(*bin1));
  ASSERT_TRUE(uShort::canConvert(*bin2));
  ASSERT_TRUE(uShort::canConvert(*bin3));
  ASSERT_FALSE(uShort::canConvert(*bin4));
  ASSERT_FALSE(uShort::canConvert(*bin5));
}

TEST_F(NumericTest, charCanConvertTest){
  ASSERT_TRUE(uChar::canConvert(*bin1));
  ASSERT_TRUE(uChar::canConvert(*bin2));
  ASSERT_FALSE(uChar::canConvert(*bin3));
  ASSERT_FALSE(uChar::canConvert(*bin4));
  ASSERT_FALSE(uChar::canConvert(*bin5));
}

TEST_F(NumericTest, uIntConvert){
  uInt i1(*bin1);
  ASSERT_EQ(8, i1.toDec());
  uInt i2(*bin2);
  ASSERT_EQ(243, i2.toDec());
  uInt i3(*bin3);
  ASSERT_EQ(29555, i3.toDec());
  uInt i4(*bin4);
  ASSERT_EQ(1936946035, i4.toDec());
}

TEST_F(NumericTest, uIntConvertException){
  ASSERT_ANY_THROW(uInt i(*bin5));
}

TEST_F(NumericTest, uShortConvert){
  uShort s1(*bin1);
  ASSERT_EQ(8, s1.toDec());
  uShort s2(*bin2);
  ASSERT_EQ(243, s2.toDec());
  uShort s3(*bin3);
  ASSERT_EQ(29555, s3.toDec());
}

TEST_F(NumericTest, uShortConvertException){
  ASSERT_ANY_THROW(uShort s(*bin4));
  ASSERT_ANY_THROW(uShort s(*bin5));
}

TEST_F(NumericTest, charConvert){
  uChar c1(*bin1);
  ASSERT_EQ('\b', c1.toChar());
  uChar c2(*bin2);
  ASSERT_EQ('\xF3', c2.toChar());
}

TEST_F(NumericTest, charConvertException){
  ASSERT_ANY_THROW(uChar c(*bin3));
  ASSERT_ANY_THROW(uChar c(*bin4));
  ASSERT_ANY_THROW(uChar c(*bin5));
}
