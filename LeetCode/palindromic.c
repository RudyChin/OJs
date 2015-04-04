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

int z[2002];

int match(char *s, int N, int l, int r) {
  int i = 0;
  while (l-i >= 0 && r+i < N && s[l-i] == s[r+i])
    i++;
  return i;
}

char *longestPalindrome(char *s) {
  memset(z, -1, sizeof(z));
  int n = strlen(s);
  int n2 = 2*n+1;
  char *extendN = (char *)malloc(sizeof(char)*n2);

  //initialization
  memset(extendN, '.', sizeof(char)*n2);
  for (int i = 0; i < n; i++) {
    extendN[i*2+1] = s[i];
  }

  //computation
  int coverM = 0, coverR = 0;
  int mirror = 0;
  int max = 0, maxp = 0;
  for (int i = 0; i < n2; i++) {
    mirror = coverM - (i - coverM);
    if (i > coverR) {
      z[i] = match(extendN, n2, i, i);
      if (max < z[i]) {
        max = z[i];
        maxp = i;
      }
      coverM = i;
      coverR = i + z[i] - 1;
    } else if (z[mirror] + i - 1 == coverR) {
      z[i] = z[mirror] + match(extendN, n2, i-z[mirror], i+z[mirror]);
      if (max < z[i]) {
        max = z[i];
        maxp = i;
      }
      coverM = i;
      coverR = i + z[i] - 1;
    } else {
      z[i] = z[mirror] < (coverR - i + 1) ? z[mirror] : (coverR - i + 1);
    }
  }

  char *ans = (char *)malloc(sizeof(char)*((max-1)/2)+1);
  int idx = 0;
  for (int i = maxp-(z[maxp]-1); i <= maxp+(z[maxp]-1); i++) {
    if (extendN[i] != '.')
      ans[idx++] = extendN[i];
  }
  ans[idx] = '\0';

  return ans;

}


void test() {
  char s[] = "bb";
  char *ans = longestPalindrome(s);
  printf("%s\n", ans);
}

int main() {
  test();
  return 0;
}

