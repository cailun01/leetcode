/* 647. 回文子串
给定一个字符串，你的任务是计算这个字符串中有多少个回文子串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。

示例 1：
输入："abc"
输出：3
解释：三个回文子串: "a", "b", "c"

示例 2：
输入："aaa"
输出：6
解释：6个回文子串: "a", "a", "a", "aa", "aa", "aaa"
*/

class Solution {
public:
  int helper(const string& s, int i, int j) {
    int num = 0;
    while (i >= 0 && j < s.size() && s[i] == s[j]) {
      ++num;
      --i, ++j;
    }
    return num;
  }
  int countSubstrings(string s) {
    if (s.size() == 0 || s.size() == 1) {
      return s.size();
    }
    int result = 0;
    for (int i = 0; i < s.size(); ++i) {
      int num1 = helper(s, i, i);
      result += num1;
      if (i < s.size() - 1) {
        int num2 = helper(s, i, i + 1);
        result += num2;
      }
    }
    return result;
  }
};