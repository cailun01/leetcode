/* 67. 二进制求和
给你两个二进制字符串，返回它们的和（用二进制表示）。

输入为 非空 字符串且只包含数字 1 和 0。

示例 1:

输入: a = "11", b = "1"
输出: "100"
示例 2:

输入: a = "1010", b = "1011"
输出: "10101"
*/

/* 
从右至左遍历两个字符串，按位相加，到新的字符串builder，最后反转builder。
carry表示进位：
to add a number to the next column on the left when adding up numbers, 
for example when the numbers add up to more than ten
*/

class Solution {
public:
  string addBinary(string a, string b) {
    int i = a.length() - 1;
    int j = b.length() - 1;
    int carry = 0; // carry有“进位”的意思
    string builder;
    //循环相加两个字符串相同长度的低位数部分
    while (i >= 0 && j >= 0) {
      int sum = carry;
      sum += a.at(i--) - '0';
      sum += b.at(j--) - '0';
      carry = sum / 2; //是否进位
      builder += to_string((sum % 2));
    }
    // 如果 a 还没遍历完成（a串比b串长），则继续遍历添加 a 的剩余部分
    while (i >= 0) {
      int sum = carry + a.at(i--) - '0';
      carry = sum / 2;
      builder += to_string(sum % 2);
    }
    // 如果 b 还没遍历完成（b串比a串长），则继续遍历添加 b 的剩余部分
    while (j >= 0) {
      int sum = carry + b.at(j--) - '0';
      carry = sum / 2;
      builder += to_string(sum % 2);
    }
    //如果 carry 不等于0 还有个进位数没加进去，需要补充
    if (carry == 1) {
      builder += to_string(carry);
    }
    // 反转字符串获得正常结果
    reverse(builder.begin(), builder.end());
    return builder;
  }
};