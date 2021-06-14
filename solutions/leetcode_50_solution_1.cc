/* 50. Pow(x, n)
实现 pow(x, n) ，即计算 x 的 n 次幂函数（即，xn）。

示例 1：
输入：x = 2.00000, n = 10
输出：1024.00000

示例 2：
输入：x = 2.10000, n = 3
输出：9.26100

示例 3：
输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25
*/

// 快速幂
class Solution {
public:
  double quickMul(double x, long long N) {
    if (N == 0) {
      return 1.0;
    }

    if (N % 2 == 0) {
      double sub = quickMul(x, N / 2);
      return sub * sub;
    } else {
      return x * quickMul(x, N - 1);
    }
  }

  double myPow(double x, int n) {
    long long N = n;
    return N >= 0 ? quickMul(x, N) : 1.0 / quickMul(x, -N);
  }
};
