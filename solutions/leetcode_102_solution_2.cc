#include "headers.h"
#include "tree_node.h"

// 递归
class Solution {
public:
    vector<vector<int>> res;   
    vector<vector<int>> levelOrder(TreeNode* root) {
        addVector(root,0);      //调用递归函数
        return res;
    }
  
    void addVector(TreeNode* root,int level) {
        if(root == nullptr) return;
        if(res.size() == level) {
          res.resize(level+1);    //level表示层数，也对应二维数组的第一层索引，
        }
        res[level].push_back(root->val);
        addVector(root->left,level+1);
        addVector(root->right,level+1);
    }
};
