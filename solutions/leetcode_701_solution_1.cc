class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            return new TreeNode(val);
        }
        // 目标值val小于root的值，插入到左子树
        if (root->val > val) {
            root->left = insertIntoBST(root->left, val);
        } 
        // 目标值val大于root的值，插入到右子树
        if (root->val < val) {
            root->right = insertIntoBST(root->right, val);
        }
        return root;
    }
};