/* 96. 不同的二叉搜索树
给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。

示例 1：
输入：n = 3
输出：5

示例 2：
输入：n = 1
输出：1
*/

/* 左子树大于根节点，右子树小于根节点。
二叉搜索树的中序遍历是一个有序列表。 
*/

class Solution {
public:
  int numTrees(int n) {
    // dp[i]: 用连续的 i 个数，所构建出的 BST 种类数
    vector<int> dp(n + 1); 
    dp[0] = dp[1] = 1;//初始化
    dfs(n, dp);
    return dp[n]; 
  }
    
  int dfs(int n, vector<int>& dp){
    //如果已经算过的，直接返回 
    if (dp[n] != 0) { 
      return dp[n];
    }
    int ans = 0;
	  for (int j = 0; j < n; j++) {
      // 左子树用j个节点，右子树用n-j-1个节点，还剩一个数作根节点
      ans += dfs(j, dp) * dfs(n - j - 1, dp);//递归
	  }
    dp[n] = ans;//记忆
    return ans;
	} 
};