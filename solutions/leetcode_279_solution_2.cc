#include "headers.h"
// BFS，性能较差
class Solution {
public:
    int numSquares(int n) {
        set<int> visited;
        queue<pair<int, int>> q; // pair的first是节点，second是节点n到节点node的步数
        q.push({n, 0});
        while (!q.empty()) {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();
            vector<int> graph;
            for (int i = 1; i <= (int)sqrt(n); ++i) {
                graph.push_back(num - i * i);
            }
            for (int & node : graph) {
                if (node == 0) {
                    return step + 1;
                }
                if (visited.find(node) == visited.end()) {
                    visited.insert(node);
                    q.push({node, step + 1});
                }
            }
        }
        return 0;
    }
};