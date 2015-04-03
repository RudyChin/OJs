/*
 * Given a string S, find the longest palindromic substring in S. 
 * You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solution:
 *   Use dynamic programming to save information of substring length
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int dp[1000][1000];

char *longestPalindrome(char *s) {
  memset(dp, -1, sizeof(dp));
  int start = 0;
  int end = 0;
  int max = 0;
  int length = strlen(s);
  for (int i = length-1; i >= 0; --i) {
    for (int j = i; j < length; ++j) {
      dp[i][j] = (s[i] == s[j]) && (j - i < 2 || dp[i+1][j-1]);
      if (dp[i][j]) {
        if (max < j - i + 1) {
          max = j - i + 1;
          start = i;
          end = j;
        }
      }
    }
  }

  char *ans = (char *)malloc(sizeof(char)*(max+1));
  int idx = 0;
  for (int i = start; i <= end; ++i)
    ans[idx++] = s[i];
  ans[idx] = '\0';
  return ans;
}


void test() {
  char s[] = "abcvbgbvc";
  char *ans = longestPalindrome(s);
  printf("%s\n", ans);
}

int main() {
  test();
  return 0;
}

