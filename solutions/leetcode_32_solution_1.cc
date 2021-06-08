/*
括号匹配问题，常常可以用“栈”来解决，不匹配则入栈，匹配则出栈

具体思路如下：
遍历s，将 {下标,字符}组成pair依次入栈，匹配则出栈并计算有效长度，如下图所示。

其中，
“字符” 用于判断是否匹配：匹配则弹出，不匹配则入栈
“下标” 用于计算当前有效长度：匹配并弹出后，与新的栈顶的“下标”求差
“下标-1” 用于初始化，便于后续求差

链接：https://leetcode-cn.com/problems/longest-valid-parentheses/solution/czhan-zhi-guan-yi-dong-de-chu-ru-zhan-tu-wcx9/

*/
class Solution {
public:
  int longestValidParentheses(string s) {
    //将 index 入栈，有效长度为 index 之差
    //初始化入栈 -1
    stack<pair<int, char>> parenthesesStk;
    parenthesesStk.push(pair<int, char>(-1, 'x'));
    int len = 0;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] == ')' && parenthesesStk.top().second == '(') {
        parenthesesStk.pop();
        len = max(len, i - parenthesesStk.top().first);
      } else {
        parenthesesStk.push(pair<int, char>(i, s[i]));
      }
    }
    return len;
  }
};