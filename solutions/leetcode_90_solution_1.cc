/* 90 子集2
给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的子集（幂集）。
解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。

示例 1：

输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
输入：nums = [0]
输出：[[],[0]]
*/

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    // 未访问过nums[i]，标记为-1
    // 使用过nums[i]，标记为1
    // 使用过，但经过回溯又取消了这个选择，标记为0
    vector<int> used(nums.size(), -1);
    vector<int> track;
    backtrack(track, nums, used, 0);
    return result;
  }
  
  void backtrack(vector<int>& track, vector<int>& nums, 
                 vector<int>& used, int start) {
    result.push_back(track);
    for (int i = start; i < nums.size(); i++) {
      // 去除重复
      if (used[i] == 1 || i > 0 && nums[i - 1] == nums[i] && used[i-1] == 0) {
        continue;
      }
      track.push_back(nums[i]);
      used[i] = 1;
      backtrack(track, nums, used, i + 1);
      track.pop_back();
      used[i] = 0;
    }
  }

  vector<vector<int>> result;
};