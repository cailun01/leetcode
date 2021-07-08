#include "headers.h"
#include "tree_node.h"

class Solution {
public:
  bool isSymmetric(TreeNode* root) {
      return isMirror(root, root);
  }

  bool isMirror(TreeNode* l, TreeNode* r) {
    if (l == nullptr && r == nullptr) {
      return true;
    }
    if ((!l && r) || (l && !r)) {
      return false;
    }
    if (l->val == r->val) {
      return isMirror(l->left, r->right) && isMirror(l->right, r->left);
    } else {
      return false;
    }
  }
};