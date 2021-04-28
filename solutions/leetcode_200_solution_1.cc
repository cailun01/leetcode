#include "headers.h"
// dfs
class Solution {
private:
  void dfs(vector<vector<char>>& grid, int r, int c) {
    int nr = grid.size(); // 获取行数
    int nc = grid[0].size(); // 获取列数

    grid[r][c] = '0'; // 将当前格子的值设为0，表示已经遍历过
    // 左侧
    if (r - 1 >= 0 && grid[r-1][c] == '1') dfs(grid, r - 1, c);
    // 右侧
    if (r + 1 < nr && grid[r+1][c] == '1') dfs(grid, r + 1, c);
    // 上侧
    if (c - 1 >= 0 && grid[r][c-1] == '1') dfs(grid, r, c - 1);
    // 下侧
    if (c + 1 < nc && grid[r][c+1] == '1') dfs(grid, r, c + 1);
  }

public:
  int numIslands(vector<vector<char>>& grid) {
    int nr = grid.size(); // 获取行数
    if (!nr) return 0;
    int nc = grid[0].size(); // 获取列数

    int num_islands = 0;
    for (int r = 0; r < nr; ++r) {
      for (int c = 0; c < nc; ++c) {
        if (grid[r][c] == '1') {
          ++num_islands;
          dfs(grid, r, c);
        }
      }
    }

    return num_islands;
  }
};
