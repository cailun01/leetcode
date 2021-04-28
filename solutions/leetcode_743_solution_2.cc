#include "headers.h"
// Bellman-Ford

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int N, int K) {
      vector<int> distance(N + 1, -1);
      distance[K] = 0;

      // 
      for (int i = 1; i < N; ++i) {
        for (int i = 0; i < times.size(); ++i) {
          int src = times[i][0];
          int des = times[i][1];
          int d = times[i][2];
          if (distance[src] != -1 && (distance[src] + d < distance[des] || distance[des] == -1)) {
            distance[des] = distance[src] + d;
          }
        }
      }

      int maxDistance = 0;
      for (int i = 1; i <= N; i++) {
        if (distance[i] == -1) {
          return -1;
        }
        maxDistance = max(distance[i], maxDistance);
      }
      return maxDistance;
    }
};