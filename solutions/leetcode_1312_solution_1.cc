/*
如果s[i] == s[j]的话，我们不需要进行任何插入，只要知道如何把s[i+1..j-1]变成回文串即可。
如果s[i] != s[j]
步骤一，做选择，先将s[i..j-1]或者s[i+1..j]变成回文串。
步骤二，根据步骤一的选择，将s[i..j]变成回文。
如果你在步骤一中选择把s[i+1..j]变成回文串，那么在s[i+1..j]右边插入一个字符s[i]一定可以将s[i..j]变成回文；
同理，如果在步骤一中选择把s[i..j-1]变成回文串，在s[i..j-1]左边插入一个字符s[j]一定可以将s[i..j]变成回文。
*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        // 定义：对 s[i..j]，最少需要插入 dp[i][j] 次才能变成回文
        vector<vector<int>> dp(n, vector<int>(n, 0));
        // base case：i == j 时 dp[i][j] = 0，单个字符本身就是回文
        // dp 数组已经全部初始化为 0，base case 已初始化

        // 从下向上遍历
        for (int i = n - 2; i >= 0; i--) {
            // 从左向右遍历
            for (int j = i + 1; j < n; j++) {
                // 根据 s[i] 和 s[j] 进行状态转移
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i + 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
                }
            }
        }
        // 根据 dp 数组的定义，题目要求的答案
        return dp[0][n - 1];
    }

};