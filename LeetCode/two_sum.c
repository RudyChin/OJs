/*
 * Given an array of integers, find two numbers such that they add up to a specific target number.
 *
 * The function twoSum should return indices of the two numbers such that they add up to the target,
 * where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
 *
 * You may assume that each input would have exactly one solution.
 *
 * Input: numbers={2, 7, 11, 15}, target=9
 * Output: index1=1, index2=2
 */


/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solution:
 *  First store the original array into value index pair array.
 *  Use Merge Sort O(N log N) to sort the array.
 *  For i = 0 ~ N, use binary search to find j in order to let
 *  arr[i] + arr[j] == target.
 *  (There is no help to loop through the rest j)
 *  if the sum matches target, find index value in that pair
 *
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct vipair {
  int value;
  int index;
} vipair;

void 
concat(vipair *arr, int l, int m, int r, vipair *sorted) {
  int idx = l;
  int x = l, y = m;
  while (x < m && y < r) {
    if (arr[x].value < arr[y].value)
      sorted[idx++] = arr[x++];
    else
      sorted[idx++] = arr[y++];
  }
  for (x; x < m; x++)
    sorted[idx++] = arr[x];
  for (y; y < r; y++)
    sorted[idx++] = arr[y];
}

void
copy(vipair *arr, vipair *sorted, int l, int r) {
  for (l; l < r; l++)
    arr[l] = sorted[l];
}

void 
mergeSplit(vipair *arr, int l, int r, vipair *sorted) {
  if (r - l < 2) {
    return;
  }
  int m = (l + r) / 2;
  mergeSplit(arr, l, m, sorted);
  mergeSplit(arr, m, r, sorted);
  concat(arr, l, m, r, sorted);
  copy(arr, sorted, l, r);
}

void 
mergeSort(vipair *arr, int n) {
  vipair *sorted = (vipair*)malloc(sizeof(vipair)*n);
  for (int i = 0; i < n; i++)
    sorted[i] = arr[i];
  mergeSplit(arr, 0, n, sorted);
  free(sorted);
}

int*
twoSum(int numbers[], int n, int target) {
  /** store it into vipair array **/
  vipair *arr = (vipair*)malloc(sizeof(vipair)*n);
  for (int i = 0; i < n; i++) {
    arr[i].value = numbers[i];
    arr[i].index = i+1;
  }

  /** sort first with nlogn algo **/
  mergeSort(arr, n);

  /** conditional compare **/
  int i = 0;
  for (i; i < n; i++) {
    int imin = i, imax = n-1;
    while (imin <= imax) {
      int imid = (imin+imax)/2;
      if (arr[i].value + arr[imid].value > target) {
        imax = imid - 1;
      } else if (arr[i].value + arr[imid].value < target) {
        imin = imid + 1;
      } else {
        int *ans = (int *)malloc(sizeof(int)*2);
        int idx1 = arr[i].index;
        int idx2 = arr[imid].index;
        if (idx1 > idx2) {
          ans[0] = idx2;
          ans[1] = idx1;
        } else {
          ans[0] = idx1;
          ans[1] = idx2;
        }
        return ans;
      }
    }
  }
}

void
testMerge() {
  vipair arr[5];
  for (int i = 0; i < 5; i++) {
    arr[i].value = 5-i;
    arr[i].index = i+1;
  }
  mergeSort(arr, 5);
  for (int i = 0; i < 5; i++)
    printf("value[%d] index[%d]\n", arr[i].value, arr[i].index);
}

int
main() {
  testMerge();
  int numbers[] = {5, 75, 25};
  int *ans = twoSum(numbers, 3, 100);
  printf("%d %d\n", ans[0], ans[1]);
  return 0;
}
