#include "headers.h"

// 每天都有三种动作：买入（buy）、卖出（sell）、无操作（rest）
// 因为不限制交易次数，因此交易次数这个因素不影响题目，不必考虑。
// DP Table 是二维的，两个维度分别是天数（0,1,...,n-1）和是否持有股票（1 表持有，0 表不持有）。

// Case 1，今天我没有股票，有两种可能：
//   昨天我手上就没有股票，今天不做任何操作（rest）；
//   昨天我手上有一只股票，今天按照时价卖掉了（sell），收获了一笔钱

// Case 2，今天持有一只股票，有两种可能：
//   昨天我手上就有这只股票，今天不做任何操作（rest）；
//   昨天我没有股票，今天按照时价买入一只（sell），花掉了一笔钱


// 这道题的在 LeetCode 122 的基础上添加了冷冻期的要求，即每次 sell 之后要等一天才能继续交易。
// 状态转移方程要做修改，如果第 i 天选择买入股票，状态要从第 i-2 的转移，而不是 i-1 (因为第 i-1 天是冷冻期)。
// 另外，由于状态转移方程中出现了 dp[i-2] 推导 dp[i-1]，因此状态边界除了考虑 i=0 天，还要加上 i=1 天的状态。
  // dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i])
  // dp[i][1] = max(dp[i-1][1], dp[i-2][0]-prices[i])    # 买入股票时注意冷冻期


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num_days = prices.size();
        if (num_days <= 1) return 0;
        // dp表示手中有多少钱
        vector<vector<int>> dp(num_days, vector<int>(num_days, -1));
        dp[0][0] = 0; //  第一天没有股票，说明没买没卖，获利为0
        dp[0][1] = -prices[0];   // 第一天持有股票，说明买入了，花掉一笔钱
        dp[1][0] = max(dp[0][0], dp[0][1]+prices[1]);  // 昨天就没有 或者 昨天买入今天卖出
        dp[1][1] = max(dp[0][1], -prices[1]);  // 昨天就有 或者 昨天没有而今天买入

        for (int i = 2; i < num_days; ++i) {
          dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
          dp[i][1] = max(dp[i-1][1], dp[i-2][0] - prices[i]);
        }
        return dp[num_days - 1][0];    // 返回最后一天且手上没有股票时的获利情况
    }
};
