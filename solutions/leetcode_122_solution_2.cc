#include "headers.h"
/*
1. 本题在交易股票的过程中，一共会有2种状态：
	○ dp0：手里没股票
	○ dp1：手里有股票
2. 初始化2种状态：
	○ dp0 = 0
	○ dp1 = - prices[0]
3. 对2种状态进行状态转移：
	○ dp0 = max(dp0, dp1 + prices[i])，前一天也是dp0状态，或者前一天是dp1状态，今天卖出一笔变成dp0状态，
	○ dp1 = max(dp1, dp0 - prices[i])，前一天也是dp1状态，或者前一天是dp0状态，今天买入一笔变成dp1状态
4. 最后一定是手里没有股票赚的钱最多，因此返回的是dp0
*/
class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int dp0 = 0;            // 手里没股票
    int dp1 = - prices[0];  // 手里有股票
    for(int i = 1; i < prices.size(); i++){
      new_dp0 = max(dp0, dp1 + prices[i]);
      new_dp1 = max(dp1, dp0 - prices[i]);
      dp0 = new_dp0;
      dp1 = new_dp1;
    }
    return dp0;
  }
};