class Solution {
private:
  ListNode* head;
public:
  /** @param head The linked list's head.
      Note that the head is guaranteed to be not null, so it contains at least one node. */
  Solution(ListNode* head) : head(head) {

  }
  
  /** Returns a random node's value. */
  int getRandom() {
    int k = 2;
    int res = head->val;
    ListNode* curr = head->next;
    while (curr != nullptr) {
      if (rand() % k == 0) { // [0, k-1]闭区间内随机产生一个整数
        res = curr->val;
      }
      curr = curr->next;
      ++k;
    }
    return res;
  }
};