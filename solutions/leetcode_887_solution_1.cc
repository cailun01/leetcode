/* 887 鸡蛋掉落
给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。
已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，
从 f 楼层或比它低的楼层落下的鸡蛋都不会破。
每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下（满足 1 <= x <= n）。
如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中 重复使用 这枚鸡蛋。
请你计算并返回要确定 f 确切的值 的 最小操作次数 是多少？
 
示例 1：
输入：k = 1, n = 2
输出：2
解释：
鸡蛋从 1 楼掉落。如果它碎了，肯定能得出 f = 0 。 
否则，鸡蛋从 2 楼掉落。如果它碎了，肯定能得出 f = 1 。 
如果它没碎，那么肯定能得出 f = 2 。 
因此，在最坏的情况下我们需要移动 2 次以确定 f 是多少。

示例 2：
输入：k = 2, n = 6
输出：3

示例 3：
输入：k = 3, n = 14
输出：4
*/

class Solution {
public:
  int superEggDrop(int K, int N) {
    vector<vector<int>> memo(K + 1, vector<int>(N + 1, -1));
    return dp(K, N, memo);
  }
  // 当前状态为 K 个鸡蛋，面对 N 层楼（这里N不表示高度）
  int dp(int K, int N, vector<vector<int>>& memo) {
    if (K == 1) return N;
    if (N == 0) return 0;
    if (memo[K][N] != -1) { 
      return memo[K][N]; 
    }
    int res = numeric_limits<int>::max();
    int low = 1, high = N;
    while (low <= high) {
      int mid = (low + high) / 2;
      int broken = dp(K - 1, mid - 1, memo); // 单调递增
      int not_broken = dp(K, N - mid, memo); // 单调递减
      if (broken > not_broken) {
        high = mid - 1;
        res = min(res, broken + 1); // + 1指的是在第 i 楼扔了一次
      } else {
        low = mid + 1;
        res = min(res, not_broken + 1);
      }
    }
    memo[K][N] = res;
    return res;
  }
};
