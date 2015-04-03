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
int p[1000][1000];

int find(char *s, int left, int right) {
  if (left == right) 
    return 1;
  else if (left > right)
    return 0;
  if (dp[left][right] != -1)
    return dp[left][right];

  if (s[left] == s[right]) {
    dp[left][right] = find(s, left+1, right-1) + 2;
    p[left][right] = 0;
  } else if (find(s, left+1, right) > find(s, left, right-1)) {
    dp[left][right] = find(s, left+1, right);
    p[left][right] = 1;
  } else if (find(s, left+1, right) <= find(s, left, right-1)) {
    dp[left][right] = find(s, left, right-1);
    p[left][right] = 2;
  }
  return dp[left][right];
}

void printSub(char *s, char *ans, int *index, int left, int right) {
  if (left == right)
    ans[(*index)++] = s[left];
  if (left < right) {
    if (p[left][right] == 0) {
      ans[(*index)++] = s[left];
      printSub(s, ans, index, left+1, right-1);
      ans[(*index)++] = s[left];
    }
    else if (p[left][right] == 1)
      printSub(s, ans, index, left+1, right);
    else if (p[left][right] == 2)
      printSub(s, ans, index, left, right-1);
  }
}

char *longestPalindrome(char *s) {
  memset(dp, -1, sizeof(dp));
  int max = find(s, 0, strlen(s)-1);
  char *ans = (char *)malloc(sizeof(char)*(max+1));
  int idx = 0;
  printSub(s, ans, &idx, 0, strlen(s)-1);
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

