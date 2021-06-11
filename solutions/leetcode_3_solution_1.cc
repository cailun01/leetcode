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

/*
标签：滑动窗口
1 HashMap 存放已经找到的不重复的字符及其在字符串中的位置
2 左右两个指针(i与j)，分别记录当前子串的起始位置和终止位置
3 定义一个 map 数据结构存储 (k, v)，其中 key 值为字符，value 值为字符位置 +1，加 1 表示从字符位置后一个才开始不重复
4 我们定义不重复子串的开始位置为 start，结束位置为 end
随着 end 不断遍历向后，会遇到与 [start, end] 区间内字符相同的情况，此时将字符作为 key 值，获取其 value 值，
并更新 start，此时 [start, end] 区间内不存在重复字符无论是否更新 start，都会更新其 map 数据结构和结果 ans。

如何保证两个指针之间[i,j]的字符是独一无二的？
假设j指向一个字符'a'，那么i指向的字符一定是上一次出现'a'的位置的右面的位置。
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
      // 判断左侧窗口是否要收缩
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

// 函数用idx这个vector作HashMap。因为把char类型作vector下标时，其表示的下标值为该字符的ASCII码的十进制值。
// idx存储的值就是for循环中j的值，即右指针的值