#include "headers.h"
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

// KMP算法
class Solution {
public:
  int strStr(string haystack, string needle) {
    if(needle.size() == 0) return 0;
    if(haystack.size() == 0) return -1;
    // 根据needle，构建next数组
    int j = -1, i = 0;//j在后面，i在前面
    vector<int> next(needle.size() + 1);
    next[0] = j;
    while(i < needle.size()) {
      while(j >= 0 && needle[i] != needle[j]) {
        j = next[j];
      }
      i++, j++;
      next[i] = j;
    }
    
    j = 0, i = 0; //j这回是haystack的， i是needle的
    while(j < haystack.size()) {
      while(i >= 0 && needle[i] != haystack[j]) { 
        i = next[i]; 
      }
      i++, j++;
      if(i == needle.size()) {
        return j - needle.size();
      }
    }
    return -1;
  }
};