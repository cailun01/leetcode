#include "headers.h"

/* 3 无重复字符的最长子串
题目：给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

示例 4:
输入: s = ""
输出: 0
*/ 

class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> window;
    int left = 0, right = 0;
    int res = 0; // 记录结果
    while (right < s.size()) {
      char c = s[right];
      right++;
      // 进行窗口内数据的一系列更新
      window[c]++;
      // 字母c在窗口内重复了，左侧窗口要收缩
      while (window[c] > 1) {
        char d = s[left];
        left++;
        // 进行窗口内数据的一系列更新
        window[d]--;
      }
      // 在这里更新答案
      // 此时right已经右移，不再指向字符c
      // 因此长度为 right - left而不是right-left + 1
      res = max(res, right - left);
    }
    return res;
  }
};
