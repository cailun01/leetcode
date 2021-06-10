
/*
https://leetcode-cn.com/problems/wildcard-matching/solution/yi-ge-qi-pan-kan-dong-dong-tai-gui-hua-dpsi-lu-by-/
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        // s和p之后各加一个a，处理s是空串，p全是*的情况。
        s = s + 'a';
        p = p + 'a';
        int slen = s.size(), plen = p.size();
        vector<vector<bool>> dp(plen + 1, vector<bool>(slen+1));
        dp[0][0]=1;
        for (int i = 1;i <= plen; ++i) {
          bool has_asterisk = false;
          for (int j = 1; j <= slen; ++j){
            if (p[i - 1] == '*' && dp[i - 1][j - 1]) {
              has_asterisk = true;
              dp[i][j - 1] = 1;
            } else if (p[i - 1] == '?' || s[j - 1] == p[i - 1]) {
              dp[i][j] = dp[i - 1][j - 1];
            }
            if (has_asterisk == true) {
              dp[i][j] = true;
            }
          }
        }
        return dp[plen][slen];
    }
};