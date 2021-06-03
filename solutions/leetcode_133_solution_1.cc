#include "headers.h"
#include "graph_node.h"

/* 133 克隆图
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。
图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

class Node {
    public int val;
    public List<Node> neighbors;
}
 
测试用例格式：
简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），
第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。

邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。
给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。
*/

// bfs
class Solution {
private:
// 使用一个unordered_map存储所有已被访问和复制的节点。unordered_map中的 key 是原始图中的节点，
// value 是克隆图中的对应节点
  unordered_map<Node*, Node*> visited;
public:
  Node* cloneGraph(Node* node) {
    if (!node) {
      return node;
    }
    queue<Node*> q;
    q.push(node);

    Node* clone_node = new Node(node->val);
    visited[node] = clone_node;

    while (!q.empty()) {
      Node* n = q.front();
      q.pop();

      for (auto neighbor : n->neighbors) {
        if (visited.find(neighbor) == visited.end()) {
          // 如果没有访问过
          Node* clone_neighbor = new Node(neighbor->val);
          visited[neighbor] = clone_neighbor;
          q.push(neighbor);
        }
        // 为克隆的节点的邻接表添加元素
        visited[n]->neighbors.push_back(visited[neighbor]);
      }
    }
    return visited[node];
  }
};
