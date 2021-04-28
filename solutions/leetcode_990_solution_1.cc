#include "headers.h"

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        int parent[26];
        // 初始化数组
        for(int i = 0; i < 26; i++) {
            parent[i] = i;
        }
        // 让相等关系的形成连通分量
        for (auto eq : equations) {
            if (eq[1] == '=') {
                int x = find(eq[0] - 'a', parent);
                int y = find(eq[3] - 'a', parent);
                parent[x] = parent[y];
            }
        }
        for (auto eq:equations) {
            if (eq[1] == '!') {
                int x = find(eq[0] - 'a', parent);
                int y = find(eq[3] - 'a', parent);
                if (x == y) {
                    return false;
                }
            }
        }
        return true;
    }
    int find(int x, int* parent) {
        while (x != parent[x]) {
            x = parent[x];
        }
        return x;
    }
};
