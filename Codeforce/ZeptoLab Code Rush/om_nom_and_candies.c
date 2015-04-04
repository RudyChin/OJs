#include <stdio.h>
#include <stdlib.h>

int main() {
  int C, Hr, Hb, Wr, Wb;
  int Nr = 0, Nb = 0;
  scanf("%d %d %d %d %d", &C, &Hr, &Hb, &Wr, &Wb);

  int max = 0;
  if (Wr > Wb)
    for (int i = 0; i <= C; i++) {
      int tmp = C - i*Wr;
      for (int j = 0; j <= tmp; j++)
        if (i*Wr + j*Wb == C)
          if (max < i*Hr+j*Hb) 
            max = i*Hr+j*Hb;
    }
  else
    for (int i = 0; i <= C; i++) {
      int tmp = C - i*Wb;
      for (int j = 0; j <= tmp; j++)
        if (i*Wb + j*Wr == C)
          if (max < i*Hb+j*Hr) 
            max = i*Hb+j*Hr;
    }

  printf("%d\n", max);

}
