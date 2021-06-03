#include "headers.h"

/* 拓扑排序的思路：
1. 定义一个队列Q，并把所有入度为0的节点加入队列。
2. 取队首节点，输出，然后删去所有从它出发的边，并令这些到达的顶点入度减1，
如果某个顶点的入度减为0，将其加入队列Q。
3. 反复进行第2步操作，直到队列为空。如果队列为空时入过队的节点数目恰好为N，
说明拓扑排序成功，图G为有向无环图，否则，图G中有环，拓扑排序失败。
*/

class Solution {
public:
  /* 先修课程按数组 prerequisites 给出，其中 prerequisites[i] = [ai, bi] ，
  表示如果要学习课程 ai 则 必须 先学习课程  bi 。
  bi -> ai
  */ 
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    // 记录所有顶点的入度,未初始化的为0
    vector<int> in_degrees(numCourses);
    // 邻接表
    vector<vector<int>> adjacents(numCourses); 
    // 记录入度为0的顶点
    queue<int> zero;
    // 加入拓扑排序的顶点数
    int num = 0;
    for (int i = 0; i < prerequisites.size(); i++) {
      //入顶点
      in_degrees[prerequisites[i][0]]++;
      //出顶点
      adjacents[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }

    for (int i = 0; i < numCourses; i++) {
      // 入度为0的先入队列
      if (in_degrees[i] == 0){
        zero.push(i); 
        num++;
      }
    }
            
    while (!zero.empty()) {
      int temp = zero.front();
      zero.pop();
      for (int j = 0; j < adjacents[temp].size(); j++) {
        // post是temp的后继
        int post = adjacents[temp][j]; 
        // 顶点post的入度减1
        in_degrees[post] -= 1;
        // 如果后继节点的入度是0
        if (in_degrees[post] == 0) { 
          zero.push(post);
          num++;
        }
      }     
    }
    return num == numCourses;
  }
};
