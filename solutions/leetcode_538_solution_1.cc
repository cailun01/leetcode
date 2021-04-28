class Solution {
private:
    int sum = 0;
public:
    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }

        traverse(root->right);
        sum += root->val;
        root->val = sum;
        traverse(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        traverse(root);
        return root;
    }
};