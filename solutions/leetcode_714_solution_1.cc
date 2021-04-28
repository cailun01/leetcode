#include "headers.h"

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int num_prices = prices.size();
        if (num_prices <= 1) return 0;

        int dp_i_0 = 0;
        int dp_i_1 = -prices[0];
        for (int i = 1; i < num_prices; ++i) {
            int temp = dp_i_0;
            dp_i_0 = max(dp_i_0, dp_i_1 + prices[i] - fee);
            dp_i_1 = max(dp_i_1, temp - prices[i]);
        }
        return dp_i_0;
    }
};
