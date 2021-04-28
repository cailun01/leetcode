#include "headers.h"
#include "tree_node.h"

//其核心思想如下：
// 使用颜色标记节点的状态，新节点为白色，已访问的节点为灰色。
// 如果遇到的节点为白色，则将其标记为灰色，然后将其右子节点、自身、左子节点依次入栈。
// 如果遇到的节点为灰色，则将节点的值输出。

class Solution {
	vector<int>ans;
public:
	vector<int> inorderTraversal(TreeNode* root) {
		int white = 0;
		int gray = 1;
		stack<pair<int, TreeNode*>>s;
		s.push(make_pair(white,root));
		while (!s.empty()) {
			int color = s.top().first;
			TreeNode* t = s.top().second;
			s.pop();
			if (t == NULL) continue;
			if (color == white)
			{
				s.push(make_pair(white, t->right));
				s.push(make_pair(gray, t));
				s.push(make_pair(white, t->left));
			}
			else ans.push_back(t->val);
		}
		return ans;
	}
};