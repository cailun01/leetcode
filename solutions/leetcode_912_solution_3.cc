#include "headers.h"
/* 冒泡排序

比较相邻的元素。如果第一个比第二个大，就交换他们两个。
对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。在这一点，最后的元素应该会是最大的数。
针对所有的元素重复以上的步骤，除了最后一个。
持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。

*/
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        int size = nums.size();
        for (int i = 1; i < size; ++i) {
            // 冒泡排序第一次迭代，将最大的数放在最后。
            // 第二次迭代，将第二大的数放到倒数第二位。
            // i从1开始增大，size-i从size-1开始减小
            for (int j = 0; j < size - i; ++j) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                }
            }
        }
        return nums;
    }
};