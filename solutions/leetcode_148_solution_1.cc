/** 排序链表
归并排序链表
用快慢指针把链表分为两部分
左边链表排序
右边链表排序
合并左右两个链表，返回链表头
 */
class Solution {
public:
  ListNode* merge(ListNode* left, ListNode* right) {
    ListNode* dummy = new ListNode(-1);
    ListNode* cur = dummy;
    while (left && right) {
      if (left->val <= right->val) {
        cur->next = left;
        cur = cur->next;
        left = left->next;
      } else {
        cur->next = right;
        cur = cur->next;
        right = right->next;
      }
    }
    if (left) {
      cur->next = left;
    }
    if (right) {
      cur->next = right;
    }
    return dummy->next;
  }

  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    // 快慢指针，找链表中点
    // 如果有2个中点(链表长度为偶数)，则找到靠左的中点
    ListNode* fast = head;
    ListNode* slow = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      slow = slow->next;
    }
    // 拆分链表，tail是左侧链表的最后一个节点
    // 它的作用是tail->next = nullptr;
    ListNode* tail = slow;
    slow = slow->next;
    tail->next = nullptr;
    
    // 左边排序后返回左链表的开头
    ListNode* left = sortList(head);
    // 右边排序后返回右链表的开头
    ListNode* right = sortList(slow);
    // 合并
    return merge(left, right);
  }
};
