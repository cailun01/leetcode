#include "headers.h"
#include "tree_node.h"

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        int layer = 0;
        while (!q.empty()) {
            int count = q.size();
            while (count--) {
                TreeNode* curr = q.front();
                q.pop();
                if (curr->left) q.push(curr->left);
                if (curr->right) q.push(curr->right);
            }
            ++layer;
        }
        return layer;
    }
};