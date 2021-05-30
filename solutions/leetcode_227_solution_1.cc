/* 227 基本计算器 II
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

整数除法仅保留整数部分。

示例 1：
输入：s = "3+2*2"
输出：7

示例 2：
输入：s = " 3/2 "
输出：1

示例 3：
输入：s = " 3+5 / 2 "
输出：5

提示：

1 <= s.length <= 3 * 105
s 由整数和算符 ('+', '-', '*', '/') 组成，中间由一些空格隔开
s 表示一个 有效表达式
表达式中的所有整数都是非负整数，且在范围 [0, 231 - 1] 内
题目数据保证答案是一个 32-bit 整数
*/

class Solution {
public:
  int i = 0;
  int calculate(string s) {
    if (s.size() == 0) {
        return 0;
    }
    int num = 0;
    char sign = '+';
    stack<int> stk;
    while (i < s.size()) {
      char c = s[i++];
      if (isdigit(c)) {
        num = 10 * num + (c - '0');
      }
      if ((!isdigit(c) && c != ' ') || i == s.size()) {
        switch (sign) {
          int pre;
          case '+':
            stk.push(num);
            break;
          case '-':
            stk.push(-num);
            break;
          case '*':
            pre = stk.top();
            stk.pop();
            stk.push(num * pre);
            break;
          case '/':
            pre = stk.top();
            stk.pop();
            stk.push(pre / num);
            break;
        }
        sign = c;
        num = 0;
      }
    }
    int res = 0;
    while (!stk.empty()) {
      res += stk.top();
      stk.pop();
    }
    return res;
  }
};