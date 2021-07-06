/* 69 x的平方根
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