/*
我们这道题就用一个名为left的栈代替之前思路中的left变量，遇到左括号就入栈，
遇到右括号就去栈中寻找最近的左括号，看是否匹配。
*/

class Solution {
public:
    bool isValid(string str) {
        stack<char> left;
        for (char c : str) {
            if (c == '(' || c == '{' || c == '[') {
                // 左括号入栈
                left.push(c);
            }
            else {// 字符 c 是右括号
                if (!left.empty() && leftOf(c) == left.top())
                    left.pop();
                else
                    // 和最近的左括号不匹配
                    return false;
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
