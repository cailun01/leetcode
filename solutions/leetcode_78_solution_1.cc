#include "headers.h"

class Solution {
public:
    vector<vector<int>> res;
    
    void backtrack(vector<int>& track, int start, vector<int>& nums) {
        res.push_back(track);

        for (int i = start; i < nums.size(); ++i) {
            track.push_back(nums[i]);
            backtrack(track, i + 1, nums);
            track.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> track;
        backtrack(track, 0, nums);
        return res;
    }
};