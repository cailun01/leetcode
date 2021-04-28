#include "headers.h"
// 这题应该和上一题的第一个解法没啥区别。但是出现了一个超内存的错误，
// 原来是传入的 k 值会非常大，dp 数组太大了。现在想想，交易次数 k 最多有多大呢？
// 一次交易由买入和卖出构成，至少需要两天。所以说有效的限制 k 应该不超过 n/2，如果超过，就没有约束作用了，
// 相当于 k = +infinity。这种情况是之前解决过的。直接把之前的代码重用
class Solution {
public:
    int maxProfit_k_inf(vector<int>& prices) {
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
    int maxProfit(int k, vector<int>& prices) {
        int num_prices = prices.size();
        if (num_prices <= 1) return 0;
        if (k > num_prices / 2) {
            return maxProfit_k_inf(prices);
        }
        vector<vector<vector<int>>> dp(num_prices, vector<vector<int>>(k + 1, vector<int>(2, 0)));
        
        for (int i = 0; i < num_prices; i++) {
            for (int j = k; j >= 1; j--) {
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