#include "headers.h"

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    int t = 0;
    ListNode*res_head = new ListNode(0);
    ListNode*res_ptr = new ListNode(0);
    res_head->next = res_ptr;
    ListNode* l1_ptr = l1;
    ListNode* l2_ptr = l2;
    ListNode* tmp_node = new ListNode(0);
    while (true) {
      int tmp = l1_ptr->val + l2_ptr->val + t;
      t = tmp / 10;
      res_ptr->next = new ListNode(tmp % 10);
      res_ptr = res_ptr->next;
      l1_ptr = l1_ptr->next;
      l2_ptr = l2_ptr->next;
      if (!l1_ptr && !l2_ptr && t == 0) {
        break;
      }
      if (!l1_ptr) { 
        l1_ptr = tmp_node; 
      }
      if (!l2_ptr) { 
        l2_ptr = tmp_node; 
      }
    }
    return res_head->next->next;
  }
};