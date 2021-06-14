/* 372. 超级次方
你的任务是计算 a^b 对 1337 取模，a 是一个正整数，b 是一个非常大的正整数且会以数组形式给出。

示例 1：
输入：a = 2, b = [3]
输出：8

示例 2：
输入：a = 2, b = [1,0]
输出：1024

示例 3：
输入：a = 1, b = [4,3,3,8,5,2]
输出：1

示例 4：
输入：a = 2147483647, b = [2,0,0]
输出：1198
*/

class Solution {
public:
  int base = 1337;

  int mypow(int a, int k) {
    if (k == 0) return 1;
    a %= base;

    if (k % 2 == 1) {
      // k 是奇数
      return (a * mypow(a, k - 1)) % base;
    } else {
      // k 是偶数
      int sub = mypow(a, k / 2);
      return (sub * sub) % base;
    }
  }

  int superPow(int a, vector<int>& b) {
    // 递归的 base case
    if (b.empty()) { 
      return 1; 
    }
    // 取出最后一个数
    int last = b.back();
    b.pop_back();
    // 将原问题化简，缩小规模递归求解
    int part1 = mypow(a, last);
    int part2 = mypow(superPow(a, b), 10);
    // 合并出结果
    return part1 * part2 % base;
  }
};
