#include "headers.h"
#include "tree_node.h"

// 迭代算法
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    if (root == nullptr) return {};  
    queue<TreeNode*> q;     
    q.push(root);
    while (!q.empty()) {  
      vector<int> level;                //存放每一层的元素值
      int count = q.size();             //队列大小表示当前层数的元素个数
      while (count--) {                 //count--逐个对该层元素进行处理 
        TreeNode *t = q.front();             
        q.pop();     
        level.push_back(t->val);
        if(t->left)  {
          q.push(t->left);
        }   
        if(t->right) {
          q.push(t->right);
        }  
      }
      res.push_back(level);           //将当层元素的vector加入res中
    }
    return res;
  }
};
