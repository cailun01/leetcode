#include "headers.h"
#include "138.h"

class Solution {
private:
    unordered_map<Node*, Node*> visited;
public:
  Node* copyRandomList(Node* head) {
    if (!head) return head;

    Node* clone_node = new Node(head->val);
    visited[head] = clone_node;

    queue<Node*> q;
    q.push(head);

    while (!q.empty()) {
      Node* cur = q.front();
      q.pop();
      
      if (cur->next) {
        if (visited.find(cur->next) == visited.end()) {
          Node* clone_cur_next = new Node(cur->next->val);
          visited[cur->next] = clone_cur_next;
          q.push(cur->next);
        }
        visited[cur]->next = visited[cur->next];
      }
      if (cur->random) {
        if (visited.find(cur->random) == visited.end()) {
          Node* clone_cur_random = new Node(cur->random->val);
          visited[cur->random] = clone_cur_random;
          q.push(cur->random);
        }
        visited[cur]->random = visited[cur->random];
      }
    }
    return clone_node;
  }
};