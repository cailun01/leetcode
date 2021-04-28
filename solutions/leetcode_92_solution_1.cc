#include "headers.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* successor = nullptr;
    
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }

        ListNode* last = reverseN(head->next, n - 1);
        head->next->next = head;
        head->next = successor;
        return last;

    }

    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head || head->next == nullptr) {
            return head;
        }
        if (m == 1) {
            return reverseN(head, n);
        }

        head->next = reverseBetween(head->next, m - 1, n - 1);
        return head;
    }
};