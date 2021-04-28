#include "headers.h"

/*
给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
k 是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。


进阶：

你可以设计一个只使用常数额外空间的算法来解决此问题吗？
你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
*/

class Solution {
public:

    /* 反转区间 [a, b) 的元素，注意是左闭右开 */
    ListNode* reverse(ListNode* a, ListNode* b) {
      ListNode* pre = nullptr;
      ListNode* cur = a;
      ListNode* nxt = a;

      while (cur != b) {
        // 逐个结点反转
        nxt = cur->next;
        cur->next = pre;
        // 更新指针位置
        pre = cur;
        cur = nxt;
      }
      // 返回反转后的头结点
      return pre;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
      if (!head) {
        return nullptr;
      }

      ListNode* a = head;
      ListNode* b = head;
      for (int i = 0; i < k; ++i) {
        // 不足 k 个，不需要反转，base case
        if (!b) {
          return head;
        }
        b = b->next;
      }
      ListNode* new_head = reverse(a, b);
      // 反转了k个元素后，b指向第k+1个元素
      a->next = reverseKGroup(b, k);
      return new_head;
    }
};

// 用迭代方式解决
// https://labuladong.github.io/algo/%E9%AB%98%E9%A2%91%E9%9D%A2%E8%AF%95%E7%B3%BB%E5%88%97/k%E4%B8%AA%E4%B8%80%E7%BB%84%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.html