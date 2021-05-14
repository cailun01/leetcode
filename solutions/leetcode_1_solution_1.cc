#include "headers/headers.h"
#include <gtest/gtest.h>
/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那两个整数，并返回他们的数组下标。
Given an array of integers, return indices of the two numbers such that they add up to a specific target.

你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
You may assume that each input would have exactly one solution, and you may not use the same element twice.

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
*/

// 暴力解放，两个循环，时间复杂度为O(n^2)，空间复杂度为O(1)

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
