#include "headers.h"
// 单调栈
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        vector<int> st;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        for (int i = 0; i < heights.size(); i++) {
            while (!st.empty() && heights[st.back()] > heights[i]) {
                int cur = st.back();
                st.pop_back();
                int left = st.back() + 1;
                int right = i - 1;
                ans = max(ans, (right - left + 1) * heights[cur]);
            }
            st.push_back(i);
        }
        return ans;
    }
};

// int left = st.back() + 1;
// int right = i - 1;

// 比如我图中，当栈里是 1 5 6 这三个数时，此时 索引 i 代表的数是 2 ，触发计算。
// 此时第一次计算是因为 栈顶 6 比 2 大。所以出栈 6 ，6 为矩形的 h ，意思就是计算高度为 6 的矩形面积。
// 所以 left 就是出栈之后 5 的右边开始算起，5 不能包含在内。
// right 就是 i - 1 ，就是 2 的左边。
// 宽度计算完就是 1 格，高度 6 。

// 接下来，会对比栈顶 5 ，与 2 比较也会出栈。
// 此时要计算是高度为 5 的矩形。
// left 是 1 的右边。
// right 还是 i - 1，2 的左边。 宽度 2 ， 高度 5 