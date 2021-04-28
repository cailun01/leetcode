#include "headers.h"
/*
你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，
影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组，计算你不触动警报装置的情况下，一夜之内能够偷窃到的最高金额。

示例 1：
输入：[1,2,3,1]
输出：4
解释：偷窃1号房屋(金额=1)，然后偷窃3号房屋(金额=3)。
     偷窃到的最高金额 = 1 + 3 = 4 。

示例 2：
输入：[2,7,9,3,1]
输出：12
解释：偷窃1号房屋(金额 = 2), 偷窃3号房屋(金额=9)，接着偷窃 5号房屋 (金额 = 1)。
     偷窃到的最高金额 = 2 + 9 + 1 = 12 。

*/

// 对solution1的改进，用了一个备忘录
// 自顶而下
class Solution {
public:
    int rob(vector<int>& nums) {
        // 初始化备忘录
        vector<int> memo(nums.size(), -1);
        // 强盗从第 0 间房子开始抢劫
        return dp(nums, 0, memo);
    }
    // 返回 dp[start..] 能抢到的最大值
    int dp(vector<int>& nums, int start, vector<int>& memo) {
        if (start >= nums.size()) return 0;
        // 避免重复计算
        if (memo[start] != -1) {
            return memo[start];
        }
        int res = max(dp(nums, start + 1, memo), 
                      nums[start] + dp(nums, start + 2, memo));
        memo[start] = res;
        return res;
    }
};