class Solution {
public:
    bool isScramble(string s1, string s2) {
    	if(s1 == s2) return true;
    	if(s1.size() != s2.size()) return false;

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

    	// 再处理其余长度情况
    	for (int len = 2; len <= n; len++) {
    		for (int i = 0; i + len <= n; i++) {
    			for (int j = 0; j + len <= n; j++) {
    				for (int k = 1; k < len; k++) {
              // 对应了「s1 的 [0, k) & [k, n)」匹配「s2 的 [0, k) & [k, n)」
    					bool a = dp[i][j][k] && dp[i + k][j + k][len - k];
              // 对应了「s1 的 [0,k) & [i,n)」匹配「s2 的 [n-k, n) & [0,n - k)」
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
