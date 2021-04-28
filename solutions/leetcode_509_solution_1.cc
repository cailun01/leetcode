#include "headers.h"
// 斐波那契数，通常用 F(n) 表示，形成的序列称为斐波那契数列。
// 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
// F(0) = 0,   F(1) = 1
// F(N) = F(N - 1) + F(N - 2), 其中 N > 1.
// 给定 N，计算 F(N)。


// 带备忘录的递归
class Solution {
public:
  int fib(int N) {
    if (N == 0 || N == 1) return N;
    if (N == 2) return 1;
    vector<int> memo(N + 1, 0);
    return helper(N, memo);
  }
  int helper(int n, vector<int>& memo) {
    if (n == 1 || n == 2) return 1;
    if (memo[n] != 0) {
      return memo[n];
    } else {
      memo[n] = helper(n - 1, memo) + helper(n - 2, memo);
      return memo[n];
    }
  }
};