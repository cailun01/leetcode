#include "headers.h"
/* 17. 电话号码的字母组合
给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。

给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]
*/
class Solution {
    vector<string> num_str_map{""/*0*/, ""/*1*/, "abc"/*2*/, "def"/*3*/, 
                               "ghi"/*4*/, "jkl"/*5*/, "mno"/*6*/,
                               "pqrs"/*7*/, "tuv"/*8*/, "wxyz"/*9*/};
    vector<string> res;
public:
  vector<string> letterCombinations(string digits) {
    if (digits.length() == 0) {
      return {};
    }

    string s;
    // 用vector的索引记录按键对应的字母

    dfs(digits, 0, s);
    return res;
  }

  void dfs(string& digits, int depth, string& combination) {
    // depth用于获取digits中的数字
    if (depth == digits.size()) {
      res.push_back(combination);
      return;
    }
    
    string curr_str = num_str_map[digits[depth] - '0']; // 某数字对应的字母
    // curr_str构成选择列表
    for (int i = 0; i < curr_str.size(); ++i) {
      combination.push_back(curr_str[i]); // 做选择
      dfs(digits, depth + 1, combination);
      combination.pop_back(); // 撤销选择
    }
    return;
  }
};
