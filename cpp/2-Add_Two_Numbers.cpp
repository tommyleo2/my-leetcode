/**
 *  You are given two non-empty linked lists representing two non-negative integers.
 *  The digits are stored in reverse order and each of their nodes contain a single digit.
 *  Add the two numbers and return it as a linked list.

 *  You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 *  Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *  Output: 7 -> 0 -> 8
 */

#include <iostream>
#include <string>

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int carry = 0;
    ListNode result = ListNode(0);
    ListNode *last = &result;
    while (l1 != NULL || l2 != NULL) {
      int sum = 0;
      if (l1 == NULL) {
        sum = l2->val + carry;
        l2 = l2->next;
      } else if (l2 == NULL) {
        sum = l1->val + carry;
        l1 = l1->next;
      } else {
        sum = l1->val + l2->val + carry;
        l1 = l1->next;
        l2 = l2->next;
      }

      carry = sum / 10;
      sum %= 10;
      ListNode *tmp = new ListNode(sum);
      last->next = tmp;
      last = tmp;
    }

    if (carry) {
      last->next = new ListNode(1);
    }

    return result.next;
  }
};

static void clear(ListNode *list) {
  while (list != NULL) {
    ListNode *tmp = list->next;
    delete list;
    list = tmp;
  }
}

using namespace std;

int main(void) {
  string s1, s2;
  ListNode l1(0), l2(0);
  ListNode *last1 = &l1, *last2 = &l2;
  cin >> s1 >> s2;
  for (int i = s1.size() - 1; i >=0; i--) {
    ListNode *tmp = new ListNode(s1[i] - '0');
    last1->next = tmp;
    last1 = tmp;
  }
  for (int i = s2.size() - 1; i >=0; i--) {
    ListNode *tmp = new ListNode(s2[i] - '0');
    last2->next = tmp;
    last2 = tmp;
  }
  Solution s;
  ListNode *result = s.addTwoNumbers(l1.next, l2.next);

  ListNode *tmp =result;
  string result_s;
  while (tmp != NULL) {
    result_s.insert(0, 1, tmp->val + '0');
    tmp = tmp->next;
  }
  cout << result_s << endl;

  clear(result);
  clear(l1.next);
  clear(l2.next);
  return 0;
}
