class Solution {
public:
  int row, col;
  // island_idx作为每个岛屿的记号。因为0是海洋，1是陆地。
  // 所以island_idx从2开始。每发现一个新岛屿，idx加1
  int island_idx = 2; 
  int dx[4] = {0, 1, 0, -1};
  int dy[4] = {1, 0, -1, 0};

  int area(int x, int y, vector<vector<int>>& grid){
    if(!inArea(x, y) || grid[x][y] != 1) {
      return 0;
    }
    // 新岛屿
    grid[x][y] = island_idx;
    return area(x+1, y, grid) 
          + area(x-1, y, grid)
          + area(x, y-1, grid)
          + area(x, y+1, grid) + 1;        
  }

  bool inArea(int x, int y){
    return x >= 0 && y >= 0 && x < row && y < col;
  }


  int largestIsland(vector<vector<int>>& grid) {
    row = grid.size();
    if(row <= 0) return 0;
    col = grid[0].size();
    int res = 0;
    unordered_map<int, int> island_area; // key: island_idx, value: area of island
    for(int i = 0; i < row; i++){
      for(int j = 0; j < col; j++){
        if(grid[i][j] == 1){
          island_area[island_idx] = area(i, j, grid);
          res = max(res, island_area[island_idx]);
          island_idx++;
        }
      }
    }
    if (res == 0) {
      //如果没有陆地，那么就造1块
      return 1;
    } 
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < col; j++) {
        if (grid[i][j] == 0) { //遍历海洋格子
          int count = 1;
          unordered_set<int> q; //把上下左右四邻放入set里，set的目的是去重
          for(int k = 0; k < 4; k++){
            int x = i + dx[k];
            int y = j + dy[k];
            // 探索当前海洋格子的四个方向的格子
            if (inArea(x, y) && grid[x][y] >= 2 && q.find(grid[x][y]) == q.end()) { // 如果grid[x][y]是岛屿
              count += island_area[grid[x][y]];
              q.insert(grid[x][y]);
            } 
          }
          res = max(res, count);   
        }
      }
    }
    return res;
  }
};