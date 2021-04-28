#include "headers.h"
#include "tree_node.h"
// 94. 二叉树的中序遍历
// 迭代法
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
      if (!root) return {};
      stack<TreeNode*> node_stack;
      vector<int> vec;
      do {
        while (root != nullptr) {
          // 把root、以及root左孩子都压入栈中
          node_stack.push(root);
          root = root->left;
        }
        if (!node_stack.empty()) {
          TreeNode* node = node_stack.top();
          node_stack.pop();
          vec.push_back(node->val);
          root = node->right;
        }
      } while (root != nullptr || !node_stack.empty());
      return vec;
    }
};