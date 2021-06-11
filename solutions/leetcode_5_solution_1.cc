#include "headers.h"
/* 5 最长回文子串
给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。

示例 1：
输入: "babad"
输出: "bab"
注意: "aba" 也是一个有效答案。

示例 2：
输入: "cbbd"
输出: "bb"
*/

// 中心扩展法
// 中心扩展就是把给定的字符串的每一个字母当做中心，向两边扩展，这样来找最长的子回文串。算法复杂度为O(N^2)。
// 需要考虑两种情况：
// 长度为奇数的回文串，比如a, aba, abcba
// 长度为偶数的回文串，比如aa, abba

class Solution {
public:
  string palindrome(string& s, int l, int r) {
    // 防止索引越界
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      // 向两边展开
      l--; r++;
    }
    // 此时l指向回文子串的左侧，r指向回文子串的右侧(s[l]!=s[r])
    return s.substr(l + 1, r - l - 1);
  }

  string longestPalindrome(string &s) {
    string res;
    for (int i = 0; i < s.size(); ++i) {
      // 以s[i]为中心的最长回文子串
      string s1 = palindrome(s, i, i);
      // 以s[i]和s[i+1]为中心的最长回文子串
      string s2 = palindrome(s, i, i + 1);
      // res = longest(res, s1, s2);
      res = res.size() > s1.size() ? res : s1;
      res = res.size() > s2.size() ? res : s2;
    }
    return res;
  }
};
