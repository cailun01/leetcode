#include "headers.h"
#include "tree_node.h"
// 递归
class Solution {
public:
  TreeNode* searchBST(TreeNode* root, int val) {
    if (!root) {
      return nullptr;
    }
    if (val == root->val) {
      return root;
    } else if (val > root->val) {
      return searchBST(root->right, val);
    } else { // (val < root->val)
      return searchBST(root->left, val);
    }
  }
};
