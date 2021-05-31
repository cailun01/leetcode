/* 236 二叉树的最近公共祖先
给定一个二叉树, 找到该树中两个指定节点的最近公共祖先。

百度百科中最近公共祖先的定义为：“对于有根树 T 的两个节点 p、q，最近公共祖先表示为一个节点 x，
满足 x 是 p、q 的祖先且 x 的深度尽可能大（一个节点也可以是它自己的祖先）。”

*/
class Solution {
public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root) {
      return nullptr;
    }
    if (root == p || root == q) {
      return root;
    }

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if (left && right) {
      return root;
    }

    if (!left && !right) {
      return nullptr;
    }

    return left == nullptr ? right : left;   
  }
};

// https://mp.weixin.qq.com/s?src=11&timestamp=1615300164&ver=2936&signature=G5eSXsS6twm7acK-nZIKt1xSjdzOUeuw2I2-QZjJNnVSrADepO3WDX2S6rFFOEduP**YRiNjsYpOloh59C*Fes13*L8tjfSD6*j0yr4zUK7puZIVYZ6Wcav3Ka5Khc0S&new=1