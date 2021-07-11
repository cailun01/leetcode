/* 958. 二叉树的完全性检验
给定一个二叉树，确定它是否是一个完全二叉树。

百度百科中对完全二叉树的定义如下：

若设二叉树的深度为 h，除第 h 层外，其它各层 (1～h-1) 的结点数都达到最大个数，
第 h 层所有的结点都连续集中在最左边，这就是完全二叉树。（注：第 h 层可能包含 1~ 2h 个节点。）
*/

/*
问题转换
什么时候是不完全呢？其实就是出现null结点之后后面又出现了结点，如果是完全则最后一个null结点之后就结束遍历了

思路
按照广度遍历（需要queue协助）来展开即可

*/
class Solution {
public:
  bool isCompleteTree(TreeNode* root) {
    // 层序遍历的辅助利器
    queue<TreeNode*> q;
    // 记录是否已经遍历到null结果
    bool reachNull = false;
    q.push(root);
    while (!q.empty()) {
      TreeNode* curr = q.front();
      q.pop();
      if (curr == nullptr) {
          // 发现空结点了
          reachNull = true;
          continue;
      } else {
        // 发现null结点后出现非空结点，发现不完全了
        if (reachNull) {
            return false;
        }
        // 继续遍历左右节点
        q.push(curr->left);
        q.push(curr->right);
      }
    }
    return true;
  }
};
