#include "headers.h"
#include "tree_node.h"
// 145. 二叉树的后序遍历
// 非递归解法：
// https://www.bilibili.com/video/av23885544?from=search&seid=3644923589944435142

// 因为后序非递归遍历二叉树的顺序是先访问左子树，再访问右子树，最后访问根节点。当用
// 堆栈来存储节点，必须分清返回根节点时，是从左子树返回的，还从右子树返回的。所以，
// 使用辅助指针prev，其指向最近访问过的节点。也可以在节点中增加一个标志域，记录是否已被
// 访问

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    if (!root) return {};
    vector<int> vec;
    stack<TreeNode *> stk;
    TreeNode *prev = nullptr;
    auto node = root;
    while (!stk.empty() || node) {
      // 1.遍历到最左子节点
      while (node) {
        stk.push(node);
        node = node->left;
      }
      node = stk.top(); 
      stk.pop();
      // 2.遍历最左子节点的右子树(右子树存在 && 未访问过)
      if (node->right && node->right != prev) {
        // 重复压栈以记录当前路径分叉节点
        stk.push(node);
        node = node->right;      
      } else {
        // 后序：填充vec在node->left和node->right后面
        // 注意：此时node的左右子树应均已完成访问
        vec.push_back(node->val);
        // 避免重复访问右子树[记录当前节点便于下一步对比]
        prev = node;
        // 避免重复访问左子树[设空节点]
        node = nullptr;
      }
    }
    return vec;
  }
};

