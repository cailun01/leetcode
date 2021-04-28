/*
给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

注意：如果 s 中存在这样的子串，我们保证它是唯一的答案。

示例 1：
输入：s = "ADOBECODEBANC", t = "ABC"
输出："BANC"

示例 2：
输入：s = "a", t = "a"
输出："a"
 
提示：
1 <= s.length, t.length <= 105
s 和 t 由英文字母组成

*/

class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> need, window;

        for (char c : t) {
            need[c]++;
        }
        int left = 0, right = 0;
        int valid = 0;
        int start = 0, len = INT_MAX;

        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c) > 0) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }

            while (valid == need.size()) {
                if (right - left < len) {
                    len = right - left;
                    start = left;
                }

                char d = s[left];
                left++;
                if (need.count(d) > 0) {
                    if (window[d] == need[d]){
                        valid--;
                    }
                    window[d]--;
                }
            }
        } // while (right < s.size())
        return len == INT_MAX ? "" : s.substr(start, len);
    }
};