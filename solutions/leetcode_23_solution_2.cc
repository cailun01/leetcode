#include "headers.h"
// 小顶堆
class Solution {
public:
    struct cmp{  
       bool operator()(ListNode *a,ListNode *b){
          return a->val > b->val;
       }
    };
    
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for (auto head : lists) {
            if (head) {
              // 如果遇到空链表则不入优先队列
              // 每个链表的head放入队列
                pq.push(head);
            }
        }
        ListNode* dummy = new ListNode(-1);
        ListNode* node = dummy;
        while (!pq.empty()) {
            ListNode* top = pq.top();
            pq.pop();
            node->next = top;
            node = node->next;
            if (top->next) {
                pq.push(top->next);
            }
        }
        return dummy->next;
    }
};