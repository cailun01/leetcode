// 深度优先搜索

class Solution {
public:
  void setZeroes(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<bool>> isFinded(n, vector<bool>(m, false));//记录查找过的位置
    
    //遍历方向
    vector<vector<int>> dirs = { {1,0},{-1,0},{0,1},{0,-1} };
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (matrix[i][j] == 0 && isFinded[i][j] == false) {
          for (int k = 0; k < 4; k++)//四个方向 {
            DFS(matrix, i, j, isFinded, dirs[k]);
          }
        }
      }
    return;
  }
      
  void DFS(vector<vector<int>>& matrix, int i, int j, vector<vector<bool>>& isFinded, vector<int> dir) {
    if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size()) {
      return;
    }
    if (matrix[i][j] != 0 && isFinded[i][j] == false) {
      matrix[i][j] = 0;
      isFinded[i][j] = true;
    }
    DFS(matrix, i + dir[0], j + dir[1], isFinded, dir);//每次只朝一个方向进行DFS
  }
};