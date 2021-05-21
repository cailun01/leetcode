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