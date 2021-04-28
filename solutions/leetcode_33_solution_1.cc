#include "headers.h"
// 二分查找
class Solution {
public:
    int recurse_search(vector<int>& nums, int target, int lo, int hi) {
        if (lo == hi) {
            if (nums.at(lo) == target) {
                return lo;
            } else {
                return -1;
            }
        } else {
            int mid = (lo + hi) / 2;
            int left_result = recurse_search(nums, target, lo, mid); 
            int right_result = recurse_search(nums, target, mid + 1, hi);
            if (left_result != -1) return left_result;
            if (right_result != -1) return right_result;
        }
        return -1;

    }
    int search(vector<int>& nums, int target) {
        if (nums.empty()) return -1;
        return recurse_search(nums, target, 0, nums.size() - 1);
    }
};