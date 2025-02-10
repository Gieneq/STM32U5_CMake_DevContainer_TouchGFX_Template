// #include <iostream>
// using namespace std;

// int main() {
//     cout << "Hello from host" << endl;
//     return 0;
// }

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(OtherTest, OtherAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(1 * 1, 1);
}