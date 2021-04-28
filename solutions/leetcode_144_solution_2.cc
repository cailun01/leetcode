#include "headers.h"
#include "tree_node.h"

// 给你二叉树的根节点 root ，返回它节点值的前序遍历。
// 递归解法

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* root) {
    if (!root) return {};
    vector<int> result;
    recursion(root, result);
    return result;
  }

  void recursion(TreeNode* root, vector<int>& vec) {
    if (!root) return;
    vec.push_back(root->val);
    
    if (root->left) {
      recursion(root->left, vec);
    }
    if (root->right) {
      recursion(root->right, vec);
    }
  }
};