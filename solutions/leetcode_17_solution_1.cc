#include "headers.h"

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) {
            return {};
        }

        string s;
        // 用vector的索引记录按键对应的字母
        vector<string> num_str_map = {"", "", "abc", "def", "ghi", "jkl",
                                      "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        dfs(digits, num_str_map, res, 0, s);
        return res;
    }

    void dfs(string& digits, vector<string>& map/**/, vector<string>& res,
             int depth, string& combination) {
        if (depth == digits.size()) {
            res.push_back(combination);
            return;
        }
        
        string curr_str = map[digits[depth] - '0']; // 某数字对应的字母
        // curr_str构成选择列表
        for (int i = 0; i < curr_str.size(); ++i) {
            combination.push_back(curr_str[i]); // 做选择
            dfs(digits, map, res, depth + 1, combination);
            combination.pop_back(); // 撤销选择
        }
        return;
    }
};