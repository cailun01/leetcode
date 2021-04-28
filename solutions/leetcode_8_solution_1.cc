#include "headers.h"

// 字符减去'0'
// 现在比如我们要字符‘1’转换成数字1，它们在计算机中都以各自的ASCII表示。
// 而‘1’的对应编码是49的二进制码，但是我们的数字1，就等于1呀，所以为了由原来的‘1’实际上
// 就是49的二进制变成现在的1对应的二进制1，只好用49-48=1了。
// 但是在ASCII码里‘0’对应的刚好是48的二进制码，所以我们转换的时候只需要‘1’-‘0’=1就可以了。
// 大小写字母的转换：先看ASCII码：a~z是97~122的二进制，而A~Z是65~90的二进制编码，
// 于是我们就得出：大写字母=小写字母-32 ；这个公式了。当然这里的32我也可以这么写‘Z’=‘z’-'空格'。
// 因为空格的ASCII码是32对应的二进制编码。



class Solution {
public:
    int myAtoi(string str) {
        int res = 0, i = 0; // i 是每个字符在字符串中的位置。
        int flag = 1; // 判断符号
        // 遇到空字符，则寻找下一个字符。
        while(str[i] == ' ') {
          i++;
        }
        
        if(str[i] == '-') flag = -1; 
        if(str[i] == '+' || str[i] == '-') i++; 
        while(i < str.size() && isdigit(str[i])) { //遇到第1个不是数字的字符的情况下，就得退出循环；
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