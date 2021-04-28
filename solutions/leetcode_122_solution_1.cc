#include "headers.h"
// 提交超时


// 每天都有三种动作：买入（buy）、卖出（sell）、无操作（rest）
// 因为不限制交易次数，因此交易次数这个因素不影响题目，不必考虑。
// DP Table 是二维的，两个维度分别是天数（0,1,...,n-1）和是否持有股票（1 表持有，0 表不持有）。

// Case 1，今天我没有股票，有两种可能：
//   昨天我手上就没有股票，今天不做任何操作（rest）；
//   昨天我手上有一只股票，今天按照时价卖掉了（sell），收获了一笔钱

// Case 2，今天持有一只股票，有两种可能：
//   昨天我手上就有这只股票，今天不做任何操作（rest）；
//   昨天我没有股票，今天按照时价买入一只（sell），花掉了一笔钱
// 综上，第 i 天的状态转移方程为：
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i])
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i])


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int num_days = prices.size();
        if (num_days <= 1) return 0;
        // dp表示手中有多少钱
        vector<vector<int>> dp(num_days, vector<int>(num_days, -1));
        dp[0][0] = 0; //  第一天没有股票，说明没买没卖，获利为0
        dp[0][1] = -prices[0];   // 第一天持有股票，说明买入了，花掉一笔钱
        for (int i = 1; i < num_days; ++i) {
          dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i]);
          dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i]);
        }
        return dp[num_days - 1][0];    // 返回最后一天且手上没有股票时的获利情况
    }
};

// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii/solution/gu-piao-jiao-yi-xi-lie-tan-xin-si-xiang-he-dong-2/