#include "headers.h"
/* 651 4键键盘
假设你有一个特殊的键盘包含下面的按键：
Key 1: (A)：在屏幕上打印一个 'A'。
Key 2: (Ctrl-A)：选中整个屏幕。
Key 3: (Ctrl-C)：复制选中区域到缓冲区。
Key 4: (Ctrl-V)：将缓冲区内容输出到上次输入的结束位置，并显示在屏幕上。
现在，你只可以按键 N 次（使用上述四种按键），请问屏幕上最多可以显示几个 'A'
样例 1:
输入: N = 3
输出: 3
解释: 
我们最多可以在屏幕上显示三个'A'通过如下顺序按键：
A, A, A
 
样例 2:
输入: N = 7
输出: 9
解释: 
我们最多可以在屏幕上显示九个'A'通过如下顺序按键：
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V
 
注释:
1 <= N <= 50
结果不会超过 32 位有符号整数范围。
*/

class Solution {
public:
  int maxA(int N) {
    // dp[i] 按键i次后，A的数量
    vector<int> dp(N + 1);
    dp[0] = 0;
    for (int i = 1; i < N + 1; ++i) {
      dp[i] = dp[i - 1] + 1; // 一直按 'A' 这个键
      for (int j = 2; j < i; ++j) {
        // 假设已有m个'A', 先全选、再复制(按键2次)，然后粘贴k次
        // j 代表ctrl-v的起点，之前有了dp[j - 2]个'A'
        // 粘贴i - j次，最后有 dp[j - 2] * (i - j + 1)个'A'
        dp[i] = max(dp[i], dp[j - 2] * (i - j + 1));
      }
    }
    return dp[N];
  }
};