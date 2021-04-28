#include "headers.h"
#include "tree_node.h"
// 145. 二叉树的后序遍历
// 递归解法
class Solution {
public:
  vector<int> postorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> result;
    postorder_recursion(root, result);
    return result;
  }

  void postorder_recursion(TreeNode* root, vector<int>& vec) {
    if (!root) return;
    if (root->left) {
      postorder_recursion(root->left, vec);
    }
    if (root->right) {
      postorder_recursion(root->right, vec);
    }
    if (root) {
      vec.push_back(root->val);
      return;
    }
  }
};