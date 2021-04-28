#include "headers.h"
#include "graph_node.h"
// dfs

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

        // If the node was already visited before.
        // Return the clone from the visited dictionary.
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }

        // Create a clone for the given node.
        // Note that we don't have cloned neighbors as of now, hence [].
        Node* clone_node = new Node(node->val);

        // The key is original node and value being the clone node.
        visited[node] = clone_node;

        // Iterate through the neighbors to generate their clones
        // and prepare a list of cloned neighbors to be added to the cloned node.
        for (auto neighbor : node->neighbors) {
            clone_node->neighbors.push_back(cloneGraph(neighbor));
        }
        return clone_node;

    }
};