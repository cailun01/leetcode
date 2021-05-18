/*
给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。

示例 1:
输入: num1 = "2", num2 = "3"
输出: "6"

示例 2:
输入: num1 = "123", num2 = "456"
输出: "56088"
说明：

num1 和 num2 的长度小于110。
num1 和 num2 只包含数字 0-9。
num1 和 num2 均不以零开头，除非是数字 0 本身。
不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
*/

class Solution {
public:
    string multiply(string num1, string num2) {
        // base case
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        int len1 = num1.size();
        int len2 = num2.size();
        // 结果最多为m + n位数
        vector<int> res(len1 + len2, 0);
        // 两个指针i, j分别指向num1和num2，i == 0时，指向num1最大位的数字(最左侧数字)
        // 从个位数开始逐位相乘
        for (int i = len1 - 1; i >= 0; i--) {
            for (int j = len2 - 1; j >= 0; j--) {
                int product = (num1[i] - '0') * (num2[j] - '0');
                // 乘积在res对应的索引位置
                // tens_place十位，ones_place个位
                int tens_place = i + j, ones_place = i + j + 1;
                int sum = product + res[ones_place];
                res[ones_place] = sum % 10;
                res[tens_place] += sum / 10;
            }
        }
        // 计算结果的左侧可能存在0（未使用的位），使not_zero指向第一个不是0的位置
        auto not_zero = find_if(res.begin(), res.end(), [](int i){ return i != 0; });
        string str;
        for (; not_zero != res.end(); ++not_zero) {
            str.push_back('0' + *not_zero);
        }
        return str.size() == 0 ? "0" : str;
    }
};
