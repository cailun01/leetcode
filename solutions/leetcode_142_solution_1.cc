/* 142 环形链表2
给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。

为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 
如果 pos 是 -1，则在该链表中没有环。注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。

说明：不允许修改给定的链表。

进阶：
你是否可以使用 O(1) 空间解决此题？
*/

class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head) {
      return nullptr;
    }
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        // fast和slow都指向环的头节点。
        break;
      }
    }
    // 没有环
    if (fast == nullptr || fast->next == nullptr) {
      return nullptr;
    }
    // 从head出发，与slow同步前进。相遇后指向环的节点
    ListNode* ptr = head;
    while (ptr != slow) {
      ptr = ptr->next;
      slow = slow->next;
    }
    return slow;
  }
};
