/* 42 接雨水
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：
输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 

示例 2：

输入：height = [4,2,0,3,2,5]
输出：9

位置i能达到的水柱高度和其左边的最高柱子、右边的最高柱子有关，我们分别称这两个柱子高度为l_max和r_max；
位置 i 最大的水柱高度就是min(l_max, r_max)。

更进一步，对于位置i，能够装的水为：

water[i] = min(# 左边最高的柱子
               max(height[0..i]),  
               # 右边最高的柱子
               max(height[i..end]) 
            ) - height[i]

把r_max和l_max记录在备忘录里，只算一次。我们开两个数组r_max和l_max充当备忘录，
l_max[i]表示位置i左边最高的柱子高度，r_max[i]表示位置i右边最高的柱子高度。预先把这两个数组计算好，避免重复计算。
*/

class Solution {
public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int res = 0;
    // 数组充当备忘录
    // l_max[i]表示位置i左边最高的柱子高度，r_max[i]表示位置i右边最高的柱子高度
    vector<int> l_max(n), r_max(n);
    // 初始化 base case
    l_max[0] = height[0];
    r_max[n - 1] = height[n - 1];
    // 从左向右计算 l_max
    for (int i = 1; i < n; i++) {
      l_max[i] = max(height[i], l_max[i - 1]);
    }
    // 从右向左计算 r_max
    for (int i = n - 2; i >= 0; i--) {
      r_max[i] = max(height[i], r_max[i + 1]);
    }
    // 计算答案
    for (int i = 1; i < n - 1; i++) {
      res += min(l_max[i], r_max[i]) - height[i];
    }
    return res;
  }
};