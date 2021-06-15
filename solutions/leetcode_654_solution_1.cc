#include "tree_node.h"
/* 654 最大二叉树
给定一个不含重复元素的整数数组 nums 。一个以此数组直接递归构建的 最大二叉树 定义如下：

二叉树的根是数组 nums 中的最大元素。
左子树是通过数组中 最大值左边部分 递归构造出的最大二叉树。
右子树是通过数组中 最大值右边部分 递归构造出的最大二叉树。
返回有给定数组 nums 构建的 最大二叉树 。

输入：nums = [3,2,1,6,0,5]
输出：[6,3,5,null,2,0,null,null,1]
解释：递归调用如下所示：
- [3,2,1,6,0,5] 中的最大值是 6 ，左边部分是 [3,2,1] ，右边部分是 [0,5] 。
    - [3,2,1] 中的最大值是 3 ，左边部分是 [] ，右边部分是 [2,1] 。
        - 空数组，无子节点。
        - [2,1] 中的最大值是 2 ，左边部分是 [] ，右边部分是 [1] 。
            - 空数组，无子节点。
            - 只有一个元素，所以子节点是一个值为 1 的节点。
    - [0,5] 中的最大值是 5 ，左边部分是 [0] ，右边部分是 [] 。
        - 只有一个元素，所以子节点是一个值为 0 的节点。
        - 空数组，无子节点。
结果：
         6
       /   \
      3     5
      \     /
       2   0
        \
         1
*/

/*
https://labuladong.github.io/algo/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%B3%BB%E5%88%972.html
*/

class Solution {
public:
  TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
    if (nums.empty()) {
      return nullptr;
    }
    TreeNode* root = construct_by_index(nums, 0, nums.size());
    return root;
  }

  TreeNode* construct_by_index(vector<int>& nums, int low, int high) {
    if (low >= high) {
      return nullptr;
    }
    int max = INT_MIN;
    int max_index;
    for (int i = low; i < high; ++i) {
      if (nums[i] > max) {
        max = nums[i];
        max_index = i;
      }
    }
    TreeNode* root = new TreeNode(max);
    root->left = construct_by_index(nums, low, max_index);
    root->right = construct_by_index(nums, max_index + 1, high);
    return root;
  }
};
