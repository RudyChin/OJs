/* 
 * Implement atoi to convert a string to an integer.
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
#include <string.h>


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
  {
    if (str[i] - '0' >= 0 && str[i] - '0' <= 9) 
    {
        sum += (str[i]-'0') * lpow(10, end-i-1); 
    } 
  }
  return sum;
}

int myAtoi(char *str) 
{
  int length = strlen(str);
  int negative = 0;
  long sum;
  int start = 0, end = length;
  while (str[start] == ' ')
    start++; 

  if (str[start] == '-') 
  {
    negative = 1;
    for (int i = start+1; i < length; i++)
      if (str[i] - '0' < 0 || str[i] - '0' > 9) {
        end = i; 
        break;
      }
    sum = calculate(str, start+1, end);
  }
  else if (str[start] == '+') 
  {
    for (int i = start+1; i < length; i++)
      if (str[i] - '0' < 0 || str[i] - '0' > 9) {
        end = i; 
        break;
      }
    sum = calculate(str, start+1, end); 
  }
  else
  {
    for (int i = start; i < length; i++)
      if (str[i] - '0' < 0 || str[i] - '0' > 9) {
        end = i; 
        break;
      }
    sum = calculate(str, start, end);
  }
  if (negative)
    sum = -sum;

  return (int)sum;
    
}

void printCmp(char *str)
{
  int pass = (myAtoi(str) == atoi(str));
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
