/* 28. 实现 strStr()
实现 strStr() 函数。

给定一个haystack字符串和一个needle字符串，在haystack字符串中找出needle字符串
出现的第一个位置 (从0开始)。如果不存在，则返回-1。

示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/


// 暴力解法
class Solution {
public:
  int strStr(string haystack, string needle) {
    int n_length = needle.size();
    int h_length = haystack.size();
    if (n_length == 0 && h_length == 0) {
      return 0;
    }
    if (h_length < n_length) {
      return -1;
    }
    for (int i = 0; i < h_length - n_length + 1; ++i) {
      if (haystack.substr(i, n_length) == needle) {
        return i;
      }
    }
    return -1;
  }
};
