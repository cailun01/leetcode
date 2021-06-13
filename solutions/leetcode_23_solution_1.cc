/* 	23. 合并K个升序链表  
给你一个链表数组，每个链表都已经按升序排列。
请你将所有链表合并到一个升序链表中，返回合并后的链表。

示例 1：
输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
示例 2：
输入：lists = []
输出：[]

示例 3：
输入：lists = [[]]
输出：[]
 

提示：
k == lists.length
0 <= k <= 10^4
0 <= lists[i].length <= 500
-10^4 <= lists[i][j] <= 10^4
lists[i] 按 升序 排列
lists[i].length 的总和不超过 10^4
*/
#include "headers.h"
// 暴力解法
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int num_lists = lists.size();
        if (num_lists == 0) {
            return nullptr;
        }
        if (num_lists == 1) {
            return lists.at(0);
        }
        ListNode* res = new ListNode(-1);
        ListNode* first = lists.at(0);
        int i = 0;
        for (i; i < num_lists - 1; ++i) {
            ListNode* new_list = new ListNode(-1);
            ListNode* head_new = new_list;
            ListNode* second = lists.at(i + 1);
            while (first && second) {
                if (first->val <= second->val) {
                    new_list->next = first;
                    first = first->next;
                } else {
                    new_list->next = second;
                    second = second->next;
                }
                new_list = new_list->next;
            }
            if (first) {
                new_list->next = first;
            }
            if (second) {
                new_list->next = second;
            }
            // 将合并后的list再设置为first，以便和新的链表合并
            first = head_new->next;
            res = head_new;
        }
        return res->next;
    }
};