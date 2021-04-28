#include "headers.h"

// 进阶
// 一次遍历算法
// 上述算法可以优化为只使用一次遍历。我们可以使用两个指针而不是一个指针。
// 第一个指针从列表的开头向前移动 n+1 步，而第二个指针将处于列表的开头位置不动。
// 现在，这两个指针被 n 个结点分开。我们通过同时移动两个指针向前来保持这个恒定的间隔，
// 直到第一个指针到达最后一个结点。此时第二个指针将指向从最后一个结点数起的第 n 个结点。
// 我们重新链接第二个指针所引用的结点的 next 指针指向该结点的下下个结点。


class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(-1);
      dummy->next = head;
      ListNode* first = dummy;
      ListNode* second = dummy;
      for (int i = 0; i < n + 1; ++i) {
        first = first->next;
      }
      while (first) {
        first = first->next;
        second = second->next;
      }
      second->next = second->next->next;
      return head;
    }
};