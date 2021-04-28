/*
头条一道面试题

一个链表，奇数位数字升序，偶数位数字降序，让链表变成升序的
1->8->3->6->5->4->7->2->9

*/
#include <iostream>
#include <cstdlib>
#include <tuple>
#include <unordered_map>
#include <string>
#include <cstddef>
#include <vector>
using namespace std;

struct Node {
    Node(int value) : val(value) {}
    int val;
    Node* next;
};

Node* initialize_list(const vector<int>& vec) {
    Node* head = new Node(-1);
    Node* foo = head;
    for (auto& i : vec) {
        Node* node = new Node(i);
        head->next = node;
        head = head->next;
    }
    return foo->next;
}

Node* initialize_list_by_head(const vector<int>& vec) {
    Node* head = new Node(-1);
    Node* foo = head;
    for (auto& i : vec) {
        Node* node = new Node(i);
        node->next = head->next;
        head->next = node;
    }
    return foo->next;
}

tuple<Node*, Node*> divide(Node* head) {
    Node* head1 = new Node(-1);
    Node* head2 = new Node(-1);
    Node* p1 = head1;
    Node* p2 = head2;
    int count = 1;
    while (head != nullptr) {
        if (count % 2 == 1) { // 奇数，尾插法
            Node* node1 = new Node(head->val);
            p1->next = node1;
            p1 = p1->next;
        } else if (count % 2 == 0) { // 偶数，头插法
            Node* node2 = new Node(head->val);
            node2->next = p2->next;
            p2->next = node2;
        }
        
        head = head->next;
        ++count;
    }
    p1->next = nullptr;
    return make_tuple(head1->next, head2->next);
}

void print_list(Node* head) {
    while (head != nullptr) {
        cout << head->val << endl;
        head = head->next;
    }
}

int main()
{
    vector<int> vec = {1,8,3,6,5,4,7,2,9};
    Node* head = initialize_list(vec);
    tuple<Node*, Node*> two_lists_heads = divide(head);
    Node* odd = get<0>(two_lists_heads);
    Node* even = get<1>(two_lists_heads);
    
    Node* new_head = new Node(-1);
    Node* dummy = new_head;
    while (odd != nullptr 
           && even != nullptr) {
        if (odd->val <= even->val) {
            new_head->next = odd;
            odd = odd->next;
        } else {
            new_head->next = even;
            even = even->next;
        }
        new_head = new_head->next;
    }
    new_head->next = (odd ? odd : even);
    print_list(dummy->next);
}

// GCC reference:
//   https://gcc.gnu.org/

// C++ language references:
//   https://cppreference.com/
//   https://isocpp.org/
//   http://www.open-std.org/jtc1/sc22/wg21/

// Boost libraries references:
//   https://www.boost.org/doc/
