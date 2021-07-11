/* 82. 删除排序链表中的重复元素 II
存在一个按升序排列的链表，给你这个链表的头节点 head ，请你删除链表中所有存在数字重复情况的节点，
只保留原始链表中 没有重复出现 的数字。

返回同样按升序排列的结果链表。

示例 1：
输入：head = [1,2,3,3,4,4,5]
输出：[1,2,5]

示例 2：
输入：head = [1,1,1,2,3]
输出：[2,3]

*/

/* 方法一：递归
https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/solution/fu-xue-ming-zhu-di-gui-die-dai-yi-pian-t-wy0h/
链表和树的问题，一般都可以有递归和迭代两种写法。对于本题一定记住是有序链表，值相同的节点会在一起。

1.1 递归函数定义
递归最基本的是要明白递归函数的定义！ 我反复强调过这一点。

递归函数直接使用题目给出的函数 deleteDuplicates(head) ，它的含义是 删除以 head 作为开头的有序链表中，值出现重复的节点。

1.2 递归终止条件
终止条件就是能想到的基本的、不用继续递归处理的case。
  如果 head 为空，那么肯定没有值出现重复的节点，直接返回 head；
  如果 head.next 为空，那么说明链表中只有一个节点，也没有值出现重复的节点，也直接返回 head。
1.3 递归调用
什么时候需要递归呢？我们想一下这两种情况：
1.3.1
如果 head.val != head.next.val ，说明头节点的值不等于下一个节点的值，所以当前的 head 节点必须保留；
但是 head.next 节点要不要保留呢？我们还不知道，需要对 head.next 进行递归，即对 head.next 作为头节点的链表，
去除值重复的节点。所以 head.next = self.deleteDuplicates(head.next).
1.3.2
如果 head.val == head.next.val ，说明头节点的值等于下一个节点的值，所以当前的 head 节点必须删除，
并且 head 之后所有与 head.val 相等的节点也都需要删除；删除到哪个节点为止呢？
需要用 move 指针一直向后遍历寻找到与 head.val 不等的节点。此时 move 之前的节点都不保留了，
因此返回 deleteDuplicates(move);

1.4 返回结果
题目让我们返回删除了值重复的节点后剩余的链表，结合上面两种递归调用的情况。

如果 head.val != head.next.val ，头结点需要保留，因此返回的是 head；
如果 head.val == head.next.val ，头结点需要删除，需要返回的是deleteDuplicates(move);。
对链表 1 -> 2 -> 2 -> 3 递归的过程如下。


*/
class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) {
      return head;
    }
    if (head->val != head->next->val) {
      head->next = deleteDuplicates(head->next);
    } else {
      ListNode* move = head->next;
      while (move && head->val == move->val) {
        move = move->next;
      }
      // 此时head->val != move->val
      return deleteDuplicates(move);
    }
    return head;
  }
};

