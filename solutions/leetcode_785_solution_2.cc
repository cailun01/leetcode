#include "headers.h"
/*
存在一个 无向图 ，图中有 n 个节点。其中每个节点都有一个介于 0 到 n - 1 之间的唯一编号。
给你一个二维数组 graph ，其中 graph[u] 是一个节点数组，由节点 u 的邻接节点组成。形式上，
对于 graph[u] 中的每个 v ，都存在一条位于节点 u 和节点 v 之间的无向边。该无向图同时具有以下属性：
不存在自环（graph[u] 不包含 u）。
不存在平行边（graph[u] 不包含重复值）。
如果 v 在 graph[u] 内，那么 u 也应该在 graph[v] 内（该图是无向图）
这个图可能不是连通图，也就是说两个节点 u 和 v 之间可能不存在一条连通彼此的路径。
二分图 定义：如果能将一个图的节点集合分割成两个独立的子集 A 和 B ，
并使图中的每一条边的两个节点一个来自 A 集合，一个来自 B 集合，就将这个图称为 二分图 。

如果图是二分图，返回 true ；否则，返回 false 。
*/
class Solution {
public:
  enum Color {
    white = 0,
    red = 1,
    green = 2
  };
  bool isBipartite(vector<vector<int>>& graph) {
    vector<int> visited(graph.size());
    vector<Color> colors(graph.size(), Color::white);
    // label 1: red
    // label 2: green
    for (int i = 0; i < graph.size(); ++i) {
      if (colors[i] != white) {
        // 涂过色意味着已访问，不需要再入队
          continue;
      }
      queue<int> q;
      q.push(i);
      colors[i] = Color::red;
      while(!q.empty()) {
        int curr = q.front();
        q.pop();
        Color curr_label = colors[curr];
        // 相邻节点的颜色neighbor_label与当前节点cur_label相反
        Color neighbor_label;
        if (curr_label == red) {
          neighbor_label = green;
        }
        else {
          neighbor_label = red;
        }
        for (int neighbor : graph[curr]) {
          if (colors[neighbor] == white) {
            // 如果没有访问过该节点，把该节点涂成neighbor_label，与cur_label相反
            colors[neighbor] = neighbor_label;
            q.push(neighbor);
          } else if (colors[neighbor] != neighbor_label) {
            // 如果访问过该节点，但是该节点颜色不是neighbor_label
            return false;
          }
        }
      }
    }
    return true;
  }
};