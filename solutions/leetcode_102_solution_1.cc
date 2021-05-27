#include "headers.h"
#include "tree_node.h"

// 迭代算法
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (!root) return res;  
    queue<TreeNode*> q;     
    q.push(root);
    while (!q.empty()) {
      //存放每一层的元素值
      vector<int> level;
      //队列大小表示当前层数的元素个数            
      int count = q.size();
      //count--逐个对该层元素进行处理 
      while (count--) {   
        TreeNode *t = q.front();             
        q.pop();     
        level.push_back(t->val);
        if(t->left) {
          q.push(t->left);
        }
        if(t->right) {
          q.push(t->right);
        }  
      }
      //将当层元素的vector加入res中
      res.push_back(level);
    }
    return res;
  }
};
