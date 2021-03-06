/* 121 买卖股票的最佳时机
给定一个数组prices，它的第i个元素prices[i]表示一支给定股票第i天的价格。
你只能选择某一天买入这只股票，并选择在未来的某一个不同的日子卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

示例 1：

输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

示例 2：
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

/*
1. 到最后交易结束时，一共会有3种状态：
  * dp0：一直不买
  * dp1：只买了一次
  * dp2：买了一次，卖了一次
2. 初始化3种状态：
  * dp0 = 0
  * dp1 = -prices[0]
  * dp2 = float("-inf")，因为第一天不可能会有dp2状态，因此将dp2置为负无穷(Java中置为int的下边界)
3. 对3种状态进行状态转移：
  * dp0 = 0，一直为0
  * dp1 = max(dp1, dp0 - prices[i])，前一天也是dp1状态，或者前一天是dp0状态，今天买入一笔变成dp1状态
  * dp2 = max(dp2, dp1 + prices[i])，前一天也是dp2状态，或者前一天是dp1状态，今天卖出一笔变成dp2状态
4. 最后一定是手里没有股票赚的钱最多，因此返回的是dp0，dp2的最大值
*/

class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.empty()) {
      return 0;
    }
    
    int length = prices.size();
    // dp[i][0] 表示在第 i 天结束时，持有0份股票的情况下可以获得的最大收益；
    // dp[i][1] 表示在第 i 天结束时，持有1份股票的情况下可以获得的最大收益；
    vector<vector<int>> dp(length, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = -prices[0];

    for (int i = 1; i < length; ++i) {
      dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
      // 原本是max(dp[i - 1][1], dp[i - 1][0] - prices[i]); ，但是dp[i - 1][0]一定为0
      dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[length - 1][0];
  }
};