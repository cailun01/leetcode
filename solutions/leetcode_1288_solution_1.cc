/*
给你一个区间列表，请你删除列表中被其他区间所覆盖的区间。

只有当 c <= a 且 b <= d 时，我们才认为区间 [a,b) 被区间 [c,d) 覆盖。

在完成所有删除操作后，请你返回列表中剩余区间的数目。

示例：
输入：intervals = [[1,4],[3,6],[2,8]]
输出：2
解释：区间 [3,6] 被区间 [2,8] 覆盖，所以它被删除了。
*/

class Solution {
public:
  int removeCoveredIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() == 1) {
      return 1;
    }
    auto Comp = [](const vector<int>& a, const vector<int>& b) {
      if (a[0] == b[0]) {
        return a[1] > b[1];
      }
      return a[0] < b[0];
    };
    sort(intervals.begin(), intervals.end(), Comp);
    // 记录合并区间的起点和终点
    int left = intervals[0][0];
    int right = intervals[0][1];
    int res = 0;
    for (int i = 1; i < intervals.size(); ++i) {
      auto intv = intervals[i];
      // 情况1，找到覆盖区间
      if (left <= intv[0] && right >= intv[1]) {
        ++res;
      }
      // 情况2，找到相交区间，合并
      if (right >= intv[0] && right <= intv[1]) {
        right = intv[1];
      }
      // 情况3，完全不相交，更新起点和终点
      if (right < intv[0]) {
        left = intv[0];
        right = intv[1];
      }
    }
    return intervals.size() - res;
  }
};