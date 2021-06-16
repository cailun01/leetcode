#include "headers.h"
#include "tree_node.h"
/* 98. 验证二叉搜索树
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
示例 1:

输入:
    2
   / \
  1   3
输出: true
示例 2:

输入:
    5
   / \
  1   4
     / \
    3   6
输出: false
解释: 输入为: [5,1,4,null,null,3,6]。
     根节点的值为 5 ，但是其右子节点值为 4 。
*/
class Solution {
public:
  /* 限定以 root 为根的子树节点必须满足 max.val > root.val > min.val */
  bool isValidBST(TreeNode* root, TreeNode* min, TreeNode* max) {
    // base case
    if (!root) {
      return true;
    }
    // 若 root.val 不符合 max 和 min 的限制，说明不是合法 BST
    if (min && root->val <= min->val) {
      return false;
    }
    if (max && root->val >= max->val) {
      return false;
    }
    // 限定左子树的最大值是 root.val，右子树的最小值是 root.val
    return isValidBST(root->left, min, root) &&
            isValidBST(root->right, root, max);
  }

  bool isValidBST(TreeNode* root) {
    return isValidBST(root, nullptr, nullptr);
  }
};