#include "headers.h"
/*
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖整个字符串s的，而不是部分字符串。

说明:
s 可能为空，且只包含从 a-z 的小写字母。
p 可能为空，且只包含从 a-z 的小写字母，以及字符 . 和 *。

示例 1:
输入:
s = "aa"
p = "a"
输出: false
解释: "a" 无法匹配 "aa" 整个字符串。

示例 2:
输入:
s = "aa"
p = "a*"
输出: true
解释: 因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。
因此，字符串 "aa" 可被视为 'a' 重复了一次。

示例 3:
输入:
s = "ab"
p = ".*"
输出: true
解释: ".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

示例 4:
输入:
s = "aab"
p = "c*a*b"
输出: true

解释: 因为 '*' 表示零个或多个，这里 'c' 为 0 个, 'a' 被重复一次。因此可以匹配字符串 "aab"。
示例 5:
输入:
s = "mississippi"
p = "mis*is*p*."
输出: false
*/

/*
确定状态方程之前先明确都会出现什么情况。
首先就是s[i-1]与p[j-1]之间的关系，可能相等，可能不等。
相等时，dp[i][j] == dp[i-1][j-1]
不等的情况下有三种情况：
（1）p[j-1]为'*'，
（2）p[j-1]为'.'
（3）p[j-1]就是普通的一个字符。

*/
class Solution {
public:
  bool isMatch(string s, string p) {
    int m = s.length();
    int n = p.length();
    if (m == 0 && n == 0) {
      return true;
    }
    // dp[i][j]==true 表示s的前i位[0,i)和p的前j位[0,j)是匹配的
    // 区间是左开右闭的，假设dp[i-1][j-1]匹配，接下来比较s[i-1]与p[i-1]。
    vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
    // s和p都为空字符串时，返回true
    dp[0][0] = true;
    
    if (m > 0 && n > 0) {
      // j=1时p只有一个字符，只能匹配一个字符，其他全部为false
      dp[1][1] = (s[0] == p[0] || p[0] == '.'); // 这句在s是空串时会越界。
    }
    
    // i=0时s为空串，p只有类似a*b*c*d*这样的形式才可以成功匹配
    for (int j = 2; j < n + 1; j++) {
      // 前0位和前j-2位是匹配的，且第j位是*
      if(p[j - 1] == '*' && dp[0][j - 2]) {
        dp[0][j] = true;
      }
    }

    for(int i = 1; i <= m; i++) {
      for(int j = 1; j <= n; j++) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '.') {
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          if (p[j - 1] == '*') {
            if (p[j - 2] != s[i - 1] && p[j - 2] != '.') {
              dp[i][j] = dp[i][j - 2];
            } else if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
              dp[i][j] = (dp[i][j - 2] || dp[i][j - 1] || dp[i - 1][j]);
            }
          }
        }
      }
    }
    return dp[m][n];
  }
};