#include "headers.h"

// 法官不相信任何人，说明法官不存在出度
// 所有人都信任法官，说明法官的入度为N-1
// 那么法官的出度加入度为N-1
class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> degrees(N + 1);
        for (int i = 0; i < trust.size(); ++i) {
            // 这里的i是trust的索引，从0开始循环
            degrees[trust[i][0]]--; // 有出度则减1，把法官与其他人区分开
            degrees[trust[i][1]]++;
        }
        // 出度为0，入度为N
        for (int i = 1; i < degrees.size(); ++i) {
            // 这里的i对应1~N个人，从1开始循环
            if (degrees[i] == N - 1) {
                return i;
            }
        }
        return -1;
    }
};