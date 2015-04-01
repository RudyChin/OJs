/* 
 * There are two sorted arrays A and B of size m and n respectively. 
 * Find the median of the two sorted arrays. 
 * The overall run time complexity should be O(log (m+n)).
 *
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *   Use merge sort to merge the two sorted array.
 *   If the total elements of the new array is ODD,
 *   then the answer is the middle one.
 *   Else if it is EVEN,
 *   then the answer is the average of the two middle number.
 *
 */

#include <stdio.h>

double findMedianSortedArrays(int A[], int m, int B[], int n) {
  int *overall = (int *)malloc(sizeof(int)*(m+n));
  int i = 0;
  int j = 0;
  int idx = 0;
  while ((i < m) && (j < n)) {
    if (A[i] < B[j]) {
      overall[idx++] = A[i++];
    } else {
      overall[idx++] = B[j++];
    }
  }
  for (i; i < m; i++) {
    overall[idx++] = A[i];
  }
  for (j; j < n; j++) {
    overall[idx++] = B[j];
  }
  if (idx % 2) {
    //odd
    return overall[(idx-1)/2];
  } else {
    //even
    return (overall[(idx-1)/2] + overall[((idx-1)/2)+1]) / 2.0;
  }
}

void test() {
  int A[] = {2,3};
  int B[] = {};
  printf("%lf", findMedianSortedArrays(A, 2, B, 0));
}

int main() {
  test();
  return 0;
}
