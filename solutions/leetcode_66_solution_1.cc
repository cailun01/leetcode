/* 66. 加一
给定一个由 整数 组成的 非空 数组所表示的非负整数，在该数的基础上加一。
最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。 

示例 1：
输入：digits = [1,2,3]
输出：[1,2,4]
解释：输入数组表示数字 123。

示例 2：
输入：digits = [4,3,2,1]
输出：[4,3,2,2]
解释：输入数组表示数字 4321。

示例 3：
输入：digits = [0]
输出：[1]
*/

class Solution {
public:
  vector<int> plusOne(vector<int>& digits) {
    int size = digits.size();
    for (int i = size - 1; i >= 0; --i) {
      digits[i] += 1;
      digits[i] %= 10;
      // 上面对10取模，如果取模后digits[i]!=0，说明取模前digits[i]<=9，无需进位，直接返回
      if (digits[i] != 0) {
        return digits;
      }
      // 如果取模后digits[i]==0，说明取模前digits[i]==10，需要进位，在下一次for循环的
      // digits[i] += 1会实现进位。
    }
    // 这个for循环结束后没有返回，说明一直需要进位，digits其中的元素全是9
    // 我们只需返回比digits的size大1的数组，开头为1，其余为0即可。
    // 比如 digits = [9,9]，返回[1,0,0]
    vector<int> res(size + 1, 0);
    res[0] = 1;
    return res;
  }
};
