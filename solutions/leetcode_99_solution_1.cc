#include "headers.h"
#include "tree_node.h"
/* 99. 恢复二叉搜索树
给你二叉搜索树的根节点 root ，该树中的两个节点被错误地交换。请在不改变其结构的情况下，恢复这棵树。

进阶：使用 O(n) 空间复杂度的解法很容易实现。你能想出一个只使用常数空间的解决方案吗
*/

/**
 * 在第一次遇到不递增的情况时，将first设置为3，second设置为2，在第二次遇到不递增的情况时，
 * 只改变second，将second置为1.遍历结束后交换first与second。
 * 空间复杂度O(n)

 */
class Solution {
public:
  TreeNode* first = nullptr;
  TreeNode* second = nullptr;
  // 记录中序遍历时上一次遍历到的节点，其val一定小于当前val
  TreeNode* pre = nullptr;
  void inorder(TreeNode* root){
    if(!root) {
      return;            
    }

    inorder(root->left);
    if (pre != nullptr && pre->val > root->val){
      if (first == nullptr) {
        // first为空,首次找到前后大小不对的点
        first = pre;
        second = root;
      } else {
        // first不为空,第二次找到前后大小不对的点,只更新second
        second = root;
      }
    }
    pre = root;
    inorder(root->right);
  }

  void recoverTree(TreeNode* root) {
    inorder(root);
    int tmp = first->val;
    first->val = second->val;
    second->val = tmp;
  }
};
