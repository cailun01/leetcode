#include "headers.h"
// 冒泡排序
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            for (int j = 0; j < size - i; ++j) {
                if (nums.at(j) > nums.at(j + 1)) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums;
    }
};