/*
 * Given a string, find the length of the longest substring without repeating characters. 
 * For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
 * For "bbbbb" the longest substring is "b", with the length of 1.
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *   Create an array of size 512 to contain every characters.
 *   i.e. hash_table['a'] = the last index position + 1 of 'a' in string
 *   if hash collision happens, renew base index if it is larger.
 *
 *   Kind of like sliding window.
 *
 *   the return value is to prevent empty string
 *
 */

#include <stdio.h>

int lengthOfLongestSubstring(char *s) {
  int hash_table[512] = {0};
  int max = 0;
  int base = 0;
  int i = 0;
  while (s[i]) {
    if (hash_table[s[i]]) {
      if (base < hash_table[s[i]])
        base = hash_table[s[i]];
    }
    hash_table[s[i]] = i+1;

    if (i-base > max) {
      max = i-base;
    }
    //printf("base[%d] i[%d]\n", base, i);
    i++;
  }
  return s[0]? max+1 : max;
}

void test() {
  char s[] = {"abba"};
  printf("%d\n", lengthOfLongestSubstring(s));
}

int main() {
  test();
}
