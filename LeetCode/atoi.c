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
    else
    {
        return 0;  
    }
  }
  return sum;
}

int myAtoi(char *str) 
{
  int length = strlen(str);
  int negative = 0;
  long sum;
  if (str[0] == '-') 
  {
    negative = 1;
    sum = calculate(str, 1, length);
  }
  else if (str[0] == '+')
  {
    sum = calculate(str, 1, length); 
  }
  else
  {
    sum = calculate(str, 0, length);
  }
  if (sum > 1<<(31-1))
    return 0;
  if (negative)
    sum = -sum;

  return (int)sum;
    
}

void atoiTest() 
{
   printf("str:12345678 int:[%d]\n", myAtoi("12345678")); 
   printf("str:0 int:[%d]\n", myAtoi("0")); 
   printf("str:2147483688 int:[%d]\n", myAtoi("2147483688")); 
   printf("str:-1234512 int:[%d]\n", myAtoi("-1234512")); 
   printf("str:-2147483648 int:[%d]\n", myAtoi("-2147483648")); 
   printf("str:+1 int:[%d]\n", myAtoi("+1")); 
}

int main(int argc, char *argv[])
{
  atoiTest();
  return 0;
}
