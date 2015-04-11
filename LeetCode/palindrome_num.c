/*
 * Determine whether an integer is a palindrome. Do this without extra space.
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
  int digits = calDigits(x);
  int i;
  for (i = 0; i < digits; ++i)
  {
    if ((x % pow(10, digits-i-1)) != (x % pow(10, i)))
      return false;
  }
  return true;
}

void assert(int num, bool expected)
{
  bool pass = (isPalindrome(num)==expected);
  printf("Test:[%d] Result:[%s]\n", num, pass?"Pass":"Fail"); 
  if (!pass)
  {
    printf("Output:[%s] Expected:[%s]\n\n", isPalindrome(num)?"True":"False", expected?"True":"False"); 
  }
}

void testIsPalindrome()
{
  assert(12321, true);
  assert(1, true);
  assert(0, true);
  assert(111111, true);
  assert(123456, false);
  assert(2147483647, false);
}

int main(int argc, char *argv[])
{
  testIsPalindrome();
  return 0;
}
