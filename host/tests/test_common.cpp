// #include <iostream>
// using namespace std;

// int main() {
//     cout << "Hello from host" << endl;
//     return 0;
// }

#include <gtest/gtest.h>

// Demonstrate some basic assertions.
TEST(HelloTest, BasicAssertions) {
  // Expect two strings not to be equal.
  EXPECT_STRNE("hello", "world");
  // Expect equality.
  EXPECT_EQ(7 * 6, 42);
}