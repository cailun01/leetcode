// 分治
class Solution {
public:
    unordered_map<string, vector<int>> memo;
    vector<int> diffWaysToCompute(string expression) {
        if (memo.find(expression) != memo.end()) {
            return memo[expression];
        }
        vector<int> res;
        for (int i = 0; i < expression.size(); ++i) {
            char c = expression[i];
            if (c == '-' || c == '*' || c == '+') {
                vector<int> left = diffWaysToCompute(expression.substr(0, i));
                vector<int> right = diffWaysToCompute(expression.substr(i + 1, expression.size() - i - 1));
                for (int a : left) {
                    for (int b : right) {
                        if (c == '+') {
                            res.push_back(a + b);
                        } else if (c == '-') {
                            res.push_back(a - b);
                        } else if (c == '*') {
                            res.push_back(a * b);
                        }
                    }
                }
            }
        }
        // 递归最深处只有一个数字，不会触发if(c=='-'||c =='*'||c=='+')语句，也就不会给res中添加任何元素。
        if (res.empty()) {
            res.push_back(stoi(expression));
        }
        memo[expression] = res;
        return res;
    }
};