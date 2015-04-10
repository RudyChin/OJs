/* 
 * Implement atoi to convert a string to an integer.
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *   Parse the string first to get start and end of digits
 *   Pass sign, start, end into a function to loop throught the string and
 *   calculate the sum
 *
 *   (On Leetcode only)
 *   if the value exceeds integer's maximum, return maximum
 *   if the value below integer's minimun, return minumum 
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INT_MAX (2147483647)
#define INT_MIN (-2147483648)

long lpow(int base, int exp)
{
  long sum = 1;
  int i;
  for (i = 0; i < exp; ++i)
  {
    sum *= base;
  }
  return sum;
}

long calculate(char *str, int start, int end)
{
  long sum = 0;
  for (int i = start; i < end; ++i) 
    sum += (str[i]-'0') * lpow(10, end-i-1); 
  return sum;
}

void parse(char *str, int *start, int *end, int *negative)
{
  int length = strlen(str);
  int s = 0, e = length;
  *negative = 0;

  while (str[s] == ' ' || str[s] == '\t')
    s++;
  if (str[s] == '-' || str[s] == '+') 
  {
    if (str[s] == '-')
      *negative = 1;
    s++;
  }
  for (int i = s; i < length; ++i)
    if (str[i] - '0' < 0 || str[i] - '0' > 9) {
      e = i; 
      break;
    }
  *start = s;
  *end = e;
}

int myAtoi(char *str) 
{
  int negative, start, end;
  long sum;

  parse(str, &start, &end, &negative);
  if (end-start > 10) {
    if (negative)
      return INT_MIN;
    else
      return INT_MAX;
  }
  sum = calculate(str, start, end); 
  if (negative)
    sum = -sum;
  if (sum > INT_MAX) return INT_MAX;
  if (sum < INT_MIN) return INT_MIN;

  return (int)sum;
}

void printCmp(char *str)
{
  int pass = 0;
  pass = (myAtoi(str) == atoi(str));
  printf("test:[%s] result:[%s]\n", str, pass?"pass":"fail");
  if (!pass)
  {
    printf("Output:[%d] Expected:[%d]\n", myAtoi(str), atoi(str)); 
  }
   
}

void atoiTest() 
{
  printCmp("12345678");
  printCmp("0");
  printCmp("2147483648");
  printCmp("99999999999999999");
  printCmp("-1234512");
  printCmp("-2147483648");
  printCmp("+1");
  printCmp("    00321");
  printCmp("asd132    00321");
  printCmp("13aasd2    00321");
  printCmp("    +00321");
  printCmp("    -2147483649");
}

int main(int argc, char *argv[])
{
  atoiTest();
  return 0;
}
