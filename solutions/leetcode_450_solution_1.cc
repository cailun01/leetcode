#include "headers.h"
#include "tree_node.h"

/* 450 删除二叉搜索树中的节点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，
并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。

*/

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
      } else if (root->left) {  // 如果左子树存在，则在左子树中找最大节点，替换root
        // 找到左子树的最大节点
        TreeNode* pre = findPre(root);
        // 把 root 改成 pre
        root->val = pre->val;
        // 转而去删除 pre
        root->left = deleteNode(root->left, pre->val);
      } else if (root->right) { // 如果右子树存在，则在右子树中找最小节点，替换root
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