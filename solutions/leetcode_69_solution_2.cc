/* 69 x的平方根
实现 int sqrt(int x) 函数。

计算并返回 x 的平方根，其中 x 是非负整数。

由于返回类型是整数，结果只保留整数的部分，小数部分将被舍去。

示例 1:

输入: 4
输出: 2
示例 2:

输入: 8
输出: 2
说明: 8 的平方根是 2.82842..., 
     由于返回类型是整数，小数部分将被舍去。
*/

/*
牛顿迭代法：
求p的平方根
https://blog.csdn.net/yohjob/article/details/92024963
xn+1 = xn - (xn^2 - p) / (2 * xn) = (xn^2 + p) / (2 * xn) = (xn + p / xn) / 2
*/
class Solution {
public:
  int mySqrt(int x) {
    if(x == 0 || x == 1) { 
      return x; 
    }
    double res = 1;
    while(fabs(res * res - x) > 0.1){
      res = (res + x / res) / 2;
    }
    return int(res);
  }
};