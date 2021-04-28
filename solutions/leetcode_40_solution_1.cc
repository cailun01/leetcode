#include "headers.h"

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.empty()) return {};

        sort(candidates.begin(), candidates.end());
        vector<int> select;
        set<vector<int>> result_set;
        vector<vector<int>> result;
        dfs(candidates, target, 0, select, result);
        

        return result;
    }

    void dfs(vector<int>& candidates, int target, int index, 
             vector<int>& select,
             vector<vector<int>>& result) {
        int sum = accumulate(select.begin(), select.end(), 0);
        if (sum == target) {
            result.push_back(select);
            return;
        } else if (sum > target) {
            return;
        }
        
        for (int i = index; i < candidates.size(); ++i) {
            // 在一个for循环中，所有被遍历到的数都是属于一个层级的。
            // 我们要让一个层级中，某个数必须出现且只出现一次
            // 对于i > index 且 candidates[i] == candidates[i - 1]直接跳过
            if (i > index && candidates[i] == candidates[i - 1]) {
                continue;
            }
            select.push_back(candidates[i]);
            dfs(candidates, target, i + 1, select, result);
            select.pop_back();
        }
    }
};