/* 493 翻转对
在归并排序的过程中，假设对于数组 nums[l..r] 而言，我们已经分别求出了子数组nums[l..m]与nums[m+1..r]的翻转对数目，
并已将两个子数组分别排好序，则 nums[l..r] 中的翻转对数目，
就等于两个子数组的翻转对数目之和，加上左右端点分别位于两个子数组的翻转对数目。

我们可以为两个数组分别维护指针 i,j。对于任意给定的 i 而言，
我们不断地向右移动 j，直到 nums[i] <= 2 * nums[j]。此时，意味着以i为左端点的翻转对数量为j−m−1。
随后，我们再将i向右移动一个单位，并用相同的方式计算以i为左端点的翻转对数量。
不断重复这样的过程，就能够求出所有左右端点分别位于两个子数组的翻转对数目。

作者：LeetCode-Solution
链接：https://leetcode-cn.com/problems/reverse-pairs/solution/fan-zhuan-dui-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution {
public:
  int reversePairsRecursive(vector<int>& nums, int left, int right) {
    if (left == right) {
      return 0;
    } else {
      int mid = (left + right) / 2;
      int n1 = reversePairsRecursive(nums, left, mid);
      int n2 = reversePairsRecursive(nums, mid + 1, right);
      int ret = n1 + n2;

      // 首先统计下标对的数量
      int i = left;
      int j = mid + 1;
      while (i <= mid) {
        while (j <= right && nums[i] > 2 * nums[j]) { 
          j++; 
        }
        ret += (j - mid - 1);
        i++;
      }

      // 随后合并两个排序数组
      vector<int> sorted(right - left + 1);
      int p1 = left, p2 = mid + 1;
      int p = 0;
      while (p1 <= mid || p2 <= right) {
        if (p1 > mid) {
          // 已经遍历完p1
          sorted[p++] = nums[p2++];
        } else if (p2 > right) {
          // 已经遍历完p2
          sorted[p++] = nums[p1++];
        } else {
          if (nums[p1] < nums[p2]) {
            sorted[p++] = nums[p1++];
          } else {
            sorted[p++] = nums[p2++];
          }
        }
      }
      for (int i = 0; i < sorted.size(); i++) {
        nums[left + i] = sorted[i];
      }
      return ret;
    }
  }

  int reversePairs(vector<int>& nums) {
    if (nums.size() == 0)  { 
      return 0; 
    }
    return reversePairsRecursive(nums, 0, nums.size() - 1);
  }
};