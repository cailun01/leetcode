/* 54. 螺旋矩阵
给你一个 m 行 n 列的矩阵 matrix ，请按照 顺时针螺旋顺序 ，返回矩阵中的所有元素。


示例 1：
输入：matrix = [[1,2,3],[4,5,6],[7,8,9]]
输出：[1,2,3,6,9,8,7,4,5]

示例 2：
输入：matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
输出：[1,2,3,4,8,12,11,10,9,5,6,7]
*/

/*
1.首先设定上下左右边界
2.其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
3.判断收集的数需要已经达到了矩阵的总数，表明螺旋矩阵遍历结束，跳出循环，返回答案
4.收集的数需要还没达到了矩阵的总数，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
*/
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    vector<int> res;
    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
    int num_elems = rows * cols;
    if (num_elems == 0) {
      return res;
    } 
    if (num_elems == 1) {
      res.push_back(matrix[0][0]);
      return res;
    }
    int global_index = 0;
    while (true) {
      // 向右移动
      for (int i = left; i <= right; ++i) {
        res.push_back(matrix[top][i]);
        ++global_index;
      }
      if (global_index == num_elems) {
        break;
      }
      top++; // 重新设定上边界
      // 向下遍历
      for (int i = top; i <= bottom; ++i) {
        res.push_back(matrix[i][right]);
        ++global_index;
      }
      if (global_index == num_elems) {
        break;
      }
      right--; // 重新设定右边界
      for (int i = right; i >= left; --i) {
        res.push_back(matrix[bottom][i]);
        ++global_index;
      }
      if (global_index == num_elems) {
        break;
      }
      bottom--; // 重新设定下边界
      for (int i = bottom; i >= top; --i) {
        res.push_back(matrix[i][left]);
        ++global_index;
      }
      if (global_index == num_elems) {
        break;
      }
      left++; // 重新设定左边界
    }
    return res;
  }
};