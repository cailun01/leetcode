class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<bool> used(nums.size(), false);
        vector<int> track;
        backtrack(track, used, nums);
        return result;
    }

    void backtrack(vector<int>& track, vector<bool>& used, vector<int>& nums) {
        if (track.size() == nums.size()) {
            result.push_back(track);
            return;
        }
        for (int i = 0; i < nums.size(); ++i) {
            ///当前选择被用过了 或者 和同一层重复了
            if (used[i] || i > 0 && nums[i - 1] == nums[i] && !used[i-1]) {
                //剪枝,!used[i-1]保证确实是在同一层发生了重复的选择
                continue;
            }
            track.push_back(nums[i]);
            used[i] = true;
            backtrack(track, used, nums);
            track.pop_back();
            used[i] = false;
        }
    }
    vector<vector<int>> result;
};