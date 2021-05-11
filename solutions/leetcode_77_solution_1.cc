/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例:

输入: n = 4, k = 2
输出:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> track;
        backtrack(track, n, k, 1);
        return result;
    }

    void backtrack(vector<int>& track, int n, int k, int start) {
        if (track.size() == k) {
            result.push_back(track);
            return;
        }

        for (int i = start; i <= n; ++i) {
            track.push_back(i);
            backtrack(track, n, k, i + 1);
            track.pop_back();
        }
        return;
    }

    vector<vector<int>> result;
};