#include "lib/googletest/googlemock/include/gmock/gmock.h"
#include "lib/googletest/googletest/include/gtest/gtest.h"

using namespace std;

TEST(TestGroup_Assert, Subtest_1) {
  ASSERT_TRUE(1 == 1);
  cout << "1 = 1" << endl;
}

TEST(TestGroupName_Expect, Subtest_1) {
  EXPECT_TRUE(1 == 2);
  cout << "1 = 2" << endl;
}

TEST(TestGroup_Assert, Subtest_2) {
  ASSERT_FALSE(1 == 1);
  cout << "1 = 1" << endl;
}

TEST(TestGroupName_Expect, Subtest_2) {
  EXPECT_FALSE(1 == 2);
  cout << "1 = 2" << endl;
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
