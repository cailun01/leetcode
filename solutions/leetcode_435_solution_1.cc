/* 435 无重叠区间
题目：
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:
	1. 可以认为区间的终点总是大于它的起点。
	2. 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。
	
示例 1:
输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。

示例 2:
输入: [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。

示例 3:
输入: [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
*/
class Solution {
public:
  int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.size() == 0 || intervals.size() == 1) {
      return 0;
    }
    // intervals中都是vector<int>，形式为 [ [start0, end0], [start1, end1] ... ]
    // 让intervals中的vector<int>按照结尾end升序
    sort(intervals.begin(), intervals.end(), 
        [](vector<int> a, vector<int> b){
      return a[1] < b[1];
    });

    int count = 0;
    int x_end = intervals[0][1];
    for (int i = 1; i < intervals.size(); ++i) {
      const vector<int>& interval = intervals[i];
      int start = interval[0];
      if (start >= x_end) {
        // 当前interval与上一个interval不重叠
        // 更新x_end为当前interval的end
        x_end = interval[1];
      } else {
        // start < x_end，需要移除该区间
        ++count;
      }
    }
    return count;
  }
};
