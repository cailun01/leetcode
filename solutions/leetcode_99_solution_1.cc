#include "headers.h"
#include "tree_node.h"
/**
 * 在第一次遇到不递增的情况时，将first设置为3，second设置为2，在第二次遇到不递增的情况时，
 * 只改变second，将second置为1.遍历结束后交换first与second。
 * 

 */
class Solution {
public:
    TreeNode* first = nullptr;
    TreeNode* second = nullptr;
    TreeNode* pre = nullptr;
    void inorder(TreeNode* root){
        if(root == NULL) {
            return;            
        }

        inorder(root->left);
        if(pre != nullptr && pre->val > root->val){
            if(first == nullptr){//first为空,首次找到前后大小不对的点
                first = pre;
                second = root;
            }else{//first不为空,第二次找到前后大小不对的点,只更新second
                second = root;
            }
        }
        pre = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};
