#include "headers.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        if (prices.size() <= 1) return 0;
        int num_prices = prices.size();
        //  前i天的最大收益 = max{前i-1天的最大收益，第i天的价格-前i-1天中的最小价格}
        int max_profit = 0;
        int min_price = prices[0];
        for (int i = 1; i < num_prices; ++i) {
            max_profit = max(max_profit, prices[i] - min_price);
            if (prices[i] < min_price) {
                min_price = prices[i];
            }
        }
        return max_profit;
    }
};