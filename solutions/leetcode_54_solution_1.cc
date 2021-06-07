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
首先设定上下左右边界
其次向右移动到最右，此时第一行因为已经使用过了，可以将其从图中删去，体现在代码中就是重新定义上边界
判断若重新定义后，上下边界交错，表明螺旋矩阵遍历结束，跳出循环，返回答案
若上下边界不交错，则遍历还未结束，接着向下向左向上移动，操作过程与第一，二步同理
不断循环以上步骤，直到某两条边界交错，跳出循环，返回答案
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
      vector<int> res;
      int rows = matrix.size(), cols = matrix[0].size();
      int left = 0, right = cols - 1, top = 0, bottom = rows - 1;
      int target = rows * cols;
      if (target == 0) {
        return res;
      } 
      if (target == 1) {
        res.push_back(matrix[0][0]);
        return res;
      }
      int num = 0;
      while (true) {
        for (int i = left; i <= right; ++i) {
          res.push_back(matrix[top][i]);
          ++num;
        }
        if (num == target) {
          break;
        }
        top++;
        for (int i = top; i <= bottom; ++i) {
          res.push_back(matrix[i][right]);
          ++num;
        }
        if (num == target) {
          break;
        }
        right--;
        for (int i = right; i >= left; --i) {
          res.push_back(matrix[bottom][i]);
          ++num;
        }
        if (num == target) {
          break;
        }
        bottom--;
        for (int i = bottom; i >= top; --i) {
          res.push_back(matrix[i][left]);
          ++num;
        }
        if (num == target) {
          break;
        }
        left++;
      }
      return res;
    }
};