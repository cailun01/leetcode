#include "headers.h"
// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。

// 示例:
// 输入:
// [
//   [1,3,1],
//   [1,5,1],
//   [4,2,1]
// ]
// 输出: 7
// 解释: 因为路径 1→3→1→1→1 的总和最小。

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		if (grid.empty() || grid[0].empty()) return 0;

		// 假设m>0, n>0
		int row = grid.size();
		int col = grid[0].size();

		//右下角坐标grid[row - 1][col - 1]
		// dp[i][j]表示坐标为i,j的最小路径和
		vector<vector<int>> dp(row, vector<int>(col, 0));
		dp[0][0] = grid[0][0];
		for (int i = 0; i < row; ++i) {
			for (int j = 0; j < col; ++j) {
				if (i >= 1 && j >= 1) {
					dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
				} else if (i >= 1) { // 只有一列
					dp[i][j] = dp[i - 1][j] + grid[i][j];
				} else if (j >= 1) { // 只有一行
					dp[i][j] = dp[i][j - 1] + grid[i][j];
				}
			}
		}
		return dp[row - 1][col - 1];
	}
};