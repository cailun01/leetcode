#include "headers.h"
// 插入排序

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            int j = i;
            int temp = nums[j];
            while (j > 0 && temp < nums[j - 1]) {
                nums[j] = nums[j - 1];
                --j;
            }
            nums[j] = temp;
        }
        return nums;
    }
};