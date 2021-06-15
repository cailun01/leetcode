#include "tree_node.h"
/* 226. 翻转二叉树
翻转一棵二叉树。

示例：

输入：

     4
   /   \
  2     7
 / \   / \
1   3 6   9
输出：

     4
   /   \
  7     2
 / \   / \
9   6 3   1
*/

/*
 解析
 https://labuladong.github.io/algo/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%B3%BB%E5%88%971.html
*/

class Solution {
public:
  TreeNode* invertTree(TreeNode* root) {
    if (!root) {
      return nullptr;
    }
    
    /**** 前序遍历位置 ****/
    // root 节点需要交换它的左右子节点
    TreeNode* temp = nullptr;
    temp = root->left;
    root->left = root->right;
    root->right = temp;

    // 让左右子节点继续翻转它们的子节点
    invertTree(root->left);
    invertTree(root->right);
    return root;
  }
};
