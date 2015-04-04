#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int traverse(int *lights, int index) {
  int sum = 0;
  while (index) {
    sum += lights[index];
    index = (index-1)/2;
  }
  return sum;
}

int main() {
  int n;
  scanf("%d", &n);
  int roads = pow(2, n+1)-1;
  int *lights = (int *)malloc(sizeof(int)*roads);
  int *ways = (int *)malloc(sizeof(int)*(roads/2));
  for (int i = 1; i < roads; i++) {
    scanf("%d", &(lights[i]));
  }
  for (int i = 0; i < (roads+1)/2; i++) {
    ways[i] = traverse(lights, i+(roads/2)); 
  }
  int max = 0;
  for (int i = 0; i < (roads+1)/2; i++) {
    if (max < ways[i]) {
      max = ways[i];
    }
  }
}
