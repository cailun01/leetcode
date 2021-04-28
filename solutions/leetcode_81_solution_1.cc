#include "headers.h"

class Solution {
public:
    bool recurse_search(vector<int>& nums, int target, int lo, int hi) {
        if (lo == hi) {
            if (nums.at(lo) == target) {
                return true;
            } else {
                return false;
            }
        } else {
            int mid = (lo + hi) / 2;
            bool left_result = recurse_search(nums, target, lo, mid);
            bool right_result = recurse_search(nums, target, mid + 1, hi);
            return left_result || right_result;
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        if (nums.empty()) {
            return false;
        }
        return recurse_search(nums, target, 0, nums.size() - 1);
    }
};