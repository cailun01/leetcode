#include "headers.h"
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
		ListNode *last_sorted = head; // last_sorted为链表已经排好序的最后一个节点并初始化
		ListNode *curr = head->next; // node节点为待插入的元素, 在node之前，链表是有序的
		while (curr) {
			if (last_sorted->val <= curr->val) {// 说明curr应该位于lastSorted之后
				last_sorted = last_sorted->next;  // 将lastSorted后移一位,curr变成新的lastSorted
			} else {                            // 否则,从链表头结点开始向后遍历链表中的节点
				ListNode* prev = dummy;           // 从链表头开始遍历 prev是插入节点curr位置的前一个节点
				while (prev->next->val <= curr->val) {  // 循环退出的条件是找到curr应该插入的位置
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
