/* 20 有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：
左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([)]"
输出：false

示例 5：
输入：s = "{[]}"
输出：true
 
提示：
1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
*/

/*
我们这道题就用一个名为left的栈代替之前思路中的left变量，遇到左括号就入栈，
遇到右括号就去栈中寻找最近的左括号，看是否匹配。如果不匹配，直接返回false。
如果匹配，把栈顶的左括号弹出。当所有括号都匹配时，栈为空。
*/

class Solution {
public:
  bool isValid(string str) {
    stack<char> left;
    for (char c : str) {
      if (c == '(' || c == '{' || c == '[') {
        // 左括号入栈
        left.push(c);
      } else { // 字符 c 是右括号
        if (!left.empty() && leftOf(c) == left.top()) {
          left.pop();
        } else {
          // 和最近的左括号不匹配
          return false;
        }
      }
    }
    // 是否所有的左括号都被匹配了
    return left.empty();
  }

  char leftOf(char c) {
    if (c == '}') return '{';
    if (c == ')') return '(';
    return '[';
  }
};
