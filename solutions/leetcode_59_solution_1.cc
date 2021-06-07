/* 59. 螺旋矩阵 II
给你一个正整数 n ，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的 n x n 正方形矩阵 matrix 。

示例 1：
输入：n = 3
输出：[[1,2,3],[8,9,4],[7,6,5]]

示例 2：
输入：n = 1
输出：[[1]]
*/

/*
生成一个 n×n 空矩阵 mat，随后模拟整个向内环绕的填入过程：
  * 定义当前左右上下边界 left,right,top,bottom，初始值 num = 1，迭代终止值 target = n * n；
  * 当 num <= target 时，始终按照 从左到右 从上到下 从右到左 从下到上 填入顺序循环，每次填入后：
    - 执行 num += 1：得到下一个需要填入的数字；
    - 更新边界：例如从左到右填完后，上边界 t += 1，相当于上边界向内缩 1。
  使用num <= target而不是l < r || t < b作为迭代条件，是为了解决当n为奇数时，矩阵中心数字无法在迭代过程中被填充的问题。
最终返回 mat 即可。


链接：https://leetcode-cn.com/problems/spiral-matrix-ii/solution/spiral-matrix-ii-mo-ni-fa-she-ding-bian-jie-qing-x/
*/

class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    int left = 0, right = n - 1, top = 0, bottom = n - 1;
    vector<vector<int>> mat(n, vector<int>(n));
    int num = 1, target = n * n;
    while (num <= target) {
      for (int i = left; i <= right; i++) {
        mat[top][i] = num++;
      }
      top++;
      for (int i = top; i <= bottom; i++) {
        mat[i][right] = num++;
      }
      right--;
      for (int i = right; i >= left; i--) {
        mat[bottom][i] = num++;
      }
      bottom--;
      for (int i = bottom; i >= top; i--) {
        mat[i][left] = num++;
      }
      left++;
    }
    return mat;
  }
};
