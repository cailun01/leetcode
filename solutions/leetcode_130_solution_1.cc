/*
给你一个 rows x cols 的矩阵 board ，由若干字符 'X' 和 'O' ，找到所有被 'X' 围绕的区域，
并将这些区域里所有的 'O' 用 'X' 填充。

示例 1：
输入：board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
输出：[["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
解释：被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

示例 2：
输入：board = [["X"]]
输出：[["X"]]
*/

// 用并查集
class UnionFind {
private:
  int count;
  vector<int> parent;
  // 新增一个数组记录树的“重量”，size[3] = 5表示，以节点3为根的那棵树，总共有5个节点。
  vector<int> size;
public:
  UnionFind(int cols) {
    this->count = cols;
    parent.resize(cols);
    size.resize(cols);
    // 初始化parent数组
    for (int i = 0; i < cols; ++i) {
      parent[i] = i;
      size[i] = i;
    }
  }

  int Find(int x) {
    // 根节点的 parent[x] == x
    while (parent[x] != x) {
      // 进行路径压缩
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  /* 将 p 和 q 连接 */
  void Union(int p, int q) {
    int root_p = Find(p);
    int root_q = Find(q);
    if (root_p == root_q) {
      return;
    }
    // 小树接到大树下面，较平衡
    if (size[root_p] > size[root_q]) {
      parent[root_q] = root_p;
      size[root_p] += size[root_q];
    } else {
      parent[root_p] = root_q;
      size[root_q] += size[root_p];
    }
    count--;
  }
  /* 判断 p 和 q 是否连通 */
  bool IsConnected(int p, int q) {
    int root_p = Find(p);
    int root_q = Find(q);
    return root_p == root_q;
  }
  /* 返回图中有多少个连通分量 */
  int Count() {
    return count;
  }
};

class Solution {
public:
  void solve(vector<vector<char>>& board) {
    if (board.size() == 0) return;

    int rows = board.size();
    int cols = board[0].size();
    // 给 dummy 留一个额外位置
    UnionFind uf(rows * cols + 1);
    int dummy = rows * cols;

    // 二维坐标(x,y)可以转换成x * n + y这个数
    // 将首列和末列的 O 与 dummy 连通
    for (int i = 0; i < rows; i++) {
      if (board[i][0] == 'O') {
        uf.Union(i * cols, dummy);
      }
      if (board[i][cols - 1] == 'O') {
        uf.Union(i * cols + cols - 1, dummy);
      }
    }
    // 将首行和末行的 O 与 dummy 连通
    for (int j = 0; j < cols; j++) {
      if (board[0][j] == 'O') {
        uf.Union(j, dummy);
      }
      if (board[rows - 1][j] == 'O') {
        uf.Union((rows - 1) * cols + j, dummy);
      }
    }
    // 方向数组 d 是上下左右搜索的常用手法
    vector<vector<int>> d({{1,0}, {0,1}, {0,-1}, {-1,0}});
    // 此次遍历，不包括首行、末行、首列、末列
    for (int i = 1; i < rows - 1; i++) {
      for (int j = 1; j < cols - 1; j++) {
        if (board[i][j] == 'O') {
          // 将此 O 与上下左右的 O 连通
          for (int k = 0; k < 4; k++) {
            int x = i + d[k][0];
            int y = j + d[k][1];
            if (board[x][y] == 'O') {
                uf.Union(x * cols + y, i * cols + j);
            }
          }
        }
      }
    }
    // 所有不和 dummy 连通的 O，都要被替换
    for (int i = 1; i < rows - 1; i++) {
      for (int j = 1; j < cols - 1; j++) {
        if (!uf.IsConnected(dummy, i * cols + j)) {
          board[i][j] = 'X';
        }
      }
    }
  }
};