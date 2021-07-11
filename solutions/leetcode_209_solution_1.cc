/* 209. 长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其和 ≥ target 的长度最小的 连续子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，
并返回其长度。如果不存在符合条件的子数组，返回 0 。

示例 1：
输入：target = 7, nums = [2,3,1,2,4,3]
输出：2
解释：子数组 [4,3] 是该条件下的长度最小的子数组。

示例 2：
输入：target = 4, nums = [1,4,4]
输出：1

示例 3：
输入：target = 11, nums = [1,1,1,1,1,1,1,1]
输出：0
*/

class Solution {
public:
  int minSubArrayLen(int target, vector<int>& nums) {
    int sum = 0;
    int left = 0, right = 0;
    int n = nums.size();
    int length = n;
    bool meet_target = false;
    while (right < n) {
      int curr = nums[right];
      sum += curr;
      right++;
      while (sum >= target) {
        meet_target = true;
        length = min(length, right - left);
        int val = nums[left];
        sum -= val;
        left++;
      }
    }
    return meet_target ? length : 0;
  }
};
