#include "headers.h"
//因为上帝视角，每天的股票价都能看到，所以为了最优，我可以任性反悔
//第一种反悔：手里握着昨天，发现今天更低价，不要买昨天的，买入今天的
//第二种反悔：刚卖了昨天，发现今天更高价，不要昨天卖，今天再卖出

class Solution {
  int maxProfit(vector<int>& prices, int fee) {
      if(prices.size()<2)
          return 0;
      int ans = 0;

      //第一天，买它，握在手里。
      int in_hand = prices[0];
      for(int i = 1;i < prices.size();i++)            
          //今天的比我手里的低价，第一种反悔
          if (prices[i] < in_hand)
              in_hand = prices[i];  
          //今天的减掉手续费后比我手里的高价，我要卖出！
          else if (prices[i] - fee > in_hand)
          {  
              //差额累加起来
              ans += (prices[i] - fee) - in_hand;
              //记录一下这天的卖出价，方便我决定1.买入明天的 或者 2.第二种反悔
              //明天比这个记录低就用上面那个if来进行买入明天的
              //明天比这个记录高，但减掉fee后比这个记录低，那么不能买入明天的，也不能第二种反悔。只能忽略，继续循环。
              //明天减掉fee后比这个记录高，通过这个记录来再累加差额一次达到第二种反悔的效果
              in_hand = prices[i]-fee;
          }                
      return ans;
  }
};
