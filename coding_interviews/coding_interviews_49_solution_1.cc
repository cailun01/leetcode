/* 剑指 Offer 49. 丑数
我们把只包含质因子 2、3 和 5 的数称作丑数（Ugly Number）。求按从小到大的顺序的第 n 个丑数。

示例:
输入: n = 10
输出: 12
解释: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 是前 10 个丑数。
说明:  
1 是丑数。
n 不超过1690。
注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/
*/

/* 
丑数是另一个丑数乘以2、3、5的结果（1除外）。我们可以创建一个数组，里面的数字是排序好的丑数，
每个丑数都是前面的丑数乘以2、3、5得到的。

思路的关键：确保数组的丑数是排好序的。假设数组中已经有若干排好序的丑数，
并且把已有的最大的丑数记做M，接下来分析如何生成下一个丑数。

该丑数一定是前面的某个丑数乘以2、3、5得到，所以首先考虑把已有的每个数乘以2，
在乘以2时，能得到若干小于或等于M的结果。由于是按照顺序生成的，小于或者等于M肯定已经在数组中了，
我们不需要再次考虑；还会得到大于M的结果，但是我们只需要第一个大于M的结果，
因为我们希望丑数是按从小到大的顺序生成的，其他更大的结果以后再说。
我们把得到的第一个乘以2后大于M的结果记为M2。同样，我们把已有的每个丑数乘以3和5，
能得到第一个大于M的结果M3和M5。那么下一个丑数应该是M2、M3和M5这3个数的最小者。

前面提到把已有的每个丑数分别乘以2、3和5。事实上这不是必需的，
因为已有的丑数是按顺序存放在数组中的。对于乘以2而言，肯定存在某个丑数T2，
排在它之前的每个丑数乘以2得到的结果都会小于已有最大的丑数，
在它之后的每个丑数乘以2得到的结果都会太大。我们只需要记下这个丑数的位置，
同时每次生成新的丑数的时候去更新这个T2即可。对于乘以3和5而言，也存在同样的T3和T5。
*/

class Solution {
public:
  int nthUglyNumber(int n) {
    if (n <= 5) {
      return n;
    }
    vector<int> ugly_number{1, 2, 3, 4, 5};
    int current_max_ugly = 5;
    size_t t2 = 0, t3 = 0, t5 = 0;
    while (ugly_number.size() < n) {
      for (; t2 < ugly_number.size(); ++t2) {
        if (ugly_number[t2] * 2 > current_max_ugly) {
          break;
        }
      }
      for (; t3 < ugly_number.size(); ++t3) {
        if (ugly_number[t3] * 3 > current_max_ugly) {
          break;
        }
      }
      for (; t5 < ugly_number.size(); ++t5) {
        if (ugly_number[t5] * 5 > current_max_ugly) {
          break;
        }
      }
      current_max_ugly = min(min(ugly_number[t2] * 2, ugly_number[t3] * 3), ugly_number[t5] * 5);
      ugly_number.push_back(current_max_ugly);
    }
    return ugly_number.back();
  }
};