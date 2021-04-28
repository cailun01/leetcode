#include "headers.h"
// 暴力解法
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        int num_of_elems = strs.size();
        string com_pre = "";
        string first_str = strs.at(0);
        auto min_word_length = first_str.length();
        char first_str_pre = first_str[0];
        int iter = 0;
        do {
            int num_of_equals = 0;
            int num_of_not_equals = 0;
            for (auto &word : strs) {   
                min_word_length = min(word.length(), min_word_length);
                char curr_pre = word[iter];
                if (curr_pre == first_str_pre) {
                    ++num_of_equals;
                } else {
                    ++num_of_not_equals;
                }
                if (num_of_equals == num_of_elems) {
                    com_pre += curr_pre;
                } else if (num_of_not_equals >= 1) {
                    return com_pre;
                }
            }
            ++iter;
            first_str_pre = first_str[iter];
        } while (iter < min_word_length);
        return com_pre;
    }
};