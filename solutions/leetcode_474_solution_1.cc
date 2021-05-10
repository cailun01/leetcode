class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int num_strs = strs.size();
        // dp 取前i个字符串时，有j个0和k个1时，最大子集的大小
        vector<vector<vector<int>>> dp(num_strs + 1, 
            vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
        for (int i = 1; i <= num_strs; ++i) {
            auto num_zeros_and_ones = count_zeros_and_ones(strs[i - 1]);
            int num_zeros = std::get<0>(num_zeros_and_ones);
            int num_ones = std::get<1>(num_zeros_and_ones);
            for (int j = 0; j <= m; ++j) {
                for (int k = 0; k <= n; ++k) {
                    if (num_zeros > j || num_ones > k) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    } else {
                        dp[i][j][k] = max(dp[i - 1][j][k],
                            dp[i - 1][j - num_zeros][k - num_ones] + 1);
                    }
                }
            }
        }
        return dp[num_strs][m][n];
    }

    tuple<int, int> count_zeros_and_ones(string str) {
        int num_zeros = 0, num_ones = 0;
        for (const auto& c : str) {
            if (c == '0') {
                num_zeros++;
            } else if (c == '1') {
                num_ones++;
            }
        }
        return std::make_tuple(num_zeros, num_ones);
    }
};