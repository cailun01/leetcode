/* 74. 搜索二维矩阵
编写一个高效的算法来判断 m x n 矩阵中，是否存在一个目标值。该矩阵具有如下特性：
* 每行中的整数从左到右按升序排列。
* 每行的第一个整数大于前一行的最后一个整数。
输入：matrix = 
               [[1, 3, 5, 7 ],
                [10,11,16,20],
                [23,30,34,60]], target = 3
输出：true

*/

/*
一次二分查找
思路

若将矩阵每一行拼接在上一行的末尾，则会得到一个升序数组，我们可以在该数组上二分找到目标元素。

代码实现时，可以二分升序数组的下标，将其映射到原矩阵的行和列上。
原矩阵为m行n列，映射到一维数组，索引就是[0,m*n-1]。对于一维数组的索引i，
映射回原数组的公式：matrix[i / n][i % n]
*/
#include "headers.h"

class Solution {
public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    int low = 0, high = m * n - 1;
    while (low <= high) {
      int mid = (high - low) / 2 + low;
      // 映射关系
      int x = matrix[mid / n][mid % n];
      if (x < target) {
        low = mid + 1;
      } else if (x > target) {
        high = mid - 1;
      } else {
        return true;
      }
    }
    return false;
  }
};
