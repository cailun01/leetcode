#include "headers.h"
// BFS，性能较差
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
      set<int> visited;
      queue<pair<int, int>> q; // pair的first是节点，second是节点n到节点node的步数
      q.push({amount, 0});
      while (!q.empty()) {
        int num = q.front().first;
        int step = q.front().second;
        q.pop();
        vector<int> graph;
        for (auto & c : coins) {
          if (num - c >= 0) {
            graph.push_back(num - c);
          }
        }
        for (auto & node : graph) {
          if (node == 0) {
            return step + 1;
          }
          if (visited.find(node) == visited.end()) {
                    visited.insert(node);
                    q.push({node, step + 1});
          }
        }
      }
      return -1;
    }

};