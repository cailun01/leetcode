/* 110. 平衡二叉树
给定一个二叉树，判断它是否是高度平衡的二叉树。

本题中，一棵高度平衡二叉树定义为：

一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1 。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：true

示例 2：
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false

示例 3：
输入：root = []
输出：true

*/
class Solution {
public:
  int height(TreeNode* root) {
    if (root == NULL) {
      return 0;
    }
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    if (leftHeight == -1 || rightHeight == -1 
           || abs(leftHeight - rightHeight) > 1) {
      return -1;
    } else {
      return max(leftHeight, rightHeight) + 1;
    }
  }

  bool isBalanced(TreeNode* root) {
    return height(root) >= 0;
  }
};