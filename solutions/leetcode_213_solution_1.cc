#include "headers.h"
/*

你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。
这个地方所有的房屋都围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。

给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

示例 1：
输入：nums = [2,3,2]
输出：3
解释：你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）, 因为他们是相邻的。

示例 2：
输入：nums = [1,2,3,1]
输出：4
解释：你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 3：
输入：nums = [0]
输出：0

*/

/*
首先，首尾房间不能同时被抢，那么只可能有三种不同情况：
(1)要么都不被抢；
(2)要么第一间房子被抢最后一间不抢；
(3)要么最后一间房子被抢第一间不抢。

其实我们不需要比较三种情况，只要比较情况(2)和情况(3)就行了，
因为这两种情况对于房子的选择余地比情况一大呀，房子里的钱数都是非负数，
所以选择余地大，最优决策结果肯定不会小。
*/
class Solution {
public:
  int rob(vector<int>& nums) {
    if (nums.empty()) return 0;
    int size = nums.size();
    if (size == 1) return nums[0];
    return max(rob_range(nums, 0, size - 2),
               rob_range(nums, 1, size - 1));
  }

  int rob_range(vector<int>& nums, int start, int end) {
    int size = nums.size();

    vector<int> dp(size, 0);
    // 因为要处理两种情况，需要特殊处理start== 1
    for (int i = start; i <= end; i++) {
      if (i == 0) {
        dp[0] = nums[0];
      } else if (i == 1) {
        if (start == 1) {
          // 如果不偷索引为0的房子
          dp[1] = nums[1];
        } else {
          dp[1] = max(nums[1], nums[0]);
        }
      } else {
        dp[i] = max(dp[i - 1], nums[i] + dp[i - 2]);
      }
    }
    return dp[end];
  }
};
