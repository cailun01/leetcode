#include "headers.h"
/* 8. 字符串转换整数 (atoi)
请你来实现一个myAtoi(string s)函数，使其能将字符串转换成一个32位有符号整数（类似C/C++中的atoi函数）。

函数 myAtoi(string s) 的算法如下：

+ 读入字符串并丢弃无用的前导空格。
+ 检查下一个字符（假设还未到字符末尾）为正还是负号，读取该字符（如果有）。
  确定最终结果是负数还是正数。 如果两者都不存在，则假定结果为正。
+ 读入下一个字符，直到到达下一个非数字字符或到达输入的结尾。字符串的其余部分将被忽略。
+ 将前面步骤读入的这些数字转换为整数（即，"123" -> 123， "0032" -> 32）。
  如果没有读入数字，则整数为 0 。必要时更改符号（从步骤 2 开始）。
+ 如果整数数超过 32 位有符号整数范围 [−2^31,  2^31 − 1] ，需要截断这个整数，
  使其保持在这个范围内。具体来说，小于−2^31的整数应该被固定为−2^31，大于2^31−1的整数应该被固定为2^31−1。
+ 返回整数作为最终结果。

注意：

本题中的空白字符只包括空格字符 ' ' 。
除前导空格或数字后的其余字符串外，请勿忽略 任何其他字符。
*/


/*
思路：
字符串索引i从0开始，遇到空格向右移动，直到遇到非空格。
如果遇到符号，设置flag。

在下面的while循环中：
  因为每一步都要执行res = res * 10 + r;
  所以res * 10不能大于INT_MAX，即res要小于INT_MAX / 10
  INT_MAX = 2^31 -1 = 2147483647
  如果res恰好等于INT_MAX / 10(214748364) ，那么r 必须小于等于7
  while(i < str.size() && isdigit(str[i])) { 
      if(res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))  {
        return flag > 0 ? INT_MAX : INT_MIN;
      }
      res = res * 10 + r;
      i++;
  }
*/

class Solution {
public:
  int myAtoi(string str) {
    // i 是每个字符在字符串中的位置。
    int res = 0, i = 0; 
    int flag = 1; // 判断符号
    // 遇到空字符，则寻找下一个字符。
    while(str[i] == ' ') {
      i++;
    }
    
    if(str[i] == '-') { 
      flag = -1; 
    }
    if(str[i] == '+' || str[i] == '-') { 
      i++; 
    }
    while(i < str.size() && isdigit(str[i])) { 
      //遇到第1个不是数字的字符的情况下，就得退出循环；
      int r = str[i] - '0';
      if(res > INT_MAX / 10 || (res == INT_MAX / 10 && r > 7))  {
        return flag > 0 ? INT_MAX : INT_MIN;
      }
      res = res * 10 + r;
      i++;
    }
    return flag > 0 ? res : -res;
  }
};
