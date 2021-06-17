#include "headers.h"
#include "tree_node.h"
/* 100. 相同的树
给你两棵二叉树的根节点 p 和 q ，编写一个函数来检验这两棵树是否相同。

如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
*/
class Solution {
public:
  bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
      return true;
    }
    if (p == nullptr || q == nullptr) {
      return false;
    }
    if (p->val == q->val) {
      return isSameTree(p->left, q->left) 
          && isSameTree(p->right, q->right);
    } else {
      return false;
    }
  }
};
