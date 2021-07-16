/* 986. 区间列表的交集
给定两个由一些 闭区间 组成的列表，firstList 和 secondList ，其中 firstList[i] = [starti, endi] 而 secondList[j] = [startj, endj] 。每个区间列表都是成对 不相交 的，并且 已经排序 。

返回这 两个区间列表的交集 。

形式上，闭区间 [a, b]（其中 a <= b）表示实数 x 的集合，而 a <= x <= b 。

两个闭区间的 交集 是一组实数，要么为空集，要么为闭区间。例如，[1, 3] 和 [2, 4] 的交集为 [2, 3] 。
*/

class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, 
                                            vector<vector<int>>& secondList) {
    int i = 0, j = 0;
    vector<vector<int>> res;

    while (i < firstList.size() && j < secondList.size()) {
      // [a1, a2]代表firstList每个区间的左右端点
      int a1 = firstList[i][0], a2 = firstList[i][1];
      // [b1, b2]代表secondList每个区间的左右端点
      int b1 = secondList[j][0], b2 = secondList[j][1];
      // 两个区间存在交集
      if (b2 >= a1 && a2 >= b1) {
        // 计算出交集，加入res
        res.push_back({max(a1, b1), min(a2, b2)});
      }
      if (b2 < a2) {
        j += 1;
      } else {
        i += 1;
      }
    }
    return res;
  }
};