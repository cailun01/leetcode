#include "headers.h"

class Solution {
public:
    int lower_bound(const vector<int>& nums, int target) {
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
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        for (auto iter = matrix.begin(); iter != matrix.end(); ++iter) {
            auto vec = *iter;
            int start = lower_bound(vec, target);
            if (vec[start] == target) {
                return true;
            }
        }
        return false;
    }
};