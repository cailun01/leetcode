/*
给定一个包含了一些 0 和 1 的非空二维数组 grid 。

一个 岛屿 是由一些相邻的 1 (代表土地) 构成的组合，这里的「相邻」要求两个 1 必须在水平或者竖直方向上相邻。你可以假设 grid 的四个边缘都被 0（代表水）包围着。

找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为 0 。)

示例 1:
[[0,0,1,0,0,0,0,1,0,0,0,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,1,1,0,1,0,0,0,0,0,0,0,0],
 [0,1,0,0,1,1,0,0,1,0,1,0,0],
 [0,1,0,0,1,1,0,0,1,1,1,0,0],
 [0,0,0,0,0,0,0,0,0,0,1,0,0],
 [0,0,0,0,0,0,0,1,1,1,0,0,0],
 [0,0,0,0,0,0,0,1,1,0,0,0,0]]
对于上面这个给定矩阵应返回 6。注意答案不应该是 11 ，因为岛屿只能包含水平或垂直的四个方向的 1 。

示例 2:
[[0,0,0,0,0,0,0,0]]
对于上面这个给定的矩阵, 返回 0。

注意: 给定的矩阵grid 的长度和宽度都不超过 50。
*/

class Solution {
public:
  int area(vector<vector<int>>& grid, int r, int c) {
    // 如果坐标越界，或者
    // 如果是水(grid[r][c]==0)或者已经访问过的土地(grid[r][c]==2)
    if (!in_area(grid, r, c) || grid[r][c] != 1) {
      return 0;
    }
    // 避免重复
    grid[r][c] = 2;
    return 1 
      + area(grid, r - 1, c)
      + area(grid, r + 1, c)
      + area(grid, r, c - 1)
      + area(grid, r, c + 1);
  }

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.empty()) {
      return 0;
    }
    int max_area = 0;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c] == 1) {
          int temp = area(grid, r, c);
          max_area = max(temp, max_area);
        }
      }
    }
    return max_area;
  }
  // 判断是否越界
  bool in_area(vector<vector<int>>& grid, int r, int c) {
    return r >= 0 && r < grid.size() && 0 <= c && c < grid[0].size();
  }
};