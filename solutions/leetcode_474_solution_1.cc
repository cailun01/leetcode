/*
题目：
给你一个二进制字符串数组 strs 和两个整数 m 和 n 。
请你找出并返回 strs 的最大子集的大小，该子集中最多有 m 个 0 和 n 个 1 。
如果 x 的所有元素也是 y 的元素，集合 x 是集合 y 的 子集 。


示例 1：
输入：strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
输出：4
解释：最多有 5 个 0 和 3 个 1 的最大子集是 {"10","0001","1","0"} ，因此答案是 4 。
其他满足题意但较小的子集包括 {"0001","1"} 和 {"10","1","0"} 。
{"111001"} 不满足题意，因为它含 4 个 1 ，大于 n 的值 3 。

示例 2：
输入：strs = ["10", "0", "1"], m = 1, n = 1
输出：2
解释：最大的子集是 {"0", "1"} ，所以答案是 2 
*/
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
          // 当前容量装不下
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