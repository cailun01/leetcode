/* 230 二叉搜索树中第K小的元素
给定一个二叉搜索树的根节点 root ，和一个整数 k ，请你设计一个算法查找其中第 k 个最小元素（从 1 开始计数）。
*/

class Solution {
private:
  // 记录当前元素的排名
  int num = 0;
  // 记录结果
  int res = 0;;
public:
  void search(TreeNode* root, int k) {
    if (!root) {
      return;
    }
    if (root->left) {
      search(root->left, k);
    }
    // 中序遍历
    ++num;
    if (num == k) {
      // 找到第 k 小的元素
      res = root->val;
    } else if (num > k) {
      // 剪枝
      return;
    }
    if (root->right) {
      search(root->right, k);
    }
    return;
  }
  int kthSmallest(TreeNode* root, int k) {
    search(root, k);
    return res;
  }
};