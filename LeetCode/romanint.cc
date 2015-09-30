/* 
 * Given a roman numeral, convert it to an integer.
 * Input is guaranteed to be within the range from 1 to 3999.
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *    A recursive solution.
 *    on the input string, search the largest charater in the string
 *    minu the left side of that string (recursively)
 *    plus the right side of that string (recursively)
 *    plus the value of itself
 *
 *    return 0 if left's length equals right's length
 *    else check whether it is below 3 charaters (since the roman representation
 *    allows three same characters in a row)
 *    if below 3 and they are all identical, then calculate that answer out
 *    else if they are different, compute recursively
 *
 */

#include <gtest/gtest.h>
#include <iostream>
#include <vector>

using namespace std;

class Solution : public ::testing::Test {
protected:
  int interpret(char roman) {
    switch (roman) {
      case 'I':
        return 1;
      case 'V':
        return 5;
      case 'X':
        return 10;
      case 'L':
        return 50;
      case 'C':
        return 100;
      case 'D':
        return 500;
      case 'M':
        return 1000;
    } 
  }

  int calculate(int l, int r, string &s) {
    if (l >= r)
      return 0;
    else if (r-l == 1)
      return interpret(s[l]);
    else if (r-l == 2 && s[l] == s[l+1])
      return 2*interpret(s[l]);
    else if (r-l == 3 && s[l] == s[l+1] && s[l] == s[l+2])
      return 3*interpret(s[l]);

    int max = 0;
    int maxi = 0;
    for (int i = l; i < r; ++i) {
      if (interpret(s[i]) > max) {
        max = interpret(s[i]);
        maxi = i;
      }
    }
    return interpret(s[maxi]) + calculate(maxi+1, r, s) - calculate(l, maxi, s);
  }

public:
  int romanToInt(string s) {
    int sum = 0;
    sum = calculate(0, s.length(), s);
    return sum;
  }
};

TEST_F(Solution, romanToInt) {
  ASSERT_EQ(9, romanToInt("IX"));
  ASSERT_EQ(1, romanToInt("I"));
  ASSERT_EQ(100, romanToInt("C"));
  ASSERT_EQ(98, romanToInt("XCVIII"));
  ASSERT_EQ(20, romanToInt("XX"));
  ASSERT_EQ(19, romanToInt("XIX"));
}
