/* 1597 根据中缀表达式构造二叉表达式树
二叉表达式树 是一种表达算术表达式的二叉树。二叉表达式树中的每一个节点都有零个或两个子节点。 
叶节点（有 0 个子节点的节点）表示操作数，非叶节点（有 2 个子节点的节点）
表示运算符： '+' （加）、 '-' （减）、 '*' （乘）和 '/' （除）。
对于每一个运算符为 o 的非叶节点，对应的 中缀表达式 为 (A o B)，其中 A 是左子树所表达的表达式， B 是右子树所表达的表达式。
给定一个 中缀表达式 字符串 s，其中包含操作数、上面提到的运算符，以及括号 '(' 与 ')' 。
返回一个有效的 二叉表达式树，其 中序遍历 序列对应表达式 s 消除括号后的序列（详情参见下面的示例）。
注意，表达式的一般解析顺序适用于 s，即优先解析括号内的表达式，然后解析乘除法，最后解析加减法。

同时，操作数在 s 和树的中序遍历中 出现顺序相同 。

示例 1：
输入：s = "3*4-2*5"
输出：[-,*,*,3,4,2,5]
解释：上面是唯一一种有效的二叉表达式树，其中序遍历生成 s 。

示例 2：
输入：s = "2-3/(5*2)+1"
输出：[+,-,1,2,/,null,null,null,null,3,*,null,null,5,2]
解释：上面的树的中序遍历为 2-3/5*2+1 ，与 s 消除括号后相同。该树还会生成正确的结果，其操作数的顺序与 s 中出现的顺序相同。
下面的树也是一个有效的二叉表达式树，具有与 s 相同的中序遍历，但它不是一个有效的答案，因为它的求值结果不同。
下面的树也是无效的。尽管它的计算结果相等并与上述树等效，但其中序遍历不会产生 s ，并且其操作数与 s 中的顺序也不相同。

示例 3：
输入：s = "1+2+3+4+5"
输出：[+,+,5,+,4,null,null,+,3,null,null,1,2]
解释：二叉树 [+,+,5,+,+,null,null,1,2,3,4] 也是诸多有效的二叉表达式树之一。

1 <= s.length <= 105
s 中包含数字和字符 '+'、 '-'、 '*'、 '/' 。
s 中的操作数 恰好 是一位数字。
题目数据保证 s 是一个有效的表达式。
*/

/**
 * Definition for a binary tree node.
 * struct Node {
 *     char val;
 *     Node *left;
 *     Node *right;
 *     Node() : val(' '), left(nullptr), right(nullptr) {}
 *     Node(char x) : val(x), left(nullptr), right(nullptr) {}
 *     Node(char x, Node *left, Node *right) : val(x), left(left), right(right) {}
 * };
 */


/*
一个基本思路是将中缀表达式转化为后缀表达式，然后后缀表达式结合中缀表达式确定一个唯一的表达式树；
事实上对于表达式树，操作符是操作数的父节点，在转化为后缀表达式的过程中子节点都是已知的，
可直接拼接到父节点生成表达式树；

代码为常规中缀表达式转后缀表达式算法，只是数字不再是维护在后缀表达式队列里，
而是也维护在栈st_node中，在每次高优先级操作符出栈时也不是拼接到后缀表达式队列后面，
而是与栈中的两个操作数结合，再次入栈st_node。
*/
#include <cctype> // isdigit
class Solution {
public:
  Node* expTree(string s) {
    int n = s.size();
    int i = 0;
    stack<char> st_symbol; // 存放操作符
    stack<Node*> st_node;  // 存放后缀表达式
    while(i < n) {
      if(s[i] == '(') {
        // 出现左括号，则压入栈
        st_symbol.push('(');
      } else if (s[i] == ')') {
        // 出现右括号，把st_symbol栈的元素不断弹出，放入后缀表达式栈st_node，
        // 直到遇到左括号
        while(!st_symbol.empty() && st_symbol.top() != '(') {
          make_node(st_symbol, st_node);
        }
        st_symbol.pop();
      } else if (isdigit(s[i])) {
        // 如果是数字
        Node *node = new Node(s[i]);
        // 压入存放后缀表达式的栈
        st_node.push(node);
      } else {
        // st_symbol的栈顶元素的优先级比当前操作符s[i]的优先级高
        while(!st_symbol.empty() 
              && symbol_priority[st_symbol.top()] >= symbol_priority[s[i]]) {
          // 把栈顶元素弹出，放入存放后缀表达式的栈
          make_node(st_symbol, st_node);
        }
        // 把该操作符压入栈
        st_symbol.push(s[i]);
      }
      ++i;
    }
    while(!st_symbol.empty()) {
      make_node(st_symbol, st_node);
    }
    return st_node.top();
  }

private:
  void make_node(stack<char>& st_symbol, stack<Node*>& st_node) {
    char op = st_symbol.top();
    st_symbol.pop();
    Node *node = new Node(op);
    // 先出栈的节点作右子树
    Node *right = st_node.top();
    st_node.pop();
    Node *left = st_node.top();
    st_node.pop();
    node->left = left;
    node->right = right;
    st_node.push(node);
  }

  unordered_map<char, int> symbol_priority{{'(', 0}, {'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
};