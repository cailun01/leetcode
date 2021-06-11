#include "headers.h"
/* 16. 最接近的三数之和
给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，
使得它们的和与 target 最接近。返回这三个数的和。假定每组输入只存在唯一答案。


示例：
输入：nums = [-1,2,1,-4], target = 1
输出：2
解释：与 target 最接近的和是 2 (-1 + 2 + 1 = 2) 。
*/

class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    // 双指针遍历每一种可能，求其与target的绝对值
    sort(nums.begin(),nums.end());
    int return_sum = nums.at(0) + nums.at(1) + nums.at(nums.size() - 1);
    for (int i = 0; i < nums.size() - 2; ++i) {
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        int sum = nums.at(i) + nums.at(j) + nums.at(k);
        if (abs(sum - target) < abs(return_sum - target)) {
          // 更新最接近target的值
          return_sum = sum;
        }
        if (sum > target) {
          k--;
        } else if (sum < target) {
          j++;
        } else { // sum == target
          return sum;
        }
      }
    }
    return return_sum;
  }
};
