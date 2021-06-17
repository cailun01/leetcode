#include "headers.h"
#include "tree_node.h"
/* 104 二叉树的最大深度
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例：
给定二叉树 [3,9,20,null,null,15,7]，

    3
   / \
  9  20
    /  \
   15   7
*/

// recursion

class Solution {
public:
  int maxDepth(TreeNode* root) {
    if (!root) return 0;
    int l_depth = maxDepth(root->left) + 1;
    int r_depth = maxDepth(root->right) + 1;
    return max(l_depth, r_depth);
  }
};