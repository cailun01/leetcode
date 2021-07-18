/* 124 二叉树的最大路径和
路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。
同一个节点在一条路径序列中 至多出现一次 。
该路径 至少包含一个节点，且不一定经过根节点。
路径和 是路径中各节点值的总和。
给你一个二叉树的根节点 root ，返回其最大路径和 。

示例 1：
输入：root = [1,2,3]
输出：6
解释：最优路径是 2 -> 1 -> 3 ，路径和为 2 + 1 + 3 = 6

示例 2：
输入：root = [-10,9,20,null,null,15,7]
输出：42
解释：最优路径是 15 -> 20 -> 7 ，路径和为 15 + 20 + 7 = 42
 
提示：
树中节点数目范围是 [1, 3 * 104]
-1000 <= Node.val <= 1000
*/

class Solution {
public:
  int result = INT_MIN;
  // maxPath函数返回以root为路径起始点的最长路径
  int maxPath(TreeNode* root) {
    if (!root) {
      return 0;
    }
    // left,right分别为根节点左右子树最大路径和
    // 注意：如果最大路径和<0,意味着该路径和对总路径和做负贡献，因此不要计入到总路径中，将它设置为0
    int left = max(maxPath(root->left), 0);
    int right = max(maxPath(root->right), 0);
    // 比较当前最大路径和与左右子树最长路径加上根节点值的较大值，更新全局变量
    result = max(result, left + right + root->val);
    // 返回左右子树较长的路径加上根节点值
    return max(left + root->val, right + root->val);
  }

  int maxPathSum(TreeNode* root) {
    maxPath(root);
    return result;
  }
};
