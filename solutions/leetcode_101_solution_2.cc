#include "headers.h"
#include "tree_node.h"
// 除了递归的方法外，我们也可以利用队列进行迭代。队列中每两个连续的结点应该是相等的，
// 而且它们的子树互为镜像。最初，队列中包含的是 root 以及 root。
// 该算法的工作原理类似于 BFS，但存在一些关键差异。每次提取两个结点并比较它们的值。
// 然后，将两个结点的左右子结点按相反的顺序插入队列中。
// 当队列为空时，或者我们检测到树不对称（即从队列中取出两个不相等的连续结点）时，该算法结束。

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
      queue<TreeNode*> q;
      q.push(root);
      q.push(root);
      while (!q.empty()) {
        TreeNode* t1 = q.front();
        q.pop();
        TreeNode* t2 = q.front();
        q.pop();
        if (!t1 && !t2) {
          continue;
        }
        if (!t1 || !t2) {
          return false;
        }
        if (t1->val != t2->val) {
          return false;
        }
        q.push(t1->left);
        q.push(t2->right);
        q.push(t1->right);
        q.push(t2->left);
      }
      return true;
    }
};