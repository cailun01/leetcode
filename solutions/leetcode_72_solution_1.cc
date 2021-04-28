#include "headers.h"
// 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

// 你可以对一个单词进行如下三种操作：

// 插入一个字符
// 删除一个字符
// 替换一个字符
//  

// 示例 1：

// 输入：word1 = "horse", word2 = "ros"
// 输出：3
// 解释：
// horse -> rorse (将 'h' 替换为 'r')
// rorse -> rose (删除 'r')
// rose -> ros (删除 'e')
// 示例 2：

// 输入：word1 = "intention", word2 = "execution"
// 输出：5
// 解释：
// intention -> inention (删除 't')
// inention -> enention (将 'i' 替换为 'e')
// enention -> exention (将 'n' 替换为 'x')
// exention -> exection (将 'n' 替换为 'c')
// exection -> execution (插入 'u')


class Solution {
public:
  int minDistance(string word1, string word2) {
    // dp[i][j] word1[0, i]1转换为word2[0, j]所需的最小操作数
    // word1[0,i]指的是对word1取子串，索引是0 ~ i
    // 比如word1 = "abcd"，i == 2, 那么word1[0, 2] == "abc"
    int length1 = word1.size();
    int length2 = word2.size();
    // length + 1考虑了空字符串
    vector<vector<int>> dp(length1 + 1, vector<int>(length2 + 1, 0));
    
    for (int j = 0; j < length2 + 1; ++j) {
      dp[0][j] = j;
    }
    for (int i = 0; i < length1 + 1; ++i) {
      dp[i][0] = i;
    }
    for (int i = 1; i < length1 + 1; ++i) {
      for (int j = 1; j < length2 + 1; ++j) {
        if (word1[i - 1] != word2[j - 1]) {
          dp[i][j] = 1 + min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]);
        } else {
          dp[i][j] = dp[i - 1][j - 1];
        }
      }
    }
    return dp[length1][length2];
  }
};