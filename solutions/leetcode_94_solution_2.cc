#include "headers.h"
#include "tree_node.h"
// 94. 二叉树的中序遍历
// 递归法
class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> res;
    recursion(root, res);
    return res;
  }

  void recursion(TreeNode* node, vector<int>& output) {
    if (node->left) {
      recursion(node->left, output);
    }
    if (!node) {
      return;
    }
    output.push_back(node->val);
    if (node->right) {
      recursion(node->right, output);
    }
  }
};