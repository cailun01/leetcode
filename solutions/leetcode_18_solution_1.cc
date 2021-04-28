#include "headers.h"

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        if (nums.size() < 4) return {};
        int num_elems = nums.size();
        sort(nums.begin(),nums.end());
        int a, b, c, d;
        vector<vector<int>> res;
        for (a = 0; a < num_elems - 3; ++a) {
            if (a > 0 && nums[a] == nums[a - 1]) {
                continue;
            }
            for (int b = a + 1; b < num_elems - 2; ++b) {
                if (b > a + 1 && nums[b] == nums[b - 1]) {
                    continue;
                }
                c = b + 1;
                d = num_elems - 1;
                while (c < d) {
                    int sum = nums[a] + nums[b] + nums[c] + nums[d];
                    if (sum == target) {
                        res.push_back({nums[a],nums[b],nums[c],nums[d]});
                        while (c < d && nums[c] == nums[c + 1]) {
                            ++c;
                        }
                        ++c;
                        while (c < d && nums[d] == nums[d - 1]) {
                            --d;
                        }
                        --d;
                    } else if (sum < target) {
                        ++c;
                    } else {
                        --d;
                    }
                }
                
            }
            
        }
        return res;
    }
};