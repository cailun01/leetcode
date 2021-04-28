#include "headers.h"

class Solution {
public:
    int upper_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] > target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int lower_bound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid;
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.empty()) return {-1, -1};
        int start = lower_bound(nums, target);
        if (nums[start] != target) {
            return {-1, -1};
        } else {
            int end = upper_bound(nums, target);
            if (nums[end] == target) {
                return {start, end};
            } else {
                return {start, end - 1};
            }
        }
    }
};