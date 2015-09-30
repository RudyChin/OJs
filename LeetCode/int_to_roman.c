/* 
 * Convert integer to Roman numeral
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *  List ones, tens, hundreds and thousands. Use string concatenation
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ones[10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
char* tens[10] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
char* hundreds[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
char* thousands[4] = {"", "M", "MM", "MMM"};

char* intToRoman(int);

int main(int argc, char *argv[])
{
  printf("%s\n", intToRoman(689));
  return 0;
}

char* intToRoman(int num) {
  char* ans = (char*)malloc(sizeof(char)*20);
  strcat(ans, thousands[num/1000]);
  num %= 1000;
  strcat(ans, hundreds[num/100]);
  num %= 100;
  strcat(ans, tens[num/10]);
  num %= 10;
  strcat(ans, ones[num]);
  return ans;
}
