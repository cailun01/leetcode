#include "headers.h"
// 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。

// 示例:

// 输入:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// 输出: 6

class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) return 0;
    int max_area = 0;
    // dp[i][j]表示以(i, j)为结束的矩形的最大宽度
    vector<vector<int>> dp(matrix.size(), vector<int>(matrix[0].size()));

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix[0].size(); j++) {
        if (matrix[i][j] == '1') {
          if (j == 0) {
            dp[i][j] = 1;
          } else {
            dp[i][j] = dp[i][j - 1] + 1;
          }
          int width = dp[i][j];
          int height = 0;
          // 计算以该(i, j)为右下角的最大矩形
          for (int k = i; k >= 0; k--) {
            // 因为(i,j)是矩形的右下角，所以从第i行开始相识遍历
            width = min(width, dp[k][j]);
            height = i - k + 1;
            max_area = max(max_area, width * height);
          }
        }
      }
    }
    return max_area;
  }
};

// https://leetcode-cn.com/problems/maximal-rectangle/solution/zui-da-ju-xing-by-leetcode/