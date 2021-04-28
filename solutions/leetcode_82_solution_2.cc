/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        if(head->next->val != head->val)
        {
            // 如果head后面一位的元素的值不等于head的值，就从head->next开始接着处理后面的链表
            head -> next = deleteDuplicates(head -> next);
            return head;
        } 
        else
        {
            // 如果head后面一位的元素的值等于head的值，就跳过所有与head的值相等的元素，从第一个不等于head值的元素开始处理
            ListNode *curr = head;
            while(curr->next && curr->next->val==curr->val) curr = curr -> next;
            return deleteDuplicates(curr -> next);
        }
    }
};

作者：superkakayong
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/zi-jie-ti-ku-82-zhong-deng-shan-chu-pai-xu-lian-bi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。