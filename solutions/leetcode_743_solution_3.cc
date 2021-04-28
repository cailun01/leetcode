#include "headers.h"
// 队列优化的Bellman-Ford
class Solution {
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K) {
    // 构建邻接矩阵
    vector<vector<int>> v(N + 1,vector<int>(N + 1, -1));
    for(int i = 1;i<v.size();i++)
      v[i][i] = 0;

    // 遍历times填充邻接矩阵
    for(int i = 0; i < times.size(); i++) {
      v[times[i][0]][times[i][1]] = times[i][2];
    }

    vector<int> D(N+1,-1);
    D[K] = 0;
    queue<int> q;
    q.push(K);
    //SPFA
    while(!q.empty()) {
      auto cur = q.front();
      q.pop();
      for(int i = 1; i<v.size(); i++){
        if(v[cur][i] != -1 && (D[cur]+v[cur][i]<D[i] || D[i] == -1)){
          D[i] = D[cur] + v[cur][i];
          q.push(i);
        }
      }
    }
    int res=-1;
    for(int i=1;i<N+1;i++){
        if(D[i]==-1)
            return -1;
        res=max(res,D[i]);
    }   
    return res;
  }
};