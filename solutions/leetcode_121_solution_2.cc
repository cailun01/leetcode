#include "headers.h"
// 单调栈，和84、85有类似

// 这个题本质就是要求某个数与其右边最大的数的差值，这符合了单调栈的应用场景 
// 当你需要高效率查询某个位置左右两侧比他大（或小）的数的位置的时候，于是我就用单调栈解决了(但是发现题解很多都是 dp，哈哈)。
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        vector<int> St;
        prices.emplace_back(-1); // 哨兵
        for (int i = 0; i < prices.size(); ++ i){
            while (!St.empty() && St.back() > prices[i]){ // 维护单调栈
                ans = std::max(ans, St.back() - St.front()); // 维护最大值
                St.pop_back();
            }
            St.emplace_back(prices[i]);
        }

        return ans;
    }
};
// 题解：
// https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/solution/c-li-yong-shao-bing-wei-hu-yi-ge-dan-diao-zhan-tu-/