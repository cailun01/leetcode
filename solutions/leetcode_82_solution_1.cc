class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode *dummyhead = new ListNode(INT_MAX);
        dummyhead -> next = head;
        ListNode *prev = dummyhead;
        while(prev && prev->next)
        {
            ListNode *curr = prev -> next;
            // 如果curr到最后一位了或者当前curr所指元素没有重复值
            if(!curr->next || curr->next->val != curr->val) prev = curr;
            else
            {
                // 将curr定位到一串重复元素的最后一位
                while(curr->next && curr->next->val == curr->val) curr = curr -> next;
                // prev->next跳过中间所有的重复元素
                prev -> next = curr -> next;
            }  
        }
        return dummyhead -> next;
    }
};

作者：superkakayong
链接：https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/zi-jie-ti-ku-82-zhong-deng-shan-chu-pai-xu-lian-bi/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。