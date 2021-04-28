#include "headers.h"
#include "tree_node.h"

class Solution {
public:
    // 在左子树找最大节点
    TreeNode* findPre(TreeNode* root) {
      root = root->left;
      while (root->right) {
        root = root->right;
      }
      return root;
    }
    // 在右子树找最小节点
    TreeNode* findSuc(TreeNode* root) {
      root = root->right;
      while (root->left) {
        root = root->left;
      }
      return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
      if (!root) {
        return nullptr;
      }
      if (root->val == key) {
        if (root->left == nullptr && root->right == nullptr) {
          root = nullptr;
        } else if (root->left) { // 如果左子树存在，则在左子树中找最大节点，替换root
          TreeNode* pre = findPre(root);
          root->val = pre->val;
          root->left = deleteNode(root->left, pre->val);
        } else { // 如果右子树存在，则在右子树中找最小节点，替换root
          TreeNode* successor = findSuc(root);
          root->val = successor->val;
          root->right = deleteNode(root->right, successor->val);
        }
      } else if (root->val > key) {
        // 查找左子树
        root->left = deleteNode(root->left, key);
      } else { // root->val < key
        // 查找右子树
        root->right = deleteNode(root->right, key);
      }
      return root;
    }
};