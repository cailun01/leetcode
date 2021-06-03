/* 986. 区间列表的交集

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