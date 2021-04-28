#include "headers.h"
// 股价有升有落，需要找出所有的升区间，计算每个升区间的价格差（峰值减去谷值）作为收益，最后把所有升区间带来的收益求和就可以了。
// 对于升区间 [a, b, c, d]，有 a <= b <= c <= d ，那么最大收益为 d - a。而 d - a = (d - c) + (c - b) + (b - a) ，
// 因此每当访问到 prices[i] 比前一天价格高，即 prices[i] - prices[i-1] > 0，那么就把 prices[i] - prices[i-1] 添加到收益中。


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