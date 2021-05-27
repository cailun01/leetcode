/* 111 二叉树的最小深度

给定一个二叉树，找出其最小深度。
最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
说明：叶子节点是指没有子节点的节点。
 */
class Solution {
public:
  int minDepth(TreeNode* root) {
    if (!root) {
      return 0;
    }
    queue<TreeNode*> q;
    q.push(root);
    // root 本身就是一层，depth 初始化为 1
    int depth = 1;
    while (!q.empty()) {
      int size = q.size();
      /* 将当前队列中的所有节点向四周扩散，对于二叉树就是向子树扩散 */
      for (int i = 0; i < size; ++i) {
        TreeNode* cur = q.front();
        q.pop();
        /* 判断是否到达终点，叶子节点没有孩子节点 */
        if (cur->left == nullptr && cur->right == nullptr) {
          return depth;
        }
        if (cur->left != nullptr) {
          q.push(cur->left);
        }
        if (cur->right != nullptr) {
          q.push(cur->right);
        }
      }
      /* 这里增加层数 */
      ++depth;
    }
    return depth;
  }
};