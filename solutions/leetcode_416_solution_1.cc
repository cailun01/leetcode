/* 416 分割等和子集
题目：
给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
*/

class Solution {
public:
  bool canPartition(vector<int>& nums) {
    // dp[i][j] = x表示，对于前i个物品，当前背包的容量为j时，
    // 若x为true，则说明可以恰好将背包装满，若x为false，则说明不能恰好将背包装满。
    int sum = 0;
    int max_num = 0;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      max_num = max(nums[i], max_num);
    }
    // 和为奇数时，不可能划分成两个和相等的集合
    if (sum % 2 != 0) {
      return false;
    }
    int n = nums.size();
    sum = sum / 2;
    if (max_num > sum) {
      return false;
    }
    vector<vector<bool>> 
        dp(n + 1, vector<bool>(sum + 1, false));
    // 因为背包没有空间的时候，就相当于装满了
    for (int i = 0; i <= n; i++) {
      dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= sum; j++) {
        if (j - nums[i - 1] < 0) {
          // 背包容量不足，不能装入第 i 个物品
          dp[i][j] = dp[i - 1][j]; 
        } else {
          // 装入或不装入背包
          dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i-1]];
        }
      }
    }
    return dp[n][sum];
  }
};