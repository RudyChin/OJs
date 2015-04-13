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
      int size = height.size();
      int sum = 0;
      for (int i = 0; i < size; ++i) {
        int bigger = 0;
        int headFirst = (size-1-i < i? i : size-1-i);
        if (headFirst) {
          //from head
          for (int j = 0; j < i; ++j) {
            if (height[j] > height[i]) {
              bigger = i-j;
              if (sum < height[i] * (i-j))
                sum = height[i] * (i-j);
              break;
            }
          }
          //from tail
          for (int j = size-1; j > i; --j) {
            if (bigger > j-i)
              break;
            else {
              if (height[j] > height[i]) {
                if (sum < height[i] * (j-i))
                  sum = height[i] * (j-i);
                break;
              }
            }
          }
        } else {
          //from tail
          for (int j = size-1; j > i; --j) {
            if (height[j] > height[i]) {
              bigger = j-i;
              if (sum < height[i] * (j-i))
                sum = height[i] * (j-i);
              break;
            }
          }
          //from head
          for (int j = 0; j < i; ++j) {
            if (bigger > i-j)
              break;
            else {
              if (height[j] > height[i]) {
                if (sum < height[i] * (i-j))
                  sum = height[i] * (i-j);
                break;
              }
            }
          }
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
