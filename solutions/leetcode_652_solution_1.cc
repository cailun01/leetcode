/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    // 借助unordered_map，存储每个节点的子树的序列化的结果
    // 并记录每颗子树出现的次数
    unordered_map<string, int> memo;
    vector<TreeNode*> result;
public:
    string traverse(TreeNode* root) {
        if (!root) {
            return string("#");
        }

        string left_sub_tree = traverse(root->left);
        string right_sub_tree = traverse(root->right);
        string sub_tree = left_sub_tree + "," + right_sub_tree + "," + to_string(root->val);
        int frequency = 0;
        if (memo.find(sub_tree) != memo.end()) {
            // 找到了重复子树
            frequency = memo[sub_tree];
            memo[sub_tree] += 1;
        } else {
            memo[sub_tree] = 1;
        }
        if (frequency == 1) {
            // frequency == 1说明在memo已经存在的子树中，又找到了重复子树
            result.push_back(root);
        }
        
        return sub_tree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        traverse(root);
        return result;
    }
};
