#include "headers.h"
// 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
// 示例 1：
// 输入: "babad"
// 输出: "bab"
// 注意: "aba" 也是一个有效答案。

// 示例 2：
// 输入: "cbbd"
// 输出: "bb"

// 动态规划
// https://leetcode-cn.com/problems/longest-palindromic-substring/solution/c-jian-ji-hao-li-jie-de-dong-tai-gui-hua-by-mei-yo/

// 注意，本题的要求是返回最长回文子串，而不是求最长回文子串的长度
class Solution {
public:
  string longestPalindrome(string s) {
    int n = s.size();
    string res = "";
    int l = 0;  //l用来记录当前最长的回文子串
    if (s.size() == 0) return res;
    if (s.size() == 1) return s;
    res = s[0];  //返回子串初始化为第一个元素
    // dp[i][j] 表示s[i]至s[j]表示的子串是否为回文子串，是为true，不是为false
    vector<vector<bool>> dp(n, vector<bool>(n));
    for (int j = 0; j < n; j++) {
      for (int i = j; i >= 0; i--){
        if ((s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1])) { 
          // j-i<=2相当于j-1<=i+1，如果成立，此时右指针j-1指向的数会在左指针i+1的左边
          dp[i][j] = true;
          if (j - i > l){
            res = s.substr(i, j - i + 1);
            l = j - i;
          }
        }
      }
    }
    return res;
  }
};
