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

#include <stdio.h>
#include <stdlib.h>

void 
concat(int *left, int l, int m, int r, int *right, int *sorted) {
  int idx = 0;
  int x = l, y = m;
  while (x < m && y < r) {
    if (left[x] < right[y])
      sorted[idx++] = left[x++];
    else
      sorted[idx++] = right[y++];
  }
  for (x; x < m; x++)
    sorted[idx++] = left[x];
  for (y; y < r; y++)
    sorted[idx++] = right[y];
}

void 
mergeSplit(int *arr, int l, int r, int *sorted) {
  if (r - l < 2) {
    sorted[0] = arr[l];
    return;
  }
  int m = (l + r) / 2;
  int *left = (int *)malloc(sizeof(int)*(l+r+1)/2);
  int *right = (int *)malloc(sizeof(int)*(l+r+1)/2);
  mergeSplit(arr, l, m, left);
  mergeSplit(arr, m, r, right);
  concat(left, l, m, r, right, sorted);
}

void 
mergeSort(int *arr, int n) {
  int l = 0;
  int r = n;
  int *sorted = (int *)malloc(sizeof(int)*n);
  mergeSplit(arr, l, r, sorted);
  for (int i = 0; i < r; i++)
    arr[i] = sorted[i];
}

void
testMerge() {
  int arr[10] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
  mergeSort(arr, 10);
  for (int i = 0; i < 10; i++)
    printf("%d ", arr[i]);
}

int *
twoSum(int numbers[], int n, int target) {
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
      ans[0] = i;
      ans[1] = j;
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
  return 0;
}
