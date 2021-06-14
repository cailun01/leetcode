/* 494. 目标和
给你一个整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。

示例 1：

输入：nums = [1,1,1,1,1], target = 3
输出：5
解释：一共有 5 种方法让最终目标和为 3 。
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

示例 2：
输入：nums = [1], target = 1
输出：1
*/

class Solution {
public:
  int subsets(vector<int>& nums, int sum) {
    int n = nums.size();
    /* dp[i][j] = x表示，若只在前i个物品中选择，若当前背包的容量为j，则最多有x种方法可以恰好装满背包。
    翻译成我们探讨的子集问题就是，若只在nums的前i个元素中选择，若目标和为j，则最多有x种方法划分子集。
    */
    vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
    /* base case
    dp[0][..] = 0，因为没有物品的话，根本没办法装背包
    dp[..][0] = 1，因为如果背包的最大载重为 0，「什么都不装」就是唯一的一种装法
    */
    for (int i = 0; i < n + 1; ++i) {
      dp[i][0] = 1;
    }
    // i取[1, n]
    for (int i = 1; i < n + 1; ++i) {
      for (int j = 0; j < sum + 1; ++j) {
        if (j >= nums[i - 1]) {
          dp[i][j] = dp[i - 1][j] + dp[i - 1][j - nums[i - 1]];
        } else {
          // 背包没有容量放下nums[i - 1]
          dp[i][j] = dp[i - 1][j];
        }
      }
    }
    // dp[n][sum]，即使用所有n个物品，有几种方法可以装满容量为 sum 的背包。
    return dp[n][sum];
  }
  
  int findTargetSumWays(vector<int>& nums, int target) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    // 这两种情况，不可能存在合法的子集划分
    if (sum < target || (sum + target) % 2 == 1) {
        return 0;
    }
    return subsets(nums, (sum + target) / 2);
  }
};