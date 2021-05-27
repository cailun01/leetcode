#include "headers.h"
/* 1 两数之和
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  
的那 两个 整数，并返回它们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。

你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。

示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]

示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]
*/

// 用Hash表，时间复杂度为O(n)，空间复杂度为O(n)
class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    // hash的key是数组中元素的值，value是该元素在数组的下标
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); ++i) {
      hash[nums[i]] = i;
    }
    vector<int> result;
    for (int j = 0; j < nums.size(); ++j) {
      int complement = target - nums[j];
      auto it = hash.find(complement);
      if (it != hash.end()) {
        // 如果找到了complement而且它的下标不是当前元素的下标j
        // 则complement和nums[j]是两个不同的数
        int idx = hash[complement];
        if (idx != j) {
          result.push_back(j);
          result.push_back(idx);
          return result;
        }   
      }
    }
    return result;
  }
};