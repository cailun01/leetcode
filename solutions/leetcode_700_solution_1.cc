#include "headers.h"
#include "tree_node.h"
// 迭代
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while (root != nullptr) {
            if (root->val > val) {
                root = root->left;
            } else if (root->val < val) {
                root = root->right;
            } else {
                return root;
            }
        }
        return root;
    }
};