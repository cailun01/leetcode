class Solution {
public:
    int calculate(string s) {
        if (s.size() == 0) {
            return 0;
        }

        int num = 0;
        char sign = '+';
        stack<int> stk;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = 10 * num + (c - '0');
            }
            if ((!isdigit(c) && c != ' ') || i == s.size() - 1) {
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