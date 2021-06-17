/* 222 完全二叉树的节点个数
给你一棵 完全二叉树 的根节点 root ，求出该树的节点个数。

完全二叉树 的定义如下：在完全二叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最大值，
并且最下面一层的节点都集中在该层最左边的若干位置。若最底层为第 h 层，则该层包含 1~ 2^h 个节点。
*/

/*
普通二叉树有常规解法，完美二叉树有特殊解法。
*/
class Solution {
public:
  int countNodes(TreeNode* root) {
    if (!root) {
      return 0;
    }
    // 记录左子树的高度和右子树的高度
    TreeNode* l = root;
    TreeNode* r = root;
    int height_of_left_sub = 0;
    int height_of_right_sub = 0;
    while (l) {
      l = l->left;
      height_of_left_sub += 1;
    }
    while (r) {
      r = r->right;
      height_of_right_sub += 1;
    }

    // 如果左右子树的高度相同，则是一棵满二叉树
    if (height_of_left_sub == height_of_right_sub) {
      return static_cast<int>(pow(2, height_of_left_sub) - 1);
    }
    // 如果左右高度不同，则按照普通二叉树的逻辑计算
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};
