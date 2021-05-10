class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size());
        vector<int> track;
        backtrack(track, nums, used, 0);
        return result;
    }
    
    void backtrack(vector<int>& track, vector<int>& nums, vector<bool> used, int start) {
        result.push_back(track);
        for (int i = start; i < nums.size(); i++) {
            if (used[i] || i > 0 && nums[i - 1] == nums[i] && !used[i-1]) {
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(track, nums, used, i + 1);
            track.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> result;
};