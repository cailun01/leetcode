/* 785 二分图
存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。给你一个二维数组 graph ，
其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。形式上，对于 graph[u] 中的每个 v ，
都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有以下属性：
不存在自环（graph[u] 不包含 u）。
不存在平行边（graph[u] 不包含重复值）。
如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，并使图中的每一条边的两个节点一个来自 A 集合
，一个来自 B 集合，就将这个图称为 二分图 。

如果图是二分图，返回 true ；否则，返回 false 。

示例 1：
输入：graph = [[1,2,3],[0,2],[0,1,3],[0,2]]
输出：false
解释：不能将节点分割成两个独立的子集，以使每条边都连通一个子集中的一个节点与另一个子集中的一个节点。

示例 2：
输入：graph = [[1,3],[0,2],[1,3],[0,2]]
输出：true
解释：可以将节点分成两组: {0, 2} 和 {1, 3} 。
*/

/*
使用并查集。我们知道如果是二分图的话，那么图中每个顶点的所有邻接点都应该属于同一集合，
且不与顶点处于同一集合。因此我们可以使用并查集来解决这个问题，我们遍历图中每个顶点，将当前顶点的所有邻接点进行合并，
并判断这些邻接点中是否存在某一邻接点已经和当前顶点处于同一个集合中了，若是，则说明不是二分图。
*/

class UnionFind {
private:
  int count;
  vector<int> parent;
public:
  UnionFind(int n) {
    count = n;
    parent.resize(count);
    for (int i = 0; i < count; ++i) {
      parent[i] = i;
    }
  }

  int Find(int x) {
    while (parent[x] != x) {
      // 路径压缩
      parent[x] = parent[parent[x]];
      x = parent[x];
    }
    return x;
  }

  void Union(int p, int q) {
    int root_p = Find(p);
    int root_q = Find(q);
    if (root_p == root_q) {
      return;
    }
    parent[root_p] = root_q;
    count--;
  }

  bool IsConnected(int p, int q) {
    int root_p = Find(p);
    int root_q = Find(q);
    return root_p = root_q;
  }
};

class Solution {
public:
  bool isBipartite(vector<vector<int>>& graph) {
    UnionFind uf(graph.size());
    for (int i = 0; i < graph.size(); ++i) {
      // i 是图中的节点
      auto adj = graph[i];
      for (int j = 0; j < adj.size(); ++j) {
        if (uf.IsConnected(i, adj[j])) {
          // 当前节点i与其邻接节点在同一连通域，返回false
          return false;
        }
        // 把当前节点i的所有邻接节点adj[0...adj.size()-1]合并
        uf.Union(adj[0], adj[i]);
      }
    }
    return true;
  } 
};
