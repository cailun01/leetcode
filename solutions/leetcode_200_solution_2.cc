// 没通过

// 并查集
class UnionFind {
private:
  vector<int> parent;
  int count;
public:
  UnionFind(int n) : count(n) {
    parent.resize(n);
    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int Find(int x) {
    while (x != parent[x]) {
      x = parent[x];
    }
    return x;
  }

  void Union(int x, int y) {
    int parent_x = Find(x);
    int parent_y = Find(y);
    if (parent_x != parent_y) {
      parent[parent_x] = parent_y;
    }
    // 合并连接后，连通分量总数减少
    count--;
  }

  bool IsConnected(int x, int y) {
    return Find(x) == Find(y);
  }

  int GetCount() {
    // 返回当前的连通分量个数
    return count;
  }
};

class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.size() == 0) {
      return 0;
    }

    int row = grid.size();
    int col = grid[0].size();
    int water = 0; // 水域个数
    UnionFind uf(row * col);
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == '0') {
          ++water;
        } else { /* grid[i][j] == '1' */
          vector<vector<int>> directions({{0, 1}, {0, -1}, {1, 0}, {-1, 0}});
          for (const auto& dir : directions) {
            int x = i + dir[0];
            int y = j + dir[1];
            if (x >= 0 && y >= 0 && x < row && y < col && grid[x][y] == '1') {
              // 二维数组转一维数组的方法
              uf.Union(i * col + j, x * col + y);
            }
          }
        }
      }
    }
    return uf.GetCount() - water;
  }
};