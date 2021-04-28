#include "headers.h"
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
// 示例 1：
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。

// 示例 2：
// 输入: "cbbd"
// 输出: "bb"

// 中心扩展法
// 中心扩展就是把给定的字符串的每一个字母当做中心，向两边扩展，这样来找最长的子回文串。算法复杂度为O(N^2)。
// 需要考虑两种情况：
// 长度为奇数的回文串，比如a, aba, abcba
// 长度为偶数的回文串，比如aa, abba

// https://www.jianshu.com/p/c82cada7e5b0

class Solution {
public:
  string longestPalindrome(string &s) {
  const int len = s.size();
  int maxlen = 1;
  int start = 0;

  for(int i = 0; i < len; i++){//求长度为奇数的回文串    
    int j = i - 1, k = i + 1;
    while(j >= 0 && k < len && s.at(j) == s.at(k)) {
      if(k - j + 1 > maxlen) {
        maxlen = k - j + 1;
        start = j;
      }
      j--;
      k++;
    }
  }
  for(int i = 0; i < len; i++){//求长度为偶数的回文串
    int j = i, k = i + 1;
    while(j >= 0 && k < len && s.at(j) == s.at(k)) {
      if(k - j + 1 > maxlen) {
        maxlen = k - j + 1;
        start = j;
      }
      j--;
      k++;
    }
  }

  return s.substr(start, maxlen);
}
};