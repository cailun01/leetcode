class Solution {
public:
  int dfs(vector<vector<int>>& grid, int r, int c) {
    // 函数因为「坐标 (r, c) 超出网格范围」返回1，对应一条黄色的边
    if (!in_area(grid, r, c)) {
      return 1;
    }
    // 函数因为「当前格子是海洋格子」返回1，对应一条蓝色的边
    if (grid[r][c] == 0) {
      return 1;
    }
    // 函数因为「当前格子是已遍历的陆地格子」返回0，和周长没关系
    if (grid[r][c] != 1) {
        return 0;
    }
    // 避免重复
    grid[r][c] = 2;
    return dfs(grid, r - 1, c)
      + dfs(grid, r + 1, c)
      + dfs(grid, r, c - 1)
      + dfs(grid, r, c + 1);
  }

  int islandPerimeter(vector<vector<int>>& grid) {
    int row = grid.size();
    if(row == 0) {
      return 0;
    }
    int col = grid[0].size();
    for(int i = 0; i < row; i++) {
      for(int j = 0; j < col; j++) {
        if(grid[i][j] == 1) {
          return dfs(grid, i, j);
        }
      }
    }
    return 0;
  }

  // 判断是否越界
  bool in_area(vector<vector<int>>& grid, int r, int c) {
    return r >= 0 && r < grid.size() && 0 <= c && c < grid[0].size();
  }
};