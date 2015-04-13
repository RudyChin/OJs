/*
 * Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
 * n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 * Find two lines, which together with x-axis forms a container, such that the container contains the most water.
 * 
 * Note: You may not slant the container.
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *
 */

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution : public ::testing::Test {
  public:
    int maxArea(vector<int> &height) {
      int sum = 0;
      int smaller;
      for (int i = 0; i < height.size()-1; i++) {
        for (int j = i+1; j < height.size(); j++) {
          smaller = height[i]>height[j]?height[j]:height[i];
          if (sum < smaller*(j-i))
            sum = smaller*(j-i);
        } 
      }
      return sum;
    }
};

TEST_F(Solution, test) {
  vector<int> testVec;
  testVec.push_back(1);
  testVec.push_back(2);
  EXPECT_EQ(1, maxArea(testVec)); 
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
