class Solution {
public:
  int row, col;
  int idx = 2;
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};
  //记录每个岛屿的面积，a中的index与岛屿标记的g[i][j]的值idx对应相等
  int a[20000];

  int dfs(int x, int y, vector<vector<int>>& grid){
    if(!inArea(x, y) || grid[x][y] != 1) {
      return 0;
    }  
    grid[x][y] = idx;
    return dfs(x+1, y, grid) 
          + dfs(x-1, y, grid)
          + dfs(x, y-1, grid)
          + dfs(x, y+1, grid) + 1;        
  }

  bool inArea(int x, int y){
    return x >= 0 && y >= 0 && x < row && y < col;
  }


  int largestIsland(vector<vector<int>>& grid) {
    row = grid.size();
    if(row <= 0) return 0;
    col = grid[0].size();
    int res = 0;
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        if(grid[i][j] == 1){
          a[idx] = dfs(i, j, grid);
          res = max(res, a[idx]);
          idx++;
        }
      }
    }
    
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        if(grid[i][j] == 0){
          int count = 1;
          unordered_map<int, int> q;
          for(int idx = 0; idx < 4; idx++){
            int x = i + dx[idx];
            int y = j + dy[idx];
            if(inArea(x, y) && grid[x][y] >= 2 && q.find(grid[x][y]) == q.end()){
              count += a[grid[x][y]];
              q[grid[x][y]] = 0;
            } 
          }
          res = max(res, count);   
        }
      }
    }
    return res;
  }
};