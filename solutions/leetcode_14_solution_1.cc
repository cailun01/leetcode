#include "headers.h"
/* 14. 最长公共前缀
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

示例 1：
输入：strs = ["flower","flow","flight"]
输出："fl"

示例 2：
输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/

/*
当字符串数组长度为 0 时则公共前缀为空，直接返回
令最长公共前缀 ans 的值为第一个字符串，进行初始化
遍历后面的字符串，依次将其与 ans 进行比较，两两找出公共前缀，最终结果即为最长公共前缀
如果查找过程中出现了 ans 为空的情况，则公共前缀不存在直接返回
时间复杂度：O(s)O，s 为所有字符串的长度之和
*/
class Solution {
public:
  string longestCommonPrefix(vector<string>& strs) {
    string r = strs.size() ? strs[0] : ""; // 假设strs[0]为公共前缀
    for (auto s: strs) {
      // 对当前的s，取它的前r.size个字符
      while(s.substr(0, r.size()) != r) { // 判断r是否是s的子串
        // 如果不是，删去r的最后一个字符，再进行判断
        r.pop_back();
        if(r == "") { 
          return r; 
        }
      }
    }
    return r;
  }
};
