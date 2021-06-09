class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if(s1 == s2) { 
        return true; 
      }
    	if(s1.size() != s2.size()) { 
        return false; 
      }

    	int n = s1.size();
      // dp[i][j][len] 代表s1从i开始，s2从j开始，后面长度为len的字符是否能形成「扰乱字符串」（互为翻转）。
    	vector<vector<vector<bool>>> dp(n, vector<vector<int>>(n, vector<int>(n+1, 0)));

    	// 先处理长度为 1 的情况
    	for(int i = 0; i < n; i++) {
    		for(int j = 0; j < n; j++) {
    			if(s1[i] == s2[j]) {
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
