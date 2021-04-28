#include "headers.h"

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        // 双指针遍历每一种可能，求其与target的绝对值
        sort(nums.begin(),nums.end());
        int return_sum = nums.at(0) + nums.at(1) + nums.at(nums.size() - 1);
        for (int i = 0; i < nums.size() - 2; ++i) {
            int j = i + 1;
            int k = nums.size() - 1;
            while (j < k) {
                int sum = nums.at(i) + nums.at(j) + nums.at(k);
                if (abs(sum - target) < abs(return_sum - target)) {
                    return_sum = sum;
                }
                if (sum > target) {
                    k -= 1;
                } else if (sum < target) {
                    j += 1;
                } else { // sum == target
                    return sum;
                }
            }
        }
        return return_sum;
    }
};