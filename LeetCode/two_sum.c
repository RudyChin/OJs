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


/* Solve by Rudy Chin.
 * Solution:
 *  First use hash table to hash from value to original indexes.
 *  Use Merge Sort O(N log N) to sort the array.
 *  Go through the array, if target is lesser than current i and j
 *  then increase i and make j = i + 1.
 *  (There is no help to loop through the rest j)
 *
 */

#include <stdio.h>
#include <stdlib.h>

void 
concat(int *arr, int l, int m, int r, int *sorted) {
  int idx = l;
  int x = l, y = m;
  while (x < m && y < r) {
    if (arr[x] < arr[y])
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
copy(int *arr, int *sorted, int l, int r) {
  for (l; l < r; l++)
    arr[l] = sorted[l];
}

void 
mergeSplit(int *arr, int l, int r, int *sorted) {
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
mergeSort(int *arr, int n) {
  int *sorted = (int *)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++)
    sorted[i] = arr[i];
  mergeSplit(arr, 0, n, sorted);
  free(sorted);
}

void
testMerge() {
  int arr[3] = {3, 2, 4};
  mergeSort(arr, 3);
  for (int i = 0; i < 3; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int *
twoSum(int numbers[], int n, int target) {
  /** store the original array **/
  int *original = (int *)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++)
    original[i] = numbers[i];

  /** sort first with nlogn algo **/
  mergeSort(numbers, n);

  /** conditional compare **/
  int i = 0, j = 1;
  while (i < n) {
    if (numbers[i] + numbers[j] > target) {
      i++;
      j = i + 1;
      continue;
    } else if (numbers[i] + numbers[j] == target) {
      int *ans = (int *)malloc(sizeof(int)*2);
      int idx1 = 0;
      int idx2 = 0;
      for (int k = 0; k < n; k++) {
        if (!idx1 && original[k] == numbers[i])
          idx1 = k+1;
        else if (!idx2 && original[k] == numbers[j])
          idx2 = k+1;
        else if (idx1 && idx2)
          break;
      }
      if (idx1 > idx2) {
        ans[0] = idx2;
        ans[1] = idx1;
      } else {
        ans[0] = idx1;
        ans[1] = idx2;
      }
      return ans;
    }
    j++;
    if (j == n) {
      i++;
      j = i+1;
    }
  }
}

int
main() {
  testMerge();
  int numbers[] = {0, 2, 0};
  int *ans = twoSum(numbers, 3, 0);
  printf("%d %d\n", ans[0], ans[1]);
  return 0;
}
