#include "headers.h"

class Solution {
 public:
  ListNode* rotateRight(ListNode* head, int k) {
    // 输入是空指针则返回空指针
    if (!head) return nullptr;
    // k 为0或只有1个节点，返回该节点。
    if (k == 0 || !head->next) return head;
    // 还有一种特殊情况，即k大于链表长度length，且k能被length整除，
    // 此时直接返回head，这种情况在下面的循环中处理。
    int length = 2;
    // 计算链表长度length时，只在第一次循环时计算，其余的循环不能再修改length
    // 这个变量，用一个bool值标记第一次循环
    bool first_cycle = true;
    while (k > 0) {
      ListNode* node = head;
      ListNode* post = head->next;
      while (post->next) {
        node = node->next;
        post = post->next;
        if (first_cycle) {
            ++length;
        }
      // 这个while循环结束后，post指向倒数第一个节点，
      // node指向倒数第二个节点
      }
      // 当k>length时，计算k除以length的余数remainder，
      // 只需要循环remainder次
      if (k > length) {
        int remainder = k % length;
        // k能被length整除时，直接返回head
        if (remainder == 0) {
          break;
        }
        // 取模
        k = k % length; 
      } 
      --k;
      // 最后一个节点的next要指向头节点
      post->next = head;
      // 最后一个节点变为新链表的头结点
      head = post;
      // 倒数第二个节点变为新链表的最后一个节点
      node->next = nullptr;
      first_cycle = false;
    }
    return head;
  }
};