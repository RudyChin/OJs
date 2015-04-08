/*
 * Reverse digits of an integer.
 * Example1: x = 123, return 321
 * Example2: x = -123, return -321
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *   Make it positive and store the original sign
 *   Find number of digits (multiply by 100 each round to speed up)
 *   Loop through to extract digits from most significant one
 *   Check if it is overflow
 *
 */

#include <stdio.h>
#include <stdlib.h>

long mypow(int base, int exp) {
  long sum = 1;
  for (int i = 0; i < exp; i++)
    sum *= base;
  return sum;
}

int reverse(int x) {
  int n = 0, negative = 0;

  if (x < 0) {
    negative = 1;
    x = -x;
    //-2147483648
    if (x < 0)
      return 0;
  }
  //find number of digits
  for (int temp = x / mypow(10, n); temp >= 10 || !temp; n+=2, temp = x / mypow(10, n))
    if (!temp) {
      --n;
      break;
    }

  long sum = 0;
  int i;
  for (i = 0; i <= n; ++i) {
    sum += (x / mypow(10, n-i)) * mypow(10, i);
    x = x % mypow(10, n-i);
  }
  //overflow
  if (sum > (long)((1<<31)-1))
    return 0;
  if (negative)
    sum = -sum;
  return (int)sum;
}

int main() {
  printf("%d\n", reverse(-2147483648));
  return 0;
}
