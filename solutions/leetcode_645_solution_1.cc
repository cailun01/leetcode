/*
集合 s 包含从 1 到 n 的整数。不幸的是，因为数据错误，导致集合里面某一个数字复制了成了集合
里面的另外一个数字的值，导致集合 丢失了一个数字 并且 有一个数字重复 。

给定一个数组 nums 代表了集合 S 发生错误后的结果。

请你找出重复出现的整数，再找到丢失的整数，将它们以数组的形式返回。

示例 1：

输入：nums = [1,2,2,4]
输出：[2,3]
示例 2：

输入：nums = [1,1]
输出：[1,2]
*/

class Solution {
public:
  vector<int> findErrorNums(vector<int>& nums) {
    int n = nums.size();
    int duplicate = -1;
    for (int i = 0; i < n; ++i) {
      // abs(nums[i])的取值范围是[1...N]
      // 索引index应该从 0 开始
      int index = abs(nums[i]) - 1;
      if (nums[index] < 0) {
        // nums[index] < 0说明这个index对应的值已被访问过，
        // 是重复的
        duplicate = abs(nums[i]);
      } else {
        nums[index] *= -1;
      }
    }

    for (int i = 0; i < n; i++) {
      if (nums[i] > 0) {
        // nums[i] 大于 0 则说明没有访问
        // 如果nums[i]的取值范围是[0...N-1]，则missing=i
        // 但是nums[i]的取值范围是[1...N]，则missing=i+1
        int missing = i + 1;
      }
    }
    return {duplicate, missing};
  }
};
