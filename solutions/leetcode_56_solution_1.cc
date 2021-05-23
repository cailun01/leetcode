/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间。

示例 1：
输入：intervals = [[1,3],[2,6],[8,10],[15,18]]
输出：[[1,6],[8,10],[15,18]]
解释：区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2：

输入：intervals = [[1,4],[4,5]]
输出：[[1,5]]
解释：区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    auto Comp = [](const vector<int>& a, const vector<int>& b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }
      return a[0] < b[0];
    };
    sort(intervals.begin(), intervals.end(), Comp);
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); ++i) {
      vector<int>& curr = intervals[i];
      vector<int>& last = res.back();
      if (last[1] >= curr[0]) {
        last[1] = max(last[1], curr[1]);
      } else {
        res.push_back(curr);
      }
    }
    return res;
  }
};