#include "headers.h"
// 选择排序

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < size; ++j) {
                if (nums.at(j) < nums.at(min_idx)) {
                    min_idx = j;
                }
            }
            swap(nums[min_idx], nums[i]);
        }
        return nums;
    }
};