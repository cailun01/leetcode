/* 516 最长回文子序列
给定一个字符串 s ，找到其中最长的回文子序列，并返回该序列的长度。可以假设 s 的最大长度为 1000 。

示例 1:
输入:
"bbbab"
输出:
4
一个可能的最长回文子序列为 "bbbb"。

示例 2:
输入:
"cbbd"
输出:
2
一个可能的最长回文子序列为 "bb"。
*/

/*
在子数组array[i..j]中，我们要求的子序列（最长回文子序列）的长度为dp[i][j]。
假设你知道了子问题dp[i+1][j-1]的结果，根据s[i]和s[j]的字符可以算出dp[i][j]的值。
  s[i] == s[j], 它俩加上s[i+1..j-1]中的最长回文子序列就是s[i..j]的最长回文子序列
  s[i] != s[j], 它俩不可能同时出现在s[i..j]的最长回文子序列中，
                那么把它俩分别加入s[i+1..j-1]中，看看哪个子串产生的回文子序列更长即可
*/
class Solution {
public:
  int longestPalindromeSubseq(string s) {
    // 在子数组array[i..j]中，我们要求的子序列（最长回文子序列）的长度为dp[i][j]。
    int n = s.size();
    if (n == 0 || n == 1) {
      return n;
    }
    
    // dp 数组全部初始化为 0
    vector<vector<int>> dp(n, vector<int>(n, 0));
    // base case
    for (int i = 0; i < n; i++) {
      dp[i][i] = 1;
    }
    // 反着遍历保证正确的状态转移
    for (int i = n - 2; i >= 0; i--) {
      for (int j = i + 1; j < n; j++) {
        // 状态转移方程
        if (s[i] == s[j]) {
          // 它俩一定在最长回文子序列中
          dp[i][j] = dp[i + 1][j - 1] + 2;
        } else {
          // s[i+1..j] 和 s[i..j-1] 谁的回文子序列更长？
          dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
        }
      }
    }
    // 整个 s 的最长回文子串长度
    return dp[0][n - 1];
  }
};
