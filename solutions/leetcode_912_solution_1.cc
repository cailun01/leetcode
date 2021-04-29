#include "headers.h"
// 归并排序的递归解法
class Solution {
public:
    vector<int> temp;
    // 将数组nums的[l1, r1]和[l2, r2]合并为有序区间(此处l2 = r1 + 1)
    void merge(vector<int>& nums, int l1, int r1, int l2, int r2) {
        int index = 0;
        int i = l1, j = l2;
        while (i <= r1 && j <= r2) {
            if (nums[i] <= nums[j]) {
                temp[index++] = nums[i++];
            } else {
                temp[index++] = nums[j++];
            }
        }
        while (i <= r1) {
            temp[index++] = nums[i++];
        }
        while (j <= r2) {
            temp[index++] = nums[j++];
        }
        for (int i = 0; i < index; ++i) {
            nums[l1 + i] = temp[i];
        }
        return;
    }
    void merge_sort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = (left + right) / 2;
            merge_sort(nums, left, mid);
            merge_sort(nums, mid + 1, right);
            merge(nums, left, mid, mid + 1, right);
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        temp.resize(nums.size(), 0);
        merge_sort(nums, 0, nums.size() - 1);
        return nums;
    }
};