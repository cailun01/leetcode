#include "headers.h"
// 给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

// 示例:
// 输入: [-2,1,-3,4,-1,2,1,-5,4],
// 输出: 6
// 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。

// 进阶:
// 如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
      //类似寻找最大最小值的题目，初始值一定要定义成理论上的最小最大值
      int result = INT_MIN;
      int numsSize = nums.size();
      //dp[i]表示nums中以nums[i]结尾的最大子序和
      vector<int> dp(numsSize);
      dp[0] = nums[0];
      result = dp[0];
      for (int i = 1; i < numsSize; i++) {
        // 最大和只有两种情况：
        //   1. 最大和的连续序列只有一个元素，即nums[i]本身
        //   2. 最大和的连续序列有多个元素，即从前面某处nums[p](p<i)开始，
        //      一直到nums[i]结尾。最大和是：
        //      nums[p] + ... + nums[i-1] + nums[i] = dp[i - 1] + nums[i]
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        result = max(result, dp[i]);
      }

      return result;
    }
};
