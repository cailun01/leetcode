#include "headers.h"
#include "tree_node.h"
// 144. 给你二叉树的根节点 root ，返回它节点值的前序遍历。
// 使用stack，迭代解法

class Solution {
public:
  vector<int> preorderTraversal(TreeNode* head) {
    if (head == nullptr) {
      return {};
    }
    stack<TreeNode*> tree_stack;
    tree_stack.push(head);
    vector<int> vec;
    while (!tree_stack.empty()) {
      TreeNode* node = tree_stack.top();
      tree_stack.pop();
      // 将栈顶元素放入vec
      vec.push_back(node->val);
      // 先放右子树
      if (node->right != nullptr) {
        tree_stack.push(node->right);
      }
      // 再放左子树
      if (node->left != nullptr) {
        tree_stack.push(node->left);
      }
    }
    return vec;
  }
};