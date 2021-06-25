#include "headers.h"
/* 2. 两数相加
给出两个非空的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，
并且它们的每个节点只能存储 一位 数字。
如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807
*/

/*
每位数字是逆序存储，因此链表头节点head指向个位数，head->next指向十位数。

1.
处理2个链表：while (val || l1 || l2)
在while循环内，需要对l1或l2是否为null分别作判断

l1 ? l1->val : 0
当前节点，如果不是null，则取它的值，否则取0

假设都是个位，l1->val==7, l2->val==9
则当前个位应该是6，计算十位时要加1
val % 10计算的是当前个位（取模）
val = val / 10为计算十位保存1
*/

class Solution {
public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode* pre_node = new ListNode(0);
    ListNode* last_node = pre_node;
    int sum = 0;
    int carry = 0; // 进位
    while (carry > 0 || l1 || l2) {
      sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
      last_node->next = new ListNode(sum % 10);
      last_node = last_node->next;
      carry = sum / 10;
      l1 = l1 ? l1->next : nullptr;
      l2 = l2 ? l2->next : nullptr;
    }
    ListNode *res = pre_node->next;
    delete pre_node;
    return res;
  }
};
