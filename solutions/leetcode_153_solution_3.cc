#include "headers.h"
// 分治，递归
// 在有序数组中，可以直接找到最小值，例如[1,2,3,4,5]，可以直接知道min=1即最左侧的元素。
// 那么同理对于旋转有序数组来说，也可以将其分为两份，如[3,4,5,1,2]，可以取最小值 = min(min([3,4,5]), min([1,2])) = 1。
// 这个思路的关键在于如何将数组划分为有序数组。

// 从情况a可以看到，最小值可能出现在无序区间中。最直观暴力的方法是，把数组中所有有序区间的最小值都拉出来比较，
// 那肯定也可以得出整体最小值, 问题也就变成了找到数组中的所有有序区间。

// 在二分的情况下，可能会出现一个无序区间，如果出现无序区间，可以继续进行二分，直到分成有序区间，这也就符合递归的定义。


class Solution {
public:
  int recurse_search_min(vector<int>& nums, int left, int right) {
    if (nums.at(left) <= nums.at(right)) {
      return nums.at(left);
    } else {
      int mid = (left + right) / 2;
      return min(recurse_search_min(nums, left, mid),
                  recurse_search_min(nums, mid + 1, right));
    }
  }
  int findMin(vector<int>& nums) {
      return recurse_search_min(nums, 0, nums.size() - 1);
  }
};

// https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/solution/lan-ren-di-gui-yu-er-fen-sou-suo-by-user5707f/