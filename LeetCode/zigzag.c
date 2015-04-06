/*
 * The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
 * (you may want to display this pattern in a fixed font for better legibility)
 * P   A   H   N
 * A P L S I I G
 * Y   I   R
 * And then read line by line: "PAHNAPLSIIGYIR"
 * Write the code that will take a string and make this conversion given a number of rows:
 *
 * convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
 *
 */


/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *  Use a matrix to store the string. For example,
 *  "PAYPALISHIRING"
 *  3x7 matrix
 *  P - A - H - N
 *  A P L S I I G
 *  Y - I - R -
 *  
 *  the algorithm fill the matrix like the following 
 *
 *  |            ^
 *  |  and then  | ...
 *  v            |
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getNext(int nRows, int nCols, int *r, int *c, int *way) {
  if (*way) {
    (*r)++;
    if (*r == nRows) {
      (*c)++;
      *r = nRows-1;
      *way = 0;
    }
  } else {
    (*r)--;
    if (*r == -1) {
      (*c)++;
      *r = 0;
      *way = 1;
    }
  }
  return (*r)*nCols+(*c);
}

char *convert(char *s, int nRows) {
  int n = strlen(s);
  int period = 2*nRows-2;
  char *ans = (char *)malloc(sizeof(char)*(n+1));

  if (!period || n <= nRows) {
    int i;
    for (i = 0; i < n; i++) 
      ans[i] = s[i];
    ans[i] = '\0';
    return ans;
  }
  
  int nCols = (n/period)*2 + (n%period == 0 ? 0 : (n%period > nRows? 2 : 1));
  char *matrix = (char *)malloc(sizeof(char)*nRows*nCols);
  memset(matrix, '-', nRows*nCols);

  int way = 1; //row++
  int r = 0, c = 0;
  int i = 0, idx = 0;
  while (i < n) {
    if (c % 2 == 1 && (r == 0 || r == nRows-1)) {
      idx = getNext(nRows, nCols, &r, &c, &way); 
      continue;
    }
    matrix[idx] = s[i++]; 
    idx = getNext(nRows, nCols, &r, &c, &way); 
  }

  i = 0;
  for (idx = 0; idx < nRows*nCols; ++idx) {
    if (matrix[idx] != '-')
      ans[i++] = matrix[idx];
  }
  ans[i] = '\0';

  return ans;
}

void test() {
  char *testString = "AB";
  char *ans = convert(testString, 1);
  printf("%s\n", ans);
}

int main(int argc, char *argv[]) {
  test();
  return 0;
}
