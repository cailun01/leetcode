/* 42 接雨水
双指针边走边算。

之前的备忘录解法，l_max[i]和r_max[i]分别代表height[0..i]和height[i..n-1]的最高柱子高度。
res += min(l_max[i], r_max[i]) - height[i];

但是双指针解法中，l_max和r_max代表的是height[0..left]和height[right..n-1]的最高柱子高度。比如这段代码：

if (l_max < r_max) {
    res += l_max - height[left];
    left++; 
} 

此时的l_max是left指针左边的最高柱子，但是r_max并不一定是left指针右边最高的柱子，这真的可以得到正确答案吗？

其实这个问题要这么思考，我们只在乎min(l_max, r_max)。对于上图的情况，我们已经知道l_max < r_max了，
至于这个r_max是不是右边最大的，不重要。重要的是height[i]能够装的水只和较低的l_max之差有关。
*/

class Solution {
public:
  int trap(vector<int>& height) {
    if (height.empty()) return 0;
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;

    int l_max = height[0];
    int r_max = height[n - 1];

    while (left <= right) {
      l_max = max(l_max, height[left]);
      r_max = max(r_max, height[right]);

      // res += min(l_max, r_max) - height[i]
      if (l_max < r_max) {
        res += l_max - height[left];
        left++; 
      } else {
        res += r_max - height[right];
        right--;
      }
    }
    return res;
  }
};