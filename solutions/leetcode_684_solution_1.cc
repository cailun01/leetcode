#include "headers.h"
/* 684 冗余连接
在本问题中, 树指的是一个连通且无环的无向图。

输入一个图，该图由一个有着N个节点 (节点值不重复1, 2, ..., N) 的树及一条附加的边构成。
附加的边的两个顶点包含在1到N中间，这条附加的边不属于树中已存在的边。

结果图是一个以边组成的二维数组。每一个边的元素是一对[u, v] ，
满足 u < v，表示连接顶点u 和v的无向图的边。

返回一条可以删去的边，使得结果图是一个有着N个节点的树。如果有多个答案，
则返回二维数组中最后出现的边。答案边 [u, v] 应满足相同的格式 u < v。

示例 1：
输入: [[1,2], [1,3], [2,3]]
输出: [2,3]
解释: 给定的无向图为:
  1
 / \
2 - 3

示例 2：
输入: [[1,2], [2,3], [3,4], [1,4], [1,5]]
输出: [1,4]
解释: 给定的无向图为:
5 - 1 - 2
    |   |
    4 - 3
注意:

输入的二维数组大小在 3 到 1000。
二维数组中的整数在1到N之间，其中N是输入数组的大小。
更新(2017-09-26):
我们已经重新检查了问题描述及测试用例，明确图是无向 图。对于有向图详见冗余连接II。对于造成任何不便，我们深感歉意。

*/
class Solution {
public:
  // 查找
  int Find(vector<int>& parent, int index) {
    while (index != parent[index]) {
      index = parent[index];
    }
    return index;
  }
  // 合并
  void Union(vector<int>& parent, int index1, int index2) {
    parent[Find(parent, index1)] = Find(parent, index2);
  }

  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    int nodesCount = edges.size();
    vector<int> parent(nodesCount + 1);
    // 初始化并查集
    for (int i = 1; i <= nodesCount; ++i) {
      parent[i] = i;
    }
    for (auto& edge: edges) {
      int node1 = edge[0], node2 = edge[1];
      if (Find(parent, node1) != Find(parent, node2)) {
        /* 如果两个顶点属于不同的连通分量，则说明在遍历到当前的边之前，
           这两个顶点之间不连通，因此当前的边不会导致环出现，
           合并这两个顶点的连通分量。*/   
        Union(parent, node1, node2);
      } else {
        /* 如果两个顶点属于相同的连通分量，则说明在遍历到当前的边之前，
           这两个顶点之间已经连通，因此当前的边导致环出现，
           为附加的边，将当前的边作为答案返回。 */
        return edge;
      }
    }
    return vector<int>{};
  }
};
