/*
 * Determine whether an integer is a palindrome. Do this without extra space.
 * 
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *   Negative numbers can't be palindromic
 *   First calculate how many digits are there
 *   Then loop through to compare First and Last digit
 *
 */
#include <stdio.h>

#define ASSERT_EQ(X, Y) \
  do { \
    if ((X) == (Y)) \
      printf("%s\n", "Pass"); \
    else \
      printf("%s\n", "Fail"); \
  } while (0)

int pow(int base, int exp)
{
  int sum = 1;
  while (exp--)
    sum *= base; 
  return sum;
}

int calDigits(int x)
{
  int d = 1;
  while (x > 9)
  {
    x/=10;
    d++;
  }
  return d;
}

bool isPalindrome(int x) {
  if (x < 0) return false;
  int digits = calDigits(x);
  int i;
  for (i = digits-1; i > 0; i-=2)
  {
    if ((x / pow(10, i)) != (x % 10))
      return false;
    x %= pow(10, i);
    x /= 10;
  }
  return true;
}

void testIsPalindrome()
{
  ASSERT_EQ(isPalindrome(12321), true);
  ASSERT_EQ(isPalindrome(1), true);
  ASSERT_EQ(isPalindrome(0), true);
  ASSERT_EQ(isPalindrome(111111), true);
  ASSERT_EQ(isPalindrome(123456), false);
  ASSERT_EQ(isPalindrome(2147483647), false);
  ASSERT_EQ(isPalindrome(-23432), false);
  ASSERT_EQ(isPalindrome(-238432), false);
  ASSERT_EQ(isPalindrome(-2147483648), false);
  ASSERT_EQ(isPalindrome(-2147447412), false);
}

void testCalDigits()
{
  ASSERT_EQ(calDigits(12345678), 8); 
  ASSERT_EQ(calDigits(12321), 5); 
}

int main(int argc, char *argv[])
{
  printf("calDigits()\n");
  testCalDigits();
  printf("isPalindrome()\n");
  testIsPalindrome();
  return 0;
}
