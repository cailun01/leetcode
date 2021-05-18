/*题目：
给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。

有加减、括号，没有乘除。

示例 1：
输入：s = "1 + 1"
输出：2

示例 2：
输入：s = " 2-1 + 2 "
输出：3

示例 3：
输入：s = "(1+(4+5+2)-3)+(6+8)"
输出：23
 
提示：

1 <= s.length <= 3 * 105
s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
s 表示一个有效的表达式
*/

class Solution {
public:
    // 定义一个成员变量i，在递归时就可以处于正确的位置。
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
                num = num * 10 + (c - '0');
            }

            if (c == '(') {
                num = calculate(s);
            }

            if (!isdigit(c) && c != ' ' || i == s.size()) {
                switch (sign) {
                    case '+':
                        stk.push(num);
                        break;
                    case '-':
                        stk.push(-num);
                        break;
                }
                sign = c;
                num = 0;
            }

            if (c == ')') {
                break;
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
