#include "headers.h"
/*
题目：
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

示例 1：
输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]

示例 2：
输入：n = 1
输出：["()"]


有效括号的两个性质：
1、一个「合法」括号组合的左括号数量一定等于右括号数量，这个显而易见。

2、对于一个「合法」的括号字符串组合p，必然对于任何0 <= i < len(p)都有：
    子串p[0..i]中左括号的数量都大于或等于右括号的数量。

回溯思路：
算法输入一个整数n，让你计算 n对儿括号能组成几种合法的括号组合，可以改写成如下问题：
现在有2n个位置，每个位置可以放置字符(或者)，组成的所有括号组合中，有多少个是合法的？
*/

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) {
            return {};
        }
        string s("");
        vector<string> result;
        // 可用的左括号和右括号数量初始化为 n
        backtrack(n, n, s, result);
        return result;
    }
    void backtrack(int left_parentheses, int right_parentheses, string s, vector<string>& result) {
        // 数量小于 0 肯定是不合法的
        if (left_parentheses < 0 || right_parentheses < 0) {
            return;
        }
        // 若左括号剩下的多，说明不合法
        if (left_parentheses > right_parentheses) {
            return;
        }
        // 当所有括号都恰好用完时，得到一个合法的括号组合
        if (right_parentheses == 0 && left_parentheses == 0) {
            result.push_back(s);
            return;
        }
        // 尝试放一个左括号
        s.push_back('('); // 选择
        backtrack(left_parentheses - 1, right_parentheses, s, result);
        s.pop_back(); // 撤销选择
        // 尝试放一个右括号
        s.push_back(')'); // 选择
        backtrack(left_parentheses, right_parentheses - 1, s, result);
        s.pop_back(); // 撤销选择
    }
};

