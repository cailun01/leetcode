#include "headers.h"

/*

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。
如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。


*/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount < 0) {
            return -1;
        } 
        if (amount == 0) {
            return 0;
        }
        // dp[i], 金额为i时，凑乘金额的最小硬币数。
        // 数组大小为 amount + 1，初始值也为 amount + 1
        // 因为组成amount的硬币数最多是amount, 所以初始化为amount+1
        // 相当于初始化为正无穷。
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); ++i) {
            for (auto coin : coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
        if (dp[amount] != amount + 1) {
            return dp[amount];
        } else { // 凑不出amount的情况
            return -1;
        }
    }
};
