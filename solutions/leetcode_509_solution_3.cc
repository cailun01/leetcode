#include "headers.h"
// 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。
// 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 给定 N，计算 F(N)。


// 动态规划，优化空间复杂度
class Solution {
public:
  int fib(int N) {
    if (N == 0 || N == 1) return N;
    if (N == 2) return 1;
    int curr = 1, prev = 0;
    int sum = 0;
    for (int n = 2; n < N + 1; ++n) {
      // curr: dp[n - 1], prev: dp[n - 2] 
      sum = curr + prev;
      prev = curr;
      curr = sum;
    }
    return sum;
  }
};