#include "headers/headers.h"
#include <gtest/gtest.h>
/*
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

// 暴力解法，两个循环，时间复杂度为O(n^2)，空间复杂度为O(1)

class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int num_elems = nums.size();
    vector<int> re_vec;
    for (int i = 0; i < num_elems - 1; ++i) {
      for (int j = i + 1; j < num_elems; ++j) {
        int sum = nums[i] + nums[j];
        if (sum == target) {
          re_vec.push_back(i);
          re_vec.push_back(j);
        }
      }
    }
    return re_vec;
  }
};

TEST(solution, test) {
  Solution s;
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> result = s.twoSum(nums, target);
  ASSERT_EQ(result[0], 0);
}

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);
  int ret = RUN_ALL_TESTS();
  return ret;
}
