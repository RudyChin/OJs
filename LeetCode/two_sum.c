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

int *
twoSum(int numbers[], int n, int target) {
  /** sort first with nlogn algo **/
  numbers = mergesort(numbers, n);

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

