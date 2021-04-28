/*
给定两个字符串 text1 和 text2，返回这两个字符串的最长公共子序列的长度。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某
些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。两个字符串的「公共子序列」
是这两个字符串所共同拥有的子序列。

若这两个字符串没有公共子序列，则返回 0。
*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size(), len2 = text2.size();
        // 定义：text1[0..i-1] 和 text2[0..j-1] 的 lcs 长度为 dp[i][j]
        // 目标：text1[0..len1-1] 和 text2[0..len1-1] 的 lcs 长度，即 dp[len1][len1]
        // base case: dp[0][..] = dp[..][0] = 0
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1));
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                // 现在 i 和 j 从 1 开始，所以要减一
                if (text1[i - 1] == text2[j - 1]) {
                    // s1[i-1] 和 s2[j-1] 必然在 lcs 中
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    // s1[i-1] 和 s2[j-1] 至少有一个不在 lcs 中
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[len1][len2];
    }
};