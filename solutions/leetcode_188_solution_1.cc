#include "headers.h"
/*
给定一个整数数组 prices ，它的第 i 个元素 prices[i] 是一支给定的股票在第 i 天的价格。

设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

*/
class Solution {
public:
  int maxProfit_k_inf(vector<int>& prices) {
    int num_days = prices.size();
    if (num_days <= 1) { 
      return 0; 
    }
    int max_profit = 0;

    for (int i = 1; i < num_days; ++i) {
      if (prices[i] > prices[i - 1]) {
        max_profit += prices[i] - prices[i - 1];
      }
    }
    return max_profit;
  }

  int maxProfit(int k, vector<int>& prices) {
    int num_prices = prices.size();
    if (num_prices <= 1) { 
      return 0; 
    }
    if (k > num_prices / 2) {
      return maxProfit_k_inf(prices);
    }

    vector<vector<vector<int>>> dp(num_prices, vector<vector<int>>(k + 1, vector<int>(2, 0)));
    
    for (int i = 0; i < num_prices; i++) {
      for (int j = 1; j <= k; j++) {
        if (i == 0) {
          dp[i][j][0] = 0;
          dp[i][j][1] = -prices[i];
          continue;
        }
        dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
        dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
      }
    }
    return dp[num_prices - 1][k][0];
  }
};