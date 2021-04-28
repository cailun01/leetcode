#include "headers.h"
#include "tree_node.h"

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

    TreeNode* create(vector<int>& inorder, int in_l, int in_r,
                     vector<int>& postorder, int post_l, int post_r) {
        if (post_l > post_r) {
            return nullptr;
        }
        int root_val = postorder.at(post_r);
        TreeNode* root = new TreeNode(root_val);
        int k = 0;
        for (k = in_l; k <= in_r; ++k) {
            if (inorder.at(k) == root_val) {
                break;
            }
        }
        int num_left = k - in_l;
        root->left = create(inorder, in_l, in_l + num_left - 1,
                            postorder, post_l, post_l + num_left - 1);
        root->right = create(inorder, k + 1, in_r,
                             postorder, post_l + num_left, post_r - 1);
        return root;
    }
};
