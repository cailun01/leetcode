#include "headers.h"
#include "tree_node.h"
/* 106. 从中序与后序遍历序列构造二叉树
根据一棵树的中序遍历与后序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出
中序遍历 inorder = [9,3,15,20,7]
后序遍历 postorder = [9,15,7,20,3]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/

class Solution {
public:
  TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
    if (inorder.empty() || postorder.empty()) {
      return nullptr;
    }
    int n = inorder.size();
    TreeNode* node = create(inorder, 0, n - 1,
                            postorder, 0, n - 1);
    return node;
  }

  TreeNode* create(vector<int>& inorder, int in_start, int in_end,
                    vector<int>& postorder, int post_start, int post_end) {
    if (post_start > post_end) {
      return nullptr;
    }
    int root_val = postorder[post_end];
    TreeNode* root = new TreeNode(root_val);
    int inorder_root_idx = 0;
    for (inorder_root_idx = in_start; inorder_root_idx <= in_end; ++inorder_root_idx) {
      if (inorder[inorder_root_idx] == root_val) {
        break;
      }
    }
    int num_left = inorder_root_idx - in_start;
    root->left = create(inorder, in_start, inorder_root_idx - 1,
                        postorder, post_start, post_start + num_left - 1);
    root->right = create(inorder, inorder_root_idx + 1, in_end,
                          postorder, post_start + num_left, post_end - 1);
    return root;
  }
};
