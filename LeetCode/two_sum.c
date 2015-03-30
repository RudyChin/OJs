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
 *  First store the original array.
 *  Use a hashtable to store value to index hash.
 *    - If the value if negative use the second part of the hash
 *      table.
 *    - else use the first part of the hash table.
 *  Use Merge Sort O(N log N) to sort the array.
 *  Go through the array, if target is lesser than current i and j
 *  then increase i and make j = i + 1.
 *  (There is no help to loop through the rest j)
 *  Use the answer value that just found to hash for indexes,
 *  search linked list if collision occurs.
 *
 */

#include <stdio.h>
#include <stdlib.h>

#define HASH_SIZE 2053
#define MAGICNUM 1381

typedef struct hash_node {
  int index;
  struct hash_node *next;
} hash_node;

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

int*
twoSum(int numbers[], int n, int target) {
  /** initial hashtable **/
  hash_node *hashtable = (hash_node*)malloc(sizeof(hash_node)*HASH_SIZE*2);
  for (int i = 0; i < 2*HASH_SIZE; i++) {
    hashtable[i].index = 0;
    hashtable[i].next = NULL;
  }
  /** store original array **/
  int *original = (int*)malloc(sizeof(int)*n);
  for (int i = 0; i < n; i++) {
    original[i] = numbers[i];
  }

  /** hash value to indexes before sort **/
  for (int i = 0; i < n; i++) {
    int temp = numbers[i] * MAGICNUM % HASH_SIZE;
    if (temp < 0) {
      temp = 2*HASH_SIZE + temp;
    }
    int index = temp;
    //no collision
    if (!hashtable[index].index) {
      hashtable[index].index = i + 1;
    }
    // collision
    else {
      hash_node *iter = &hashtable[index];
      while (iter->next) {
        iter = iter->next;
      }
      iter->next = (hash_node*)malloc(sizeof(hash_node));
      iter->next->index = i + 1;
      iter->next->next = NULL;
    }
  }

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
      int hashidx1 = numbers[i] * MAGICNUM % HASH_SIZE; 
      int idx1 = 0;
      int idx2 = 0;
      if (hashidx1 < 0) {
        hashidx1 = 2*HASH_SIZE + hashidx1;
      }
      int hashidx2 = numbers[j] * MAGICNUM % HASH_SIZE;
      if (hashidx2 < 0) {
        hashidx2 = 2*HASH_SIZE + hashidx2;
      }
      //collision
      if (hashidx1 == hashidx2) {
        hash_node *iter = &hashtable[hashidx1];
        while (iter) {
          if (!idx1 && (original[(iter->index)-1] == numbers[i]))
            idx1 = iter->index;
          else if (!idx2 && (original[(iter->index)-1] == numbers[j]))
            idx2 = iter->index;
          else if (idx1 && idx2)
            break;
          iter = iter->next;
        }
      } else {
        hash_node *iter1 = &hashtable[hashidx1];
        hash_node *iter2 = &hashtable[hashidx2];
        while (iter1) {
          if (original[(iter1->index)-1] == numbers[i]) {
            idx1 = iter1->index;
            break;
          } else {
            iter1 = iter1->next;
          }
        }
        while (iter2) {
          if (original[(iter2->index)-1] == numbers[j]) {
            idx2 = iter2->index;
            break;
          } else {
            iter2 = iter2->next;
          }
        }
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

void
testMerge() {
  int arr[] = {-1,-2,-3,-4,-5};
  mergeSort(arr, 5);
  for (int i = 0; i < 5; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

int
main() {
  testMerge();
  int numbers[] = {0, 4, 3, 0};
  int *ans = twoSum(numbers, 4, 0);
  printf("%d %d\n", ans[0], ans[1]);
  return 0;
}
