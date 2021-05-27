/* 103. 二叉树的锯齿形层序遍历
给定一个二叉树，返回其节点值的锯齿形层序遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。

例如：
给定二叉树 [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7
返回锯齿形层序遍历如下：

[
  [3],
  [20,9],
  [15,7]
]
*/

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) {
        return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    int layer = 1;
    while (!q.empty()) {
      int count = q.size();
      vector<int> current_layer_nodes;
      while (count--) {
        TreeNode* node = q.front();
        q.pop();
        current_layer_nodes.push_back(node->val);
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      if (layer % 2 == 0) {
        reverse(current_layer_nodes.begin(), current_layer_nodes.end());
      }
      res.push_back(current_layer_nodes);
      layer++;
    }
    return res;
  }
};