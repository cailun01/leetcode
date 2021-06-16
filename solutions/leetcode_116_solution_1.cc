#include "tree_node.h"

/* 116. 填充每个节点的下一个右侧节点指针
给定一个完美二叉树 ，其所有叶子节点都在同一层，每个父节点都有两个子节点。二叉树定义如下：

struct Node {
  int val;
  Node *left;
  Node *right;
  Node *next;
}
填充它的每个next指针，让这个指针指向其下一个右侧节点。如果找不到下一个右侧节点，则将next指针设置为NULL。

初始状态下，所有next指针都被设置为NULL。


进阶：

你只能使用常量级额外空间。
使用递归解题也符合要求，本题中递归程序占用的栈空间不算做额外的空间复杂度。
*/

/*
https://labuladong.github.io/algo/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%B3%BB%E5%88%971.html
*/

class Solution {
public:
  Node* connect(Node* root) {
    if (!root) return nullptr;
    connectTwo(root->left, root->right);
    return root;
  }

  void connectTwo(Node* left, Node* right) {
    if (!left || !right) {
      return;
    }

    left->next = right;

    connectTwo(left->left, left->right);
    connectTwo(right->left, right->right);
    connectTwo(left->right, right->left);
  }
};
