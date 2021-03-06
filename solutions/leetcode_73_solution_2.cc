/* 73. 矩阵置零
给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。

进阶：

一个直观的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
你能想出一个仅使用常量空间的解决方案吗？
 

示例 1：
输入：matrix = [[1,1,1],[1,0,1],[1,1,1]]
输出：[[1,0,1],[0,0,0],[1,0,1]]

示例 2：
输入：matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
输出：[[0,0,0,0],[0,4,5,0],[0,3,1,0]]
*/

/* 方法二：使用两个标记变量
我们可以用矩阵的第一行和第一列代替方法一中的两个标记数组，以达到 O(1) 的额外空间。
但这样会导致原数组的第一行和第一列被修改，无法记录它们是否原本包含 0。
因此我们需要额外使用两个标记变量分别记录第一行和第一列是否原本包含 0。

在实际代码中，我们首先预处理出两个标记变量，接着使用其他行与列去处理第一行与第一列，
然后反过来使用第一行与第一列去更新其他行与列，最后使用两个标记变量更新第一行与第一列即可。
*/

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    // flag_col0 第一列原本包含0
    // flag_row0 第一行原本包含0
    bool flag_col0 = false, flag_row0 = false;
    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        flag_col0 = true;
      }
    }
    for (int j = 0; j < n; j++) {
      if (matrix[0][j] == 0) {
        flag_row0 = true;
      }
    }
    // 遍历除第一行和第一列的其他位置，如果发现0
    // 将信息存储到改行的最左方matrix[i][0]和最上方matrix[0][j]
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = matrix[0][j] = 0;
        }
      }
    }
    // 根据最左方和最上方格子内的置零信息，进行非首行首列置零
    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (!matrix[i][0] || !matrix[0][j]) {
          matrix[i][j] = 0;
        }
      }
    }
    // 置零首行和首列
    if (flag_col0) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
    if (flag_row0) {
      for (int j = 0; j < n; j++) {
        matrix[0][j] = 0;
      }
    }
  }
};