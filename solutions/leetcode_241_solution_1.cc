/* 241 为运算表达式设计优先级

给定一个含有数字和运算符的字符串，为表达式添加括号，改变其运算优先级以求出不同的结果。
你需要给出所有可能的组合的结果。有效的运算符号包含 +, - 以及 * 。

示例 1:
输入: "2-1-1"
输出: [0, 2]
解释: 
((2-1)-1) = 0 
(2-(1-1)) = 2

示例 2:
输入: "2*3-4*5"
输出: [-34, -14, -10, -10, 10]
解释: 
(2*(3-(4*5))) = -34 
((2*3)-(4*5)) = -14 
((2*(3-4))*5) = -10 
(2*((3-4)*5)) = -10 
(((2*3)-4)*5) = 10
*/

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
