#include "headers.h"
// 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

// 示例：

// 给定一个链表: 1->2->3->4->5, 和 n = 2.

// 当删除了倒数第二个节点后，链表变为 1->2->3->5.
// 说明：

// 给定的 n 保证是有效的。

// 进阶：
// 你能尝试使用一趟扫描实现吗？

// 题解：
// 假设链表长度为L，倒数第n个节点相当于正数第L-n+1个节点
// 删除倒数第n个节点的过程是把倒数第n+1个节点的next直接设置为倒数第n-1个节点
// 也就是把正数第L-n个节点next直接设置为正数L-n+2个节点

// 首先我们将添加一个哑结点作为辅助，该结点位于列表头部。
// 哑结点用来简化某些极端情况，例如列表中只含有一个结点，或需要删除列表的头部。
// 在第一次遍历中，我们找出列表的长度L。然后设置一个指向哑结点的指针，
// 并移动它遍历列表，直至它到达第 (L - n)个结点那里。
// 我们把第(L - n)个结点的 next 指针重新链接至第(L - n + 2)个结点，完成这个算法。

// 扫描两趟
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
      ListNode* dummy = new ListNode(-1);
      dummy->next = head;
      ListNode* first = head;
      int length = 1;
      while (head->next) {
        length += 1;
        head = head->next;
      }
      length -= n; // L - n
      first = dummy;
      while (length--) {
        first = first->next;
      }
      first->next = first->next->next;
      return dummy->next;
    }
};

// 确定链表的长度
// int length = 1;
// while (head->next) {
//   length += 1;
//   head = head->next;
// }

// while (length--)
// 先判断，后作减法