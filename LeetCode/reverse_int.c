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
 *
 */

#include <stdio.h>
#include <stdlib.h>

double mypow(int base, int exp) {
  double sum = 1;
  for (int i = 0; i < exp; i++)
    sum *= base;
  return sum;
}

int reverse(int x) {
  int n = 0;
  int negative = 0;
  if (x < 0) {
    negative = 1;
    x = -x;
  }
  for (int temp = x / mypow(10, n); temp >= 10 || !temp; n+=2, temp = x / mypow(10, n)) {
    if (!temp) {
      n--;
      break;
    }
  }
  int sum = 0;
  int i;
  for (i = 0; i <= n; ++i) {
    sum += (x / (int)mypow(10, n-i)) * (int)mypow(10, i);
    x = x % (int)mypow(10, n-i);
  }
  //overflow
  if (sum < 0)
    return 0;
  if (negative)
    sum = -sum;
  return sum;
}

int main() {
  printf("%d\n", reverse(-2147483412));
  return 0;
}
