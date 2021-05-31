/* 234 回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/
 
/* 
1、先通过 双指针技巧汇总 中的快慢指针来找到链表的中点
2、如果fast指针没有指向null，说明链表长度为奇数，slow还要再前进一步
3、从slow开始反转后面的链表，现在就可以开始比较回文串了
*/
class Solution {
public:
  // 迭代法反转链表
  ListNode* reverse(ListNode* head) {
    ListNode* cur = head;
    ListNode* nxt = head;
    ListNode* prev = nullptr;
    while (cur != nullptr) {
      nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }
    return prev;
  }
  bool isPalindrome(ListNode* head) {
    // 快慢指针，slow指向链表中间的位置
    // 如果链表个数时奇数，slow指向中间节点，如果是偶数，指向中间偏右的节点。
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode* left = head;
    // 反转链表，返回反转后的头节点right
    ListNode* right = reverse(slow);
    // 判断回文
    while (fast != nullptr && fast->next != nullptr) {
      if (left->val != right->val) {
        return false;
      }
      left = left->next;
      right = right->next;
    }
    return true;
  }
};
