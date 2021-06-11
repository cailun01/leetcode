#include "headers.h"
/* 7. 整数反转
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−2^31,  2^31 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 
示例 1：
输入：x = 123
输出：321

示例 2：
输入：x = -123
输出：-321

示例 3：
输入：x = 120
输出：21

示例 4：
输入：x = 0
输出：0
*/

/* 思路
本题如果不考虑溢出问题，是非常简单的。解决溢出问题有两个思路，第一个思路是通过字符串转换加try catch的方式来解决，
第二个思路就是通过数学计算来解决。
由于字符串转换的效率较低且使用较多库函数，所以解题方案不考虑该方法，而是通过数学计算来解决。
通过循环将数字x的每一位拆开，在计算新值时每一步都判断是否溢出。
溢出条件有两个，一个是大于整数最大值MAX_VALUE，另一个是小于整数最小值MIN_VALUE，设当前计算结果为rev，下一位为pop。
从rev * 10 + pop > MAX_VALUE这个溢出条件来看
  当出现 rev > MAX_VALUE / 10 且 还有pop需要添加 时，则一定溢出
  当出现 rev == MAX_VALUE / 10 且 pop > 7 时，则一定溢出，7是2^31 - 1的个位数
从ans * 10 + pop < MIN_VALUE这个溢出条件来看
  当出现 rev < MIN_VALUE / 10 且 还有pop需要添加 时，则一定溢出
  当出现 rev == MIN_VALUE / 10 且 pop < -8 时，则一定溢出，8是-2^31的个位数
*/


class Solution {
public:
  int reverse(int x) {
    int rev = 0;
    while (x != 0) {
      int pop = x % 10;
      x /= 10;
      if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && pop > 7))  { 
        return 0; 
      }
      if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && pop < -8)) { 
        return 0; 
      }
      rev = rev * 10 + pop;
    }
    return rev;
  }
};
