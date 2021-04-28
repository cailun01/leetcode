#include "headers.h"
#include "tree_node.h"

class Solution {
public:
    int rob(TreeNode* root) {
      vector<int> res = dp(root);
    }

    vector<int> dp(TreeNode* root) {
      if (!root) return {0, 0};
      /* 返回一个大小为 2 的数组 arr
      arr[0] 表示不抢 root 的话，得到的最大钱数
      arr[1] 表示抢 root 的话，得到的最大钱数 */
      vector<int> left = dp(root->left);
      vector<int> right = dp(root->right);
      // 抢，下家就不能抢了
      int rob = root->val + left[0] + right[0];
      // 不抢，下家可抢可不抢，取决于收益大小
      int not_rob = max(left[0], left[1]) + 
                    max(right[0], right[1]);
      return {not_rob, rob};
    }
};