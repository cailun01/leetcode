#include "headers.h"
//因为上帝视角，每天的股票价都能看到，所以为了最优，我可以任性反悔
//第一种反悔：手里握着昨天，发现今天更低价，不要买昨天的，买入今天的
//第二种反悔：刚卖了昨天，发现今天更高价，不要昨天卖，今天再卖出


class Solution {
public:
  int maxProfit(vector<int>& prices, int fee) {
    int length = prices.size();
    if (length <= 1) { 
      return 0; 
    }

    int profit0 = 0, profit1 = -prices[0] - fee;
    for (int i = 1; i < length; ++i) {
      int newProfit0 = max(profit0, profit1 + prices[i]);
      int newProfit1 = max(profit1, profit0 - prices[i] - fee);
      profit0 = newProfit0;
      profit1 = newProfit1;
    }
    return profit0;
  }
};
