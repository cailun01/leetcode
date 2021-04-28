#include "headers.h"
#include "tree_node.h"

class Solution {
private:
    unordered_map<int, int> index;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0 || inorder.size() == 0) {
            return nullptr;
        }
        // 构造哈希映射，帮助我们快速定位根节点
        for (int i = 0; i < preorder.size(); ++i) {
            index[inorder[i]] = i;
        }

        TreeNode* root = recursion(preorder, 0, preorder.size() - 1,
                                   inorder, 0, inorder.size() - 1);
        return root;
    }

    TreeNode* recursion(vector<int>& preorder, int pre_low, int pre_high,
                        vector<int>& inorder, int in_low, int in_high) {
        if (pre_low > pre_high) {
             // 不能用中序遍历的索引作base case
            return nullptr;
        }
        // 前序遍历数组的第一个数是根节点。
        int root_val = preorder[pre_low];
                
        // 在中序遍历中定位根节点
        int root_inorder_idx = index[preorder[pre_low]];

        // 左子树的节点数目
        int left_sub_tree_size = root_inorder_idx - in_low;
        TreeNode* root = new TreeNode(root_val);
        root->left = recursion(
            preorder, pre_low + 1, pre_low + left_sub_tree_size,
            inorder, in_low, root_inorder_idx - 1
        );
        root->right = recursion(
            preorder, pre_low + 1 + left_sub_tree_size, pre_high,
            inorder, root_inorder_idx + 1, in_high
        );
        return root;
    }
};