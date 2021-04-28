#include "headers.h"

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
            if (curr_label == red) neighbor_label = green;
            else neighbor_label = red;
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