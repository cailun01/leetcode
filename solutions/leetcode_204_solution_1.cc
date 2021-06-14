/* 204 计算质数
统计所有小于非负整数 n 的质数的数量。

示例 1：

输入：n = 10
输出：4
解释：小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
示例 2：

输入：n = 0
输出：0
示例 3：

输入：n = 1
输出：0
*/
class Solution {
public:
  int countPrimes(int n) {
    if (n == 0 || n == 1) {
      return 0;
    }
    vector<bool> is_prime(n, true);
    // 0和1都不是质数
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < n; ++i) {
      if (is_prime[i]) {
        // i是质数，i的倍数不可能是质数了
        for (int j = i * i; j < n; j += i) {
          /* i=4时算法会标记4*2=8，4*3=12等等数字，
          但是8和12已经被i = 2和i = 3的 2*4 和 3*4 标记过了。
          所以直接从4*4开始标记
          */
          is_prime[j] = false;
        }
      }
    }

    int num_primes = std::count(is_prime.begin(), is_prime.end(), true);
    return num_primes;
  }
};