/* 463 岛屿的周长
给定一个 row x col 的二维网格地图 grid ，其中：grid[i][j] = 1 表示陆地， grid[i][j] = 0 表示水域。

网格中的格子 水平和垂直 方向相连（对角线方向不相连）。整个网格被水完全包围，
但其中恰好有一个岛屿（或者说，一个或多个表示陆地的格子相连组成的岛屿）。

岛屿中没有“湖”（“湖” 指水域在岛屿内部且不和岛屿周围的水相连）。格子是边长为 1 的正方形。
网格为长方形，且宽度和高度均不超过 100 。计算这个岛屿的周长。

输入：grid = 
[[0,1,0,0],
 [1,1,1,0],
 [0,1,0,0],
 [1,1,0,0]]
输出：16
解释：它的周长是上面图片中的 16 个黄色的边
示例 2：

输入：grid = [[1]]
输出：4
示例 3：

输入：grid = [[1,0]]
输出：4
*/

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