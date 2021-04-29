#include "headers.h"
/* 
选择排序

第一次从待排序的数据元素中选出最小（或最大）的一个元素，存放在序列的起始位置，
然后再从剩余的未排序元素中寻找到最小（大）元素，然后放到已排序的序列的末尾。
以此类推，直到全部待排序的数据元素的个数为零。选择排序是不稳定的排序方法。

*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        for (int i = 0; i < size; ++i) {
            int min_idx = i;
            for (int j = i + 1; j < size; ++j) {
                if (nums[j] < nums[min_idx]) {
                    min_idx = j;
                }
            }
            swap(nums[min_idx], nums[i]);
        }
        return nums;
    }
};