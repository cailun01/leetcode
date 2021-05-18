/*
772. 基本计算器 III
实现一个基本的计算器来计算简单的表达式字符串。

表达式字符串只包含非负整数，算符 +、-、*、/ ，左括号 ( 和右括号 ) 。整数除法需要 向下截断 。

你可以假定给定的表达式总是有效的。所有的中间结果的范围为 [-231, 231 - 1] 。

示例 1：
输入：s = "1+1"
输出：2

示例 2：
输入：s = "6-4/2"
输出：4

示例 3：
输入：s = "2*(5+5*2)/3+(6/2+8)"
输出：21

示例 4：
输入：s = "(2+6*3+5-(3*14/7+2)*5)+3"
输出：-12

示例 5：
输入：s = "0"
输出：0
 

提示：

1 <= s <= 104
s 由整数、'+'、'-'、'*'、'/'、'(' 和 ')' 组成
s 是一个 有效的 表达式
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
                int pre;
                switch (sign) {
                    case '+':
                        stk.push(num);
                        break;
                    case '-':
                        stk.push(-num);
                        break;
                    case '*':
                        pre = stk.top();
                        stk.pop();
                        stk.push(pre * num);
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