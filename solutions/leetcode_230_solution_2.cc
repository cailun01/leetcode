#include "headers.h"
#include "tree_node.h"
// 迭代
class Solution {
public:
  int kthSmallest(TreeNode* root, int k) {
    TreeNode* cur = root;
    stack<TreeNode*> stk;
    int num = 0;
    while (!stk.empty() || cur) {
      while (cur) {
        stk.push(cur);
        cur = cur->left;
      }
      cur = stk.top();
      stk.pop();
      num++;
      if (num == k) {
        return cur->val;
      }
      cur = cur->right;
    }
    return 0;
  }
};