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
 *
 */

int checkPalindrome(char *s, int index, int n) {
  int shift = !(n % 2);
  for (int i = 0; i < (n-1+shift)/2; i++)
    if (s[index-i] != s[index+i+shift])
      return 0;
  return 1;
}

char *longestPalindrome(char *s) {
  int length = strlen(s);    
  int isOdd = length % 2;
  int mid = (length-1)/2;
  int max = 0;
  int max_begin = 0;
  int max_end = 0;
  
  for (int i = mid; i >= 0; i--) {
    for (int j = (i+1)*2-isOdd; j >= 1; j--) {
      if (max > j) {
        break;
      }
      if (checkPalindrome(s, i, j)) {
        if (max < j) { 
          max = j;
          max_begin = i - j/2 + !(j%2);
          max_end = i + j/2;
          break;
        }
      }
    }
  }
  for (int i = mid+1; i < length; i++) {
    for (int j = (length-i)*2; j >= 1; j--) {
      if (max > j) {
        break;
      }
      if (checkPalindrome(s, i, j)) {
        if (max < j) { 
          max = j;
          max_begin = i - j/2 + !(j%2);
          max_end = i + j/2;
          break;
        }
      }
    }
  }

  char *ans = (char *)malloc(sizeof(char)*(max+1));
  int idx = 0;
  for (int i = max_begin; i <= max_end; i++) {
    ans[idx++] = s[i];
  }
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

