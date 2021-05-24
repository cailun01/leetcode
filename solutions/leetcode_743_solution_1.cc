#include "headers.h"
/*
有 n 个网络节点，标记为 1 到 n。
给你一个列表 times，表示信号经过有向边的传递时间。times[i] = (ui, vi, wi)，
其中 ui 是源节点，vi 是目标节点， wi 是一个信号从源节点传递到目标节点的时间。
现在，从某个节点 K 发出一个信号。需要多久才能使所有节点都收到信号？如果不能使所有节点收到信号，返回 -1 。

示例 1：
输入：times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
输出：2
示例 2：
输入：times = [[1,2,1]], n = 2, k = 1
输出：1
示例 3：
输入：times = [[1,2,1]], n = 2, k = 2
输出：-1

提示：
1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
ui != vi
0 <= wi <= 100
所有 (ui, vi) 对都互不相同（即，不含重复边）
*/

/* 求最短路径
Dijkstra 迪杰斯特拉算法，求单源最短路径问题。时间复杂度O(n^2)

Dijkstra的基本思想：
对图G(V, E)设置集合S，存放已被访问的顶点，然后每次从集合V-S(存放未访问的顶点)中选择与起点s的最短距离
最小的一个顶点(记为u)，访问并加入集合S。之后，令顶点u为中介点，优化起点s与所有从u能到达的顶点v之间的最短距离。
这样的操作执行n次（n为顶点次数），直到集合S已包含所有顶点。

Dijkstra的具体实现：
两个关键的数据结构：(1)集合S的实现、(2)起点s到达顶点Vi的最短距离的实现。
(1) 集合S可以用一个bool型数组vis[]实现，当vis[i] == true时，表示顶点Vi已经被访问，vis[i]==false表示未访问。
(2) 令int型数组d[]表示s到达顶点Vi的最短距离，初始时除了起点s的d[s]赋值为0，其余都赋值为一个很大的数来表示inf，即不可达。
伪代码：
// G为图
Dijkstra(G, d[], s) {
  初始化;
  for (循环n次) {
    u = 使d[u]最小的还未被访问的顶点的标号;
    记u已被访问
    for (从u出发能到达的所有顶点v) {
      if (v未被访问 && 以u为中介点使s到顶点v的最短距离d[v]更优) {
        优化d[v];
      }
    }
  }
}
图可以用邻接表或邻接矩阵实现，有2种写法：
邻接矩阵：枚举所有顶点来查看v是否可由u到达；
邻接表：直接得到u能到达的顶点v。

*/ 
class Solution {
public:
  // N代表N个节点，K为起点
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    /* 因为节点序号为1~N，为了方便编程，graph、distance和visited
        的size都初始化为N+1
    */
    // 构建邻接矩阵graph，用于存放各个点到各个点的距离
    vector<vector<int>> graph(N + 1, vector<int>(N + 1, -1));
    for (int i = 0; i < times.size(); ++i) {
      graph[times[i][0]][times[i][1]] = times[i][2];
    }
    
    // 存放 K 到各个点的最短路径，最大的那个最短路径即为结果
    vector<int> distance(N + 1, -1);

    // 初始化 distance 为 K 到各个节点的距离
    for (int i = 0; i < distance.size(); ++i) {
      distance[i] = graph[K][i];
    }
    // K到达K本身的节点初始化为 0
    distance[K] = 0;

    // 判断是否找到K到达该点的最短路径
    vector<bool> visited(N + 1, false);
    visited[K] = true;
    
    // 遍历除K本身节点之外的所有N-1个节点
    for (int i = 1; i <= N - 1; i++) { // 此处的i只用于循环N-1次
      int min_distance = std::numeric_limits<int>::max();
      int u = 1;
      // 遍历所有从K能到达的节点，找到离K最近的节点 
      for (int j = 1; j <= N; j++) {
        // !visited[j]: 如果没访问过节点j
        // distance[j] != -1: 从K能到达j
        // distance[j]<min_distance: distance[j]是最短距离
        if (!visited[j] && distance[j] != -1 && distance[j] < min_distance) {
          min_distance = distance[j];
          u = j;
        }
      }
      // u是离K最近的节点，标记找到了最近距离节点
      visited[u] = true;
      // 根据刚刚找到的最短距离节点u，通过节点u更新K节点与其他的节点的距离
      for (int j = 1; j <= N; j++) {
        // 如果没有访问过该节点且已更新的距节点K最短的节点u可以到达当前节点j
        // 且从u作中介的距离小于distance[j]
        if (graph[u][j] != -1) { 
          if (distance[j] != -1) {
            // K可以直达j
            distance[j] = min(distance[j], distance[u] + graph[u][j]);
          } else {
            // K不能直达j，需要u作中介点
            distance[j] = distance[u] + graph[u][j];
          }
        }
      }
    }
    int max_time = 0;
    for (int k = 1; k < distance.size(); ++k) {
      if (distance[k] == -1) {
        return -1;
      }
      max_time = max(max_time, distance[k]);
    }
    return max_time;
  }
};
