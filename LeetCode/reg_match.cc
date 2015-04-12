/*
 * Implement regular expression matching with support for '.' and '*'.
 * '.' Matches any single character.
 * '*' Matches zero or more of the preceding element.
 *
 * The matching should cover the entire input string (not partial).
 * The function prototype should be:
 * 
 * bool isMatch(const char *s, const char *p)
 * 
 * Some examples:
 * isMatch("aa","a") → false
 * isMatch("aa","aa") → true
 * isMatch("aaa","aa") → false
 * isMatch("aa", "a*") → true
 * isMatch("aa", ".*") → true
 * isMatch("ab", ".*") → true
 * isMatch("aab", "c*a*b") → true
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *   Extend original string and pattern, add '!' in begin and end
 *   Use strstr to find
 *   TODO:
 *   reg_exp operators, i.e. '.', '*' ...
 *
 */

#include <iostream>
#include <string.h>
#include <gtest/gtest.h>

using namespace std;

class Solution : public ::testing::Test {
public:
    bool isMatch(const char *s, const char *p) {
      char *extS, *extP, *tmp;
      extS = (char *)malloc(sizeof(char)*(strlen(s)+2));
      extP = (char *)malloc(sizeof(char)*(strlen(p)+2));
      
      int i, j;
      for (i = 0, j = 0; i < strlen(s)+2; ++i) { if (!i || i == strlen(s)+1)
          extS[i] = '!';
        else
          extS[i] = s[j++];
      }
      for (i = 0, j = 0; i < strlen(p)+2; ++i) {
        if (!i || i == strlen(p)+1)
          extP[i] = '!';
        else
          extP[i] = p[j++];
      }

      tmp = strstr(extS, extP);

      if (tmp == NULL)
        return false;
      else
        return true;
    }
};

TEST_F(Solution, test) {
  EXPECT_EQ(isMatch("aaa", "a"), false); 
  EXPECT_EQ(isMatch("aaa", "aaa"), true); 
}

int main(int argc, char *argv[])
{
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
