#include "headers.h"
/*
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
此外，你可以假设该网格的四条边均被水包围。

示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3
*/

// dfs
class Solution {
private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    // 如果坐标 (r, c) 超出了网格范围，直接返回
    if (r >= grid.size() || c >= grid[0].size() || r < 0 || c < 0) {
      return;
    }
    if (grid[r][c] != '1') {
      return;
    }
    // 将访问过的陆地记为'2'，表示已经访问过，避免重复遍历。
    grid[r][c] = '2';

    // 访问上、下、左、右四个相邻结点
    dfs(grid, r - 1, c);
    dfs(grid, r + 1, c);
    dfs(grid, r, c - 1);
    dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    int num_rows = grid.size(); // 获取行数
    if (num_rows == 0) {
      return 0;
    } 
    int num_cols = grid[0].size(); // 获取列数

    int num_islands = 0;
    for (int r = 0; r < num_rows; ++r) {
      for (int c = 0; c < num_cols; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }
    return num_islands;
  }
};
