class Solution {
private:
    int num = 0;
    int res = 0;;
public:
    void search(TreeNode* root, int k) {
        if (!root) {
            return;
        }
        if (root->left) {
            search(root->left, k);
        }
        ++num;
        if (num == k) {
            res = root->val;
        } else if (num > k) {
            return;
        }
        if (root->right) {
            search(root->right, k);
        }
        return;
    }
    int kthSmallest(TreeNode* root, int k) {
        search(root, k);
        return res;
    }
};