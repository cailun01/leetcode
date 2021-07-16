/* 377 组合总和 Ⅳ
给你一个由不同整数组成的数组nums，和一个目标整数target。请你从nums中找出并返回总和为 target的元素组合的个数。

题目数据保证答案符合 32 位整数范围。

示例 1：
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。

示例 2：
输入：nums = [9], target = 3
输出：0
*/

class Solution {
public:
    unordered_map<int, int> memo;
    int combinationSum4(vector<int>& nums, int target) {
      // target==0的情况只有一种组合，就是不选择nums中的任何数字
      memo[0] = 1;
      return dp(nums, target);
    }

    // 函数 dp(nums, target) 表示从nums中挑选数字可以构成target的方法数
    int dp(vector<int>& nums, int target) {
      if (target < 0) {
        return 0;
      }
      if (memo.find(target) != memo.end()) {
        return memo[target];
      }
      int res = 0;
      for (auto num : nums) {
        res += dp(nums, target - num);
      }
      memo[target] = res;
      return res;
    }
};