#include "headers.h"
/* 插入排序链表
题目：
对链表进行插入排序。

插入排序的动画演示如上。从第一个元素开始，该链表可以被认为已经部分排序（用黑色表示）。
每次迭代时，从输入数据中移除一个元素（用红色表示），并原地将其插入到已排好序的链表中。


插入排序算法：

插入排序是迭代的，每次只移动一个元素，直到所有元素可以形成一个有序的输出列表。
每次迭代中，插入排序只从输入数据中移除一个待排序的元素，找到它在序列中适当的位置，并将其插入。
重复直到所有输入数据插入完为止。
 

示例 1：

输入: 4->2->1->3
输出: 1->2->3->4
示例 2：

输入: -1->5->3->4->0
输出: -1->0->3->4->5
*/

// 数组的插入排序，leetcode_912_solution_5.cc
// 本题解释：https://leetcode-cn.com/problems/insertion-sort-list/solution/dui-lian-biao-jin-xing-cha-ru-pai-xu-by-leetcode-s/

class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    ListNode *dummy = new ListNode(-1);//伪头指针
    dummy->next = head;
    // last_sorted为链表已经排好序的最后一个节点并初始化
    ListNode *last_sorted = head;
    // node节点为待插入的元素, 在node之前，链表是有序的
    ListNode *curr = head->next; 
    while (curr) {
      if (last_sorted->val <= curr->val) {
        // 说明curr应该位于lastSorted之后
        // 将lastSorted后移一位,curr变成新的lastSorted
        last_sorted = last_sorted->next;  
      } else {
        // 否则,从链表头结点开始向后遍历链表中的节点
        // 从链表头开始遍历 prev是插入节点curr位置的前一个节点        
        ListNode* prev = dummy;           
        while (prev->next->val <= curr->val) {
          // 循环退出的条件是找到curr应该插入的位置
          prev = prev->next;
        }
        // 以下三行是为了完成对curr的插入
        last_sorted->next = curr->next;
        curr->next = prev->next;
        prev->next = curr;
      }
      curr = last_sorted->next; // 此时 curr 为下一个待插入的元素
    }
    return dummy->next;
  }
};
