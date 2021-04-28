#include "headers.h"
// 插入排序
// 对序列A的n个元素A[1] ~ A[n]，令i从2到n枚举，进行n-1趟操作。
// 假设某一趟时，序列A的前i-1个元素A[1]~A[i-1]已经有序，而范围[i, n]还未有序，
// 那么该趟从范围[1, i-1]中寻找某个位置j，将A[i]插入到位置j，范围A[1, i]有序。
class Solution {
 public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next)
			return head;
		ListNode *dummyhead = new ListNode(-1);//伪头指针
		dummyhead->next = head;
		ListNode *prev = head;
		ListNode *node = head->next; // node节点将被插入到前面的某个位置, 在node之前，链表是有序的
		while (node) {
			if (node->val < prev->val) { // 如果后一节点的值小于前一节点
				ListNode* temp = dummyhead;//！！temp要等于dummyhead，这样才可以比较第一个元素
				while (temp->next->val < node->val) {//！！！这里是temp->next：因为要修改前面的temp的指向
					temp = temp->next;//指针后移
				}
				prev->next = node->next;
				node->next = temp->next;
				temp->next = node;
				node = prev->next;//此时不用改变prev指向！因为prev没有变，只是待排序元素变了位置。
			} else { // 如果后一节点的值大于等于前一节点
				prev = prev->next;
				node = node->next;
			}
		}
		return dummyhead->next;//!!!不能返回head！！因为后面会改变head所指向内存的位置！
	}
};
