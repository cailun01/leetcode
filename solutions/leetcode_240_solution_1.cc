/* 240. 搜索二维矩阵 II
编写一个高效的算法来搜索 m x n 矩阵 matrix 中的一个目标值 target 。该矩阵具有以下特性：

每行的元素从左到右升序排列。
每列的元素从上到下升序排列。

示例 1：
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
输出：true

示例 2：
输入：matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
输出：false
*/

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size()==0) {
      return false;
    }
    // 从右上角开始查找
    int row = 0;//行
    int col = matrix[0].size() - 1;
    while (row <= matrix.size() - 1 && col >= 0){
      if (target > matrix[row][col]) {
        // target > 右上角的元素，则右上角所在行的所有元素都不用考虑了。
        row++;
      } else if(target < matrix[row][col]) {
        // target < 右上角的元素，则右上角所在列的所有元素都不用考虑了。
        col--;
      } else {
        return true;
      }
    }
    return false;   
  }
};
