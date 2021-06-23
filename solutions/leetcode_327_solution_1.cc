/* 327. 区间和的个数
给你一个整数数组 nums 以及两个整数 lower 和 upper 。求数组中，值位于范围 [lower, upper] （包含 lower 和 upper）之内的 区间和的个数 。
区间和 S(i, j) 表示在 nums 中，位置从 i 到 j 的元素之和，包含 i 和 j (i ≤ j)。

示例 1：
输入：nums = [-2,5,-1], lower = -2, upper = 2
输出：3
解释：存在三个区间：[0,0]、[2,2] 和 [0,2] ，对应的区间和分别是：-2 、-1 、2 。

示例 2：
输入：nums = [0], lower = 0, upper = 0
输出：1
*/

class Solution {
public:
  int countRangeSumRecursive(vector<long>& sum, int lower, int upper, int left, int right) {
    if (left == right) {
      return 0;
    } else {
      int mid = (left + right) / 2;
      int n1 = countRangeSumRecursive(sum, lower, upper, left, mid);
      int n2 = countRangeSumRecursive(sum, lower, upper, mid + 1, right);
      int ret = n1 + n2;

      // 首先统计下标对的数量
      int i = left;
      int l = mid + 1;
      int r = mid + 1;
      while (i <= mid) {
        while (l <= right && sum[l] - sum[i] < lower) { 
          l++; 
        }
        while (r <= right && sum[r] - sum[i] <= upper) { 
          r++; 
        }
        ret += (r - l);
        i++;
      }

      // 随后合并两个排序数组
      vector<long> sorted(right - left + 1);
      int p1 = left, p2 = mid + 1;
      int p = 0;
      while (p1 <= mid || p2 <= right) {
        if (p1 > mid) {
          sorted[p++] = sum[p2++];
        } else if (p2 > right) {
          sorted[p++] = sum[p1++];
        } else {
          if (sum[p1] < sum[p2]) {
            sorted[p++] = sum[p1++];
          } else {
            sorted[p++] = sum[p2++];
          }
        }
      }
      for (int i = 0; i < sorted.size(); i++) {
        sum[left + i] = sorted[i];
      }
      return ret;
    }
  }

  int countRangeSum(vector<int>& nums, int lower, int upper) {
    long s = 0;
    vector<long> sum{0};
    for (auto& v: nums) {
      s += v;
      sum.push_back(s);
    }
    return countRangeSumRecursive(sum, lower, upper, 0, sum.size() - 1);
  }
};
