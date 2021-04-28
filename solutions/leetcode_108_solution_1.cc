#include "headers.h"
#include "tree_node.h"

class Solution {
public:
    TreeNode* DFS(vector<int>& nums, int start, int end){
        if(start == end){
            return NULL;
        }
        int mid = (start + end)>>1;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = DFS(nums, start, mid);
        root->right = DFS(nums, mid+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return DFS(nums, 0, nums.size());
    }
};
