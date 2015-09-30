/* 
 * Regular expression matching
 * Operator: '*' and '.'
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *  Recusively match. Check if current character followed by '*', if it does,
 *  we give repeat this character 0 ~ INF times starting from 0.
 *  under each repeation, if it match then recursively match s+1, p+2
 *  and if s+1, p+2 does not match we repeat this character one more time and do it
 *  again. (Which is in fact a rollback)
 *
 *  If string match to the end, get ride of trailing character that followed by '*'
 *  Check if both pattern and string match to the end, then success
 *
 */

#include <stdio.h>
#include <string.h>

typedef int bool;
#define true 1
#define false 0

// To execute C, please define "int main()"
int matchStar(char* s, char* p, int sIdx, int pIdx, int star);
bool isCharMatch(char s, char p);
bool isMatch(char* s, char* p);


int main() {
  char *s = "a";
  char *p = "a*aa*a*";
  if (isMatch(s, p))
    printf("Match");
  else
    printf("Not match");
  return 0;
}

bool isMatch(char* s, char* p) {
  int sIdx = 0, pIdx = 0;
  int sLen = strlen(s);
  int pLen = strlen(p);
  //printf("sLen=%d pLen=%d\n", sLen, pLen);
  if (sIdx < sLen && pIdx < pLen) {
    if (p[pIdx+1] == '*') {
      int starIdx = 0;
      int star = 0;
      int matched = 0;
      do {
        starIdx = matchStar(s, p, sIdx, pIdx, star++);
        //star matching success of `star` times of p[pIdx]
        if (starIdx != -1) {
          matched = isMatch(s+starIdx, p+2);
        }
        //star matching fail
        else {
          return false;
        }
      } while (matched == false && starIdx != sLen);
      if (matched)
        return true;
    }
    else {
      if (isCharMatch(s[sIdx], p[pIdx])) {
        return isMatch(s+1, p+1);
      }
    }
  }

  else {
    //Get ride of trailing *
    while (pIdx < pLen && p[pIdx+1] == '*') pIdx += 2;
  
    if (sIdx == sLen && pIdx == pLen) {
      return true;
    }
  }
  return false;
}


bool isCharMatch(char s, char p) {
  if (s == p || p == '.') {
    return true;
  }
  return false;
}

// match * expression
// return index of s if valid
// return -1 if not valid
int matchStar(char* s, char* p, int sIdx, int pIdx, int star) {
  for (int i = 0; i < star; i++) {
    if (!isCharMatch(s[sIdx], p[pIdx])) {
      return -1;
    }
    else {
      sIdx++;
      if (sIdx == strlen(s)) {
        break;
      }
    }
  }
  return sIdx;
}
    
