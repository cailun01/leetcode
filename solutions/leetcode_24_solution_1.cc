#include "headers.h"
/* 24. 两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例:
给定 1->2->3->4, 你应该返回 2->1->4->3.
*/

// 递归
class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (!head) {
      return nullptr;
    } 
    if (!head->next) {
      return head;
    }
    // 拿到第一个节点head和第二个节点second
    ListNode* second = head->next;
    // 把head的next设置为交换后的链表
    head->next = swapPairs(second->next);
    // second的next设置为head
    second->next = head;
    return second;
  }
};
