#include "headers.h"
/* 
选择排序

对于一个序列A中的元素A[1] ~ A[n]，令i从1~n枚举，进行n趟操作，每趟从待排序的部分[i,n]中选择最小的元素，
令他与待排序部分的第一个元素A[i]交换，这样元素A[i]就会与当前有序区间[1, i - 1]形成新的有序区间[1, i]。
n趟操作后，A变为有序。
选择排序是不稳定的排序方法。

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
            // 经过上面的for循环，nums[min_idx]是nums[i...size-1]中的最小值
            swap(nums[min_idx], nums[i]);
        }
        return nums;
    }
};