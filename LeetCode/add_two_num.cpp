/*
 * You are given two linked lists representing two non-negative numbers.
 * The digits are stored in reverse order and each of their nodes contain a single digit.
 * Add the two numbers and return it as a linked list.
 *
 * Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 * Output: 7 -> 0 -> 8
 *
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/* 
 * Authur: Rudy Chin
 * Email: bb1168kk@gmail.com
 * 
 * Solutions:
 *   add each digit separately, the benefit is that it save space and can
 *   handle large number.
 *
 */

#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      int carry = 0;
      int digit = l1->val + l2->val + carry;
      carry = digit / 10;
      digit = digit % 10;
      ListNode *iter1 = l1->next;
      ListNode *iter2 = l2->next;
      ListNode *sum = new ListNode(digit);
      ListNode *iterSum = sum;
      while (iter1 || iter2) {
        int i1 = iter1? iter1->val : 0;
        int i2 = iter2? iter2->val : 0;
        digit = i1 + i2 + carry;
        carry = digit / 10;
        digit = digit % 10;
        iterSum->next = new ListNode(digit);
        iterSum = iterSum->next;
        iter1 = iter1? iter1->next : NULL;
        iter2 = iter2? iter2->next : NULL;
      }
      if (carry) {
        iterSum->next = new ListNode(carry);
      }
      return sum;
    }
};


void printList(ListNode *l) {
  ListNode *iter = l;
  while (iter->next) {
    cout << iter->val << " -> ";
    iter = iter->next;
  }
  cout << iter->val << endl;
}

void testAdd() {
  Solution sol;
  ListNode *l1 = new ListNode(1);
  ListNode *iter = l1;
  for (int i = 0; i < 9; i++) {
    iter->next = new ListNode(9);
    iter = iter->next;
  }

  ListNode *l2 = new ListNode(9);
  iter = l2;
  for (int i = 0; i < 0; i++) {
    iter->next = new ListNode(3);
    iter = iter->next;
  }
  printList(sol.addTwoNumbers(l1, l2));
}

int main() {
  testAdd();
}
