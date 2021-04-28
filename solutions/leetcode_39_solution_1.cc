#include "headers.h"
// 这道题用常规的回溯算法求解。难点在于去重。
// 如果candidates = [2,3,6,7], target = 7,
// 所求正确解集为: [ [7], [2,2,3] ]
// 如果没有去重，会得到：[ [7], [2,2,3], [2,3,2], [3,2,2] ]

// 本解法用了比较笨的办法去重。
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};  
        vector<vector<int>> result;
        vector<int> option;
        set<vector<int>> result_set; // 用set存放解，可以保证不重复
        dfs(candidates, target, 0, option, result_set);
        // 将set中的vector放到result里
        for (auto begin = result_set.begin(); begin != result_set.end(); ++begin) {
            result.push_back(*begin);
        }
        return result;
    }

    void dfs(vector<int>& candidates, int target, int depth, 
             vector<int>& option, set<vector<int>>& result_set) {
        int sum = accumulate(option.begin(), option.end(), 0);
        if (sum == target) {
            // 这里对option进行拷贝，把copy排序并放入result_set
            // 如果没有拷贝，则排序后的option会影响下一次回溯，导致出现bug
            vector<int> copy = option;
            sort(copy.begin(), copy.end());  
            result_set.insert(copy);
            return;
        } else if (sum > target) {
            return;
        }

        for (auto &num : candidates) {
            option.push_back(num);
            dfs(candidates, target, depth + 1, option, result_set);
            option.pop_back();
        }
    }
};