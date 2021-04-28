#include "headers.h"

class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> in_degrees(N + 1);
        vector<vector<int>> graph(N + 1);
        for (int i = 0; i < trust.size(); ++i) {
            // 这里的i是trust的索引，从0开始循环
            in_degrees[trust[i][1]]++;
            graph[trust[i][0]].push_back(trust[i][1]);
        }
        // 出度为0，入度为N
        for (int i = 1; i < in_degrees.size(); ++i) {
            // 这里的i对应1~N个人，从1开始循环
            if (in_degrees[i] == N - 1 && graph[i].empty()) {
                return i;
            }
        }
        return -1;
    }
};