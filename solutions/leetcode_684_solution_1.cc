#include "headers.h"

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int sz = edges.size();
        vector<int> rp(2 * sz);
        // 初始化各元素为单独的集合，代表节点就是其本身
        for(int i=0;i<sz;i++)
            rp[i] = i;
        for(int j=0;j<sz;j++){
            // 找到边上两个节点所在集合的代表节点
            int set1 = find(edges[j][0], rp);
            int set2 = find(edges[j][1], rp);
            if(set1 == set2)  // 两个集合代表节点相同，说明出现环，返回答案
                return edges[j]; 
            else    // 两个集合独立，合并集合。将前一个集合代表节点戳到后一个集合代表节点上
                rp[set1] = set2;
        }
        return {0, 0};
    }

    // 查找路径并返回代表节点，实际上就是给定当前节点，返回该节点所在集合的代表节点
    int find(int n, vector<int> &rp){
        int num = n;
        while(rp[num] != num)
            num = rp[num];
        return num;
    }
};
