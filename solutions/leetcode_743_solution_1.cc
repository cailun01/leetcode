#include "headers.h"
// dijkstra
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
        // 构建邻接表graph，用于存放各个点到各个点的距离
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

        // 判断是否找到K到达该点最短路径
        vector<bool> visited(N + 1, false);
        visited[K] = true;
        
        // 遍历除K本身节点之外的所有N-1个节点
        for (int i = 1; i <= N - 1; i++) {
          int min_distance = std::numeric_limits<int>::max();
          int u = 1;
          // 遍历所有从K能到达的节点，找到离K最近的节点 
          for (int j = 1; j <= N; j++) {
            if (!visited[j] && distance[j] != -1 && distance[j] < min_distance) {
              min_distance = distance[j];
              u = j;
            }
          }
          // 标记最近距离节点找到
          visited[u] = true;
          // 根据刚刚找到的最短距离节点，通过该节点更新K节点与其他的节点的距离
          for (int j = 1; j <= N; j++) {
            // 如果没有访问过该节点且已更新的距离K最短的节点u可以到达当前节点j
            // 且从u作中介的距离小于distance[j]
            if (graph[u][j] != -1) { 
              if (distance[j] != -1) {
                distance[j] = min(distance[j], distance[u] + graph[u][j]);
              } else {
                // K不能直达j，需要u作中介点
                distance[j] = distance[u] + graph[u][j];
              }
            }
          }
        }
        int max_time = 0;
        for (int i = 1; i < distance.size(); ++i) {
          if (distance[i] == -1) {
            return -1;
          }
          max_time = max(max_time, distance[i]);
        }
        return max_time;
    }
};