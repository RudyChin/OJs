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
 *   Use two pointers to point to the first and the last element ('L'eft and
 *   'R'ight)
 *   While L != R
 *   Compare a[L] and a[R] and modify max if necessary
 *   If a[L] is smaller than a[R], which means a[R] still have chances to have
 *   larger area, move pointer L, on the other hand, move R.
 *
 */

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution : public ::testing::Test {
  public:
    int maxArea(vector<int> &height) {
      int L = 0, R = height.size()-1;
      int max = 0;
      while (L != R) {
        if (height[L] < height[R]) {
          if (max < height[L] * (R-L))
            max = height[L] * (R-L);
          ++L;
        } else {
          if (max < height[R] * (R-L))
            max = height[R] * (R-L);
          --R;
        }
      }
      return max;
    }
};

TEST_F(Solution, test) {
  vector<int> testVec;
  testVec.push_back(1);
  testVec.push_back(2);
  EXPECT_EQ(1, maxArea(testVec)); 
  testVec.push_back(3);
  testVec.push_back(4);
  testVec.push_back(5);
  EXPECT_EQ(6, maxArea(testVec)); 
  testVec.clear();
  testVec.push_back(5);
  testVec.push_back(4);
  testVec.push_back(3);
  testVec.push_back(2);
  testVec.push_back(1);
  EXPECT_EQ(6, maxArea(testVec)); 
}
