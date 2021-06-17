#include "headers.h"
#include "tree_node.h"
// 二叉搜索树经过中序遍历，其节点的值单调递增
class Solution {
public:
  bool isValidBST(TreeNode* root) {
    stack<TreeNode*> stack;
    long long inorder = LLONG_MIN;
    while (!stack.empty() || root != nullptr) {
      while (root != nullptr) {
        stack.push(root);
        root = root->left;
      }
      root = stack.top();
      stack.pop();
      if (root->val <= inorder) {
        return false;
      }
      inorder = root->val;
      root = root->right;
    }
    return true;
  }
};