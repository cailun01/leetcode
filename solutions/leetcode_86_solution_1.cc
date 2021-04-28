#include "headers.h"

// 创建2个链表，1个保存小于x的节点，另1个保存大于等于x的节点，最后拼接2个链表。
class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    if (!head || !head->next) return head;

    ListNode* smaller = new ListNode(-1);
    ListNode* ps = smaller;
    ListNode* larger_equal = new ListNode(-1);
    ListNode* pl = larger_equal;

    while (head) {
      if (head->val < x) {
        ps->next = head;
        ps = ps->next;
      } else { // head->val >= x
        pl->next = head;
        pl = pl->next;
      }
      head = head->next;
    }
    ps->next = larger_equal->next;
    pl->next = nullptr;
    return smaller->next;
  }
};  