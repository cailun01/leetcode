/* 415. 字符串相加
给定两个字符串形式的非负整数 num1 和num2 ，计算它们的和。

提示：

num1 和num2 的长度都小于 5100
num1 和num2 都只包含数字 0-9
num1 和num2 都不包含任何前导零
你不能使用任何內建 BigInteger 库， 也不能直接将输入的字符串转换为整数形式
*/

class Solution {
public:
  string addStrings(string num1, string num2) {
    int len1 = num1.size();
    int len2 = num2.size();
    string res;
    int carry = 0;
    int i = len1 - 1;
    int j = len2 - 1;
    while (i >= 0 || j >= 0) {
      int sum = carry + (i >= 0 ? num1[i] - '0' : 0) + (j >= 0 ? num2[j] - '0' : 0);
      int val = sum % 10;
      res += to_string(val);
      carry = sum / 10;
      --i, --j;
    }
    if (carry > 0) {
      res += to_string(carry);
    }
    reverse(res.begin(), res.end());
    return res;
  }
};