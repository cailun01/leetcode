/* 268. 丢失的数字
给定一个包含 [0, n] 中 n 个数的数组 nums ，找出 [0, n] 这个范围内没有出现在数组中的那个数。

进阶：
你能否实现线性时间复杂度、仅使用额外常数空间的算法解决此问题?
*/ 

class Solution {
public:
  int missingNumber(vector<int>& nums) {
    // 索引0 , 1, 2 , ... n - 1
    // 数字[0, n]
    int n = nums.size();
    int res = n;
    for (int i = 0; i < n; ++i) {
      res ^= i;
      res ^= nums[i];
    }
    return res;
  }
};