#include "headers.h"
#include "tree_node.h"
/* 105. 从前序与中序遍历序列构造二叉树
根据一棵树的前序遍历与中序遍历构造二叉树。

注意:
你可以假设树中没有重复的元素。

例如，给出

前序遍历 preorder = [3,9,20,15,7]
中序遍历 inorder = [9,3,15,20,7]
返回如下的二叉树：

    3
   / \
  9  20
    /  \
   15   7
*/

class Solution {
private:
  // key:节点值，value:该值在inorder的索引
  unordered_map<int, int> index;
public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    if (preorder.size() == 0 || inorder.size() == 0) {
      return nullptr;
    }

    // 快速定位根节点在中序遍历数组的索引
    for (int i = 0; i < inorder.size(); ++i) {
      index[inorder[i]] = i;
    }

    TreeNode* root = recursion(preorder, 0, preorder.size() - 1,
                                inorder, 0, inorder.size() - 1);
    return root;
  }

  TreeNode* recursion(vector<int>& preorder, int pre_start, int pre_end,
                    vector<int>& inorder, int in_start, int in_end) {
    if (pre_start > pre_end) {
      // 不能用中序遍历的索引作base case
      return nullptr;
    }
    // 前序遍历数组的第一个数是根节点。
    int root_val = preorder[pre_start];
            
    // 在中序遍历中定位根节点
    int inorder_root_idx = index[root_val];

    // 左子树的节点数目
    int left_sub_tree_size = inorder_root_idx - in_start;
    TreeNode* root = new TreeNode(root_val);
    // 递归创建左子树
    root->left = recursion(
      preorder, pre_start + 1, pre_start + left_sub_tree_size,
      inorder, in_start, inorder_root_idx - 1);
    // 递归创建右子树
    root->right = recursion(
      preorder, pre_start + 1 + left_sub_tree_size, pre_end,
      inorder, inorder_root_idx + 1, in_end);
    return root;
  }
};