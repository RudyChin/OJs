#include <stdio.h>
#include <stdlib.h>

char *s; //input

int jump(int index, int length, int n) {
  int jumps = 0;
  while (index < n) {
    jumps++;
    index += length;
    if (s[index+length] != '*')
      return 0;
    if (jumps >= 4)
      return 1;
  }
  return 0;
}

int main() {
  int segs;
  s = (char *)malloc(sizeof(char)*segs+1);

  scanf("%d", &segs);
  scanf("%s", s);

  for (int l = 1; l <= (segs / 4); l++) {
    for (int i = 0; i < segs; i++) {
      if (jump(i, l, segs)) {
        printf("yes\n");
        return 0;
      }
    }
  }
  printf("no\n");
  return 0;
}
