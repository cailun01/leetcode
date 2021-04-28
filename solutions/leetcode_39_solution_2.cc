#include "headers.h"


class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};  
        vector<vector<int>> result;
        vector<int> option;
        dfs(candidates, target, 0, option, result);
        return result;
    }

    void dfs(vector<int>& candidates, int target, int index, 
             vector<int>& option, 
             vector<vector<int>>& result) {
        int sum = accumulate(option.begin(), option.end(), 0);
        if (sum == target) {
            result.push_back(option);
            return;
        } else if (sum > target) {
            return;
        }
        // 去重的关键在于i，调用dfs时，形参index的实参为i，
        // 避免了重复使用candidates中已经遍历过的值。
        // 比如candidates = [2,3,6,7]，i == 1时，比如candidates[i] == 3
        // 此时调用dfs(candidates, 1, target, option, result)
        // 在新的dfs函数中，for循环的i从1开始，只会把3push_back进入option，
        // 不会把3以前的数字2push_back进入option
        for (int i = index; i < candidates.size(); ++i) {
            option.push_back(candidates[i]);
            dfs(candidates, target, i, option, result);
            option.pop_back();
        }
    }
};