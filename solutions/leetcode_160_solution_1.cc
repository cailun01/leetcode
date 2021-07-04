/* 160. 相交链表
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表没有交点，返回 null 。

图示两个链表在节点 c1 开始相交：


题目数据 保证 整个链式结构中不存在环。

注意，函数返回结果后，链表必须 保持其原始结构 。

示例 1：
输入：intersectVal = 8, listA = [4,1,8,4,5], listB = [5,0,1,8,4,5], skipA = 2, skipB = 3
输出：Intersected at '8'
解释：相交节点的值为 8 （注意，如果两个链表相交则不能为 0）。
从各自的表头开始算起，链表 A 为 [4,1,8,4,5]，链表 B 为 [5,0,1,8,4,5]。
在 A 中，相交节点前有 2 个节点；在 B 中，相交节点前有 3 个节点。
*/
/*
解释：
判断A和B的长度，如果A比B长n，则headA先移动n步，如果B比A长n，headB先移动n步。然后让headA与headB同时移动，直到headA == headB。
*/

class Solution {
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int num_a = 0;
    int num_b = 0;
    ListNode *node_a = headA, *node_b = headB;
    while (node_a) {
      num_a++;
      node_a = node_a->next;
    }
    while (node_b) {
      num_b++;
      node_b = node_b->next;
    }
    if (num_a > num_b) {
      for (int i = 0; i < num_a - num_b; ++i) {
        headA = headA->next;
      }
    } else if (num_a < num_b) {
      for (int i = 0; i < num_b - num_a; ++i) {
        headB = headB->next;
      }
    }
    while (headA != headB) {
      headA = headA->next;
      headB = headB->next;
    }
    return headA;
  }
};
