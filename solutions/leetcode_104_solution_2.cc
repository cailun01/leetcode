#include "headers.h"
#include "tree_node.h"

// recursion

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        int l_depth = maxDepth(root->left) + 1;
        int r_depth = maxDepth(root->right) + 1;
        return max(l_depth, r_depth);
    }
};