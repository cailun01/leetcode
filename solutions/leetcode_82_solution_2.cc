/*方法二：一次遍历
这里说的一次遍历，是说一边遍历、一边统计相邻节点的值是否相等，如果值相等就继续后移找到值不等的位置，
然后删除值相等的这个区间。

其实思路很简单，跟递归方法中的 while 语句跳过所有值相等的节点的思路是一样的：
如果 cur.val == cur.next.val  说明两个相邻的节点值相等，所以继续后移，
一直找到 cur.val != cur.next.val  ，此时的 cur.next  就是值不等的节点。

    比如： 1 -> 2 -> 2 -> 2 -> 3，我们用一个 pre 指向 1；当 cur 指向第一个 2 的时候，
    发现 cur.val == cur.next.val  ，所以出现了值重复的节点啊，所以 cur 一直后移到最后一个 2 的时候，
    发现 cur.val != cur.next.val  ，此时 cur.next = 3 ，所以 pre.next = cur.next ，
    即让1 的 next 节点是 3，就把中间的所有 2 都删除了。
代码中用到了一个常用的技巧：dummy 节点，也叫做 哑节点。它在链表的迭代写法中非常常见，
因为对于本题而言，我们可能会删除头结点 head，为了维护一个不变的头节点，
所以我们添加了 dummy，让dummy.next = head，这样即使 head 被删了，那么会操作 dummy.next 指向新的链表头部，
所以最终返回的也是 dummy.next。
*/

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    ListNode* pre = dummy;
    ListNode* cur = head;
    while (cur) {
      //跳过当前的重复节点，使得cur指向当前重复元素的最后一个位置
      while (cur->next && cur->val == cur->next->val) {
        cur = cur->next;
      }
      if (pre->next == cur) {
        // pre和cur之间没有重复节点，pre后移
        pre = pre->next; 
      } else {
        //pre->next指向cur的下一个位置（相当于跳过了当前的重复元素）
        //但是pre不移动，仍然指向已经遍历的链表结尾
        pre->next = cur->next;
      }
      cur = cur->next;
    }
    return dummy->next;
  }
};
