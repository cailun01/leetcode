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