/* 87. 扰乱字符串
 使用下面描述的算法可以扰乱字符串 s 得到字符串 t ：
如果字符串的长度为 1 ，算法停止
如果字符串的长度 > 1 ，执行下述步骤：
在一个随机下标处将字符串分割成两个非空的子字符串。即，如果已知字符串 s ，
则可以将其分成两个子字符串 x 和 y ，且满足 s = x + y 。
随机 决定是要「交换两个子字符串」还是要「保持这两个子字符串的顺序不变」。
即，在执行这一步骤之后，s 可能是 s = x + y 或者 s = y + x 。
在 x 和 y 这两个子字符串上继续从步骤 1 开始递归执行此算法。
给你两个 长度相等 的字符串 s1 和 s2，判断 s2 是否是 s1 的扰乱字符串。如果是，返回 true ；否则，返回 false 。

示例 1：
输入：s1 = "great", s2 = "rgeat"
输出：true
解释：s1 上可能发生的一种情形是：
"great" --> "gr/eat" // 在一个随机下标处分割得到两个子字符串
"gr/eat" --> "gr/eat" // 随机决定：「保持这两个子字符串的顺序不变」
"gr/eat" --> "g/r / e/at" // 在子字符串上递归执行此算法。两个子字符串分别在随机下标处进行一轮分割
"g/r / e/at" --> "r/g / e/at" // 随机决定：第一组「交换两个子字符串」，第二组「保持这两个子字符串的顺序不变」
"r/g / e/at" --> "r/g / e/ a/t" // 继续递归执行此算法，将 "at" 分割得到 "a/t"
"r/g / e/ a/t" --> "r/g / e/ a/t" // 随机决定：「保持这两个子字符串的顺序不变」
算法终止，结果字符串和 s2 相同，都是 "rgeat"
这是一种能够扰乱 s1 得到 s2 的情形，可以认为 s2 是 s1 的扰乱字符串，返回 true

示例 2：
输入：s1 = "abcde", s2 = "caebd"
输出：false

示例 3：
输入：s1 = "a", s2 = "a"
输出：true
*/

/*
两个题解：
https://leetcode-cn.com/problems/scramble-string/solution/miao-dong-de-qu-jian-xing-dpsi-lu-by-sha-yu-la-jia/
https://leetcode-cn.com/problems/scramble-string/solution/gong-shui-san-xie-yi-ti-san-jie-di-gui-j-hybk/
*/
class Solution {
public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2) { 
      return true; 
    }
    if (s1.size() != s2.size()) { 
      return false; 
    }

    int n = s1.size();
    // dp[i][j][len] 代表s1从i开始，s2从j开始，后面长度为len的字符是否能形成「扰乱字符串」（互为翻转）。
    vector<vector<vector<bool>>> dp(n, vector<vector<bool>>(n, vector<bool>(n+1, false)));

    // 先处理长度为 1 的情况
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (s1[i] == s2[j]) {
          dp[i][j][1] = true;
        }
      }
    }
    // 假设划分后，s1的两个子串是s1_sub1和s1_sub2。s2的两个子串为s2_sub1和s2_sub2

    // 再处理其余长度情况
    for (int len = 2; len <= n; len++) {
      for (int i = 0; i + len <= n; i++) {
        for (int j = 0; j + len <= n; j++) {
          // 枚举划分位置k
          for (int k = 1; k < len; k++) {
            // s1_sub1匹配s2_sub1, s1_sub2匹配s2_sub2。
            bool a = dp[i][j][k] && dp[i + k][j + k][len - k];
            // s1_sub1匹配s2_sub2, s1_sub2匹配s2_sub1。
            // s1_sub1起点i，s2_sub2起点 j + 前面那段长度len-k，s1_sub2起点i+前面长度k
            bool b = dp[i][j + len - k][k] && dp[i + k][j][len - k];
            if(a || b) {
              dp[i][j][len] = true;
            }
          }
        }
      }
    }
    return dp[0][0][n];
  }
};
