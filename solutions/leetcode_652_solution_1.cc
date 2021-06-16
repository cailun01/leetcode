/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

/*
需要解决的问题：
1、以我为根的这棵二叉树（子树）长啥样？

2、以其他节点为根的子树都长啥样？

解决方法：
1、使用「后序遍历」解决。我要知道以自己为根的子树长啥样，得先知道我的左右子树长啥样，再加上自己，就构成了整棵子树的样子。
2、借助一个外部数据结构，让每个节点把自己子树的序列化结果存进去，这样，对于每个节点，就可以知道有没有其他节点的子树和自己重复了
*/

class Solution {
private:
  // 借助unordered_map，存储每个节点的子树的序列化的结果
  // 并记录每颗子树出现的次数
  unordered_map<string, int> memo;
  vector<TreeNode*> result;
public:
  string traverse(TreeNode* root) {
    if (!root) {
      return string("#");
    }

    string left_sub_tree = traverse(root->left);
    string right_sub_tree = traverse(root->right);
    string sub_tree = left_sub_tree + "," + right_sub_tree + "," + to_string(root->val);
    int frequency = 0;
    if (memo.find(sub_tree) != memo.end()) {
      // 找到了重复子树
      frequency = memo[sub_tree];
      memo[sub_tree] += 1;
    } else {
      memo[sub_tree] = 1;
    }
    if (frequency == 1) {
      // frequency == 1说明在memo已经存在的子树中，又找到了重复子树
      result.push_back(root);
    }
    
    return sub_tree;
  }

  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
    traverse(root);
    return result;
  }
};
