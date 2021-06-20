/* 234 回文链表
请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
*/


/* 解法1： 将链表中的值复制到数组中后用双指针法。
确定数组列表是否回文很简单，我们可以使用双指针法来比较两端的元素，并向中间移动。
一个指针从起点向中间移动，另一个指针从终点向中间移动。这需要O(n)的时间，因为访问每个元素的时间是O(1)，
而有n个元素要访问。

第一步，我们需要遍历链表将值复制到数组列表中。我们用 currentNode 指向当前节点。
每次迭代向数组添加 currentNode.val，并更新 currentNode = currentNode.next，当 currentNode = null 时停止循环。

第二步，用双指针法来检查是否为回文。我们在起点放置一个指针，在结尾放置一个指针，
每一次迭代判断两个指针指向的元素是否相同，若不同，返回 false；相同则将两个指针向内移动，
并继续判断，直到两个指针相遇。
*/

class Solution {
public:
  bool isPalindrome(ListNode* head) {
    vector<int> vals;
    while (head != nullptr) {
      vals.push_back(head->val);
      head = head->next;
    }
    for (int i = 0, j = vals.size() - 1; i < j; ++i, --j) {
      if (vals[i] != vals[j]) {
        return false;
      }
    }
    return true;
  }
};
