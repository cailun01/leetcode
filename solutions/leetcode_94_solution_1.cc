#include "headers.h"
#include "tree_node.h"
// 94. 二叉树的中序遍历
// 迭代法

class Solution {
public:
  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> stk;
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
      // 把root、以及root左孩子都压入栈中
        stk.push(root);
        root = root->left;
      }
      root = stk.top();
      stk.pop();
      res.push_back(root->val);
      // 此处是访问右子树的过程
      root = root->right;
    }
    return res;
  }
};