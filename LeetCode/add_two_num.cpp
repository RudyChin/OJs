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
 *   Sum each of the list first, and then mod 10 gradualy.
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
  private:
    long sumOfList(ListNode *l) {
      long sum = 0;
      long base = 1;
      ListNode *iter = l;
      while (iter) {
        sum += iter->val * base;
        base *= 10;
        iter = iter->next;
      }
      return sum;
    }
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
      long lsum = 0;
      lsum += sumOfList(l1);
      lsum += sumOfList(l2);
      ListNode *sum = new ListNode(lsum % 10);
      lsum /= 10;
      ListNode *iter = sum;
      while (lsum) {
        iter->next = new ListNode(lsum % 10);
        iter = iter->next; 
        lsum /= 10;
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
