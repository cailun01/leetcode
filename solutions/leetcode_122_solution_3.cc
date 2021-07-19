/*122. 买卖股票的最佳时机 II
给定一个数组 prices ，其中 prices[i] 是一支给定股票第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入: prices = [7,1,5,3,6,4]
输出: 7
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

示例 2:
输入: prices = [1,2,3,4,5]
输出: 4
解释: 在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。因为这样属于同时参与了多笔交易，
     你必须在再次购买前出售掉之前的股票。

示例 3:
输入: prices = [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/

// 贪心算法
// 股价有升有落，需要找出所有的升区间，计算每个升区间的价格差（峰值减去谷值）作为收益，
// 最后把所有升区间带来的收益求和就可以了。
// 对于升区间 [a, b, c, d]，有 a <= b <= c <= d ，
// 那么最大收益为 d - a。而 d - a = (d - c) + (c - b) + (b - a) ，
// 因此每当访问到 prices[i] 比前一天价格高，即 prices[i] - prices[i-1] > 0，
// 那么就把 prices[i] - prices[i-1] 添加到收益中。


class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int num_days = prices.size();
    if (num_days <= 1) return 0;
    int max_profit = 0;

    for (int i = 1; i < num_days; ++i) {
      if (prices[i] > prices[i - 1]) {
        max_profit += prices[i] - prices[i - 1];
      }
    }
    return max_profit;
  }
};