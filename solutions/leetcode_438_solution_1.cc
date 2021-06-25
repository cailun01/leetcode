/* 438 找到字符串中所有字母异位词
给定一个字符串 s 和一个非空字符串 p，找到 s 中所有是 p 的字母异位词的子串，返回这些子串的起始索引。
字符串只包含小写英文字母，并且字符串 s 和 p 的长度都不超过 20100。
说明：
	• 字母异位词指字母相同，但排列不同的字符串。
	• 不考虑答案输出的顺序。
示例 1:
输入:
s: "cbaebabacd" p: "abc"
输出:
[0, 6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的字母异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的字母异位词。

示例 2:
输入:
s: "abab" p: "ab"
输出:
[0, 1, 2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的字母异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的字母异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的字母异位词。
*/

class Solution {
public:
  vector<int> findAnagrams(string s, string p) {
    int left = 0, right = 0;
    // valid变量表示窗口中满足need条件的字符个数
    int valid = 0;
    // need记录p中的字符出现的次数
    // window记录窗口中的需要的字符出现的次数
    unordered_map<char, int> need, window;
    vector<int> res;
    for (auto c : p) {
      need[c]++;
    }
    
    while (right < s.size()) {
      char c = s[right];
      right++;
      if (need.find(c) != need.end()) {
        window[c]++;
        if (window[c] == need[c]) {
          valid++;
        }
      }

      while (right - left >= p.size()) {
        if (valid == need.size()) {
          res.push_back(left);
        }
        char d = s[left];
        left++;
        if (need.find(d) != need.end()) {
          if (window[d] == need[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }
    return res;
  }
};