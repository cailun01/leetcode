#include "headers.h"
#include "tree_node.h"

class Solution {
public:
    vector<int> v;
    vector<int> res;
    
    vector<int> findMode(TreeNode* root) {
        int max = 1;
        int cur = 1;
        inOrder(root);
        if(v.size() == 0) return res;//处理输入为空的情况
        res.push_back(v[0]);//初始化res数组
        for(int i = 1;i < v.size(); i++)//求数组v的众数
        {
            if(v[i] == v[i-1])
                cur++;
            else
                cur = 1;
            if(cur == max)
                res.push_back(v[i]);
            else if(cur > max)
            {
                res.clear();
                max = cur;
                res.push_back(v[i]);
            }
        }
        return res;
    }
    
    void inOrder(TreeNode* root)//中序遍历
    {
        if(root == NULL)  return;
        inOrder(root->left);
        v.push_back(root->val);
        inOrder(root->right);
    }
};
