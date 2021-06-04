class Solution {
public:
  int subDivide(int dividend, int divisor, bool negative) {
    int i = 0, times = 1;
    int originDivisor = divisor;
    while (dividend <= divisor && dividend <= 0) {
      dividend -= divisor;
      i += times;           
      if (dividend >= divisor) {
        break;
      }
      // 自增翻倍，加快减法速度
      divisor += divisor;
      times += times;
    }

    if (dividend > originDivisor) {
      if (negative) {
        return -i;
      } else {
        return i;
      }
    } else {
      if (negative) {
        return -i + subDivide(dividend, originDivisor, negative);
      } else {
        return i + subDivide(dividend, originDivisor, negative);
      }
    }
  }

  int divide(int dividend, int divisor) {
    int i = 0, times = 1, left = 0;
    bool negative = false;
    
    if (dividend == INT_MIN) {
      if (divisor == -1) {
        return INT_MAX;
      } else if (divisor == 1) {
        return INT_MIN;
      } else if (divisor == INT_MIN) {
        return 1;
      }
    }
    if (divisor == INT_MIN) {
      return 0;
    }
    if (divisor == 1) {
        return dividend;
    }
    if (divisor == -1) {
        return -dividend;
    }

    // 把所有正数转换为负数
    if (dividend < 0 && divisor > 0) {
      negative = true;
      divisor = -divisor;
    }
    else if (dividend > 0 && divisor < 0) {
      negative = true;
      dividend = -dividend;
    }
    else if (dividend > 0 && divisor > 0) {
       divisor = -divisor;
      dividend = -dividend;                        
    }
    return subDivide(dividend, divisor, negative);
  }
};
