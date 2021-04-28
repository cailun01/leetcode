#include "headers.h"
#include "graph_node.h"
// bfs
class Solution {
private:
// 使用一个unordered_map存储所有已被访问和复制的节点。unordered_map中的 key 是原始图中的节点，
// value 是克隆图中的对应节点
    unordered_map<Node*, Node*> visited;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return node;

        unordered_map<Node*, Node*> visited;

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
                
                visited[n]->neighbors.push_back(visited[neighbor]);
                
            }
        }
        return visited[node];
    }
};