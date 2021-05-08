#include "tree_node.h"
/*
给你二叉树的根结点 root ，请你将它展开为一个单链表：

展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。

输入：root = [1,2,5,3,4,null,6]
输出：[1,null,2,null,3,null,4,null,5,null,6]
示例 2：

输入：root = []
输出：[]
示例 3：

输入：root = [0]
输出：[0]

题解：
https://labuladong.github.io/algo/%E6%95%B0%E6%8D%AE%E7%BB%93%E6%9E%84%E7%B3%BB%E5%88%97/%E4%BA%8C%E5%8F%89%E6%A0%91%E7%B3%BB%E5%88%971.html

*/

class Solution {
public:
    void flatten(TreeNode* root) {
        if (!root) return;
        flatten(root->left);
        flatten(root->right);
        /**** 后序遍历位置 ****/
        // 1、左右子树已经被拉平成一条链表
        TreeNode* left_temp = root->left;
        TreeNode* right_temp = root->right;

        // 2、将左子树作为右子树
        root->left = nullptr;
        root->right = left_temp;

        // 3、将原先的右子树接到当前右子树的末端
        TreeNode* p = root;
        while (p->right) {
            p = p->right;
        }
        p->right = right_temp;
    }
};
