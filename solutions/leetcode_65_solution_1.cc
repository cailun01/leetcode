/* 65. 有效数字
有效数字（按顺序）可以分成以下几个部分：

一个 小数 或者 整数
（可选）一个 'e' 或 'E' ，后面跟着一个 整数
小数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
下述格式之一：
至少一位数字，后面跟着一个点 '.'
至少一位数字，后面跟着一个点 '.' ，后面再跟着至少一位数字
一个点 '.' ，后面跟着至少一位数字
整数（按顺序）可以分成以下几个部分：

（可选）一个符号字符（'+' 或 '-'）
至少一位数字
部分有效数字列举如下：

["2", "0089", "-0.1", "+3.14", "4.", "-.9", "2e10", "-90E3", "3e+7", "+6e-1", "53.5e93", "-123.456e789"]
部分无效数字列举如下：

["abc", "1a", "1e", "e3", "99e2.5", "--6", "-+3", "95a54e53"]
给你一个字符串 s ，如果 s 是一个 有效数字 ，请返回 true 。


示例 1：

输入：s = "0"
输出：true

示例 2：
输入：s = "e"
输出：false

示例 3：
输入：s = "."
输出：false

示例 4：
输入：s = ".1"
输出：true
*/

/*
分了三步来处理。
第一步trim，即去除头尾的空格；
第二步划分，找出字符e划分为底数和指数两部分；
第三步判断底数和指数是否有效，若没有指数则指判断底数，显然指数只能包含符号和整数、而底数只能包含符号、小数点和数字。
*/

class Solution {
public:
  bool isNumber(string s) {   
    int first_not_space = s.find_first_not_of(' ');
    int last_not_space = s.find_last_not_of(' ');
    s = s.substr(first_not_space, last_not_space - first_not_space + 1);
    
    if(s.size() == 0) { 
      return false; 
    }
    
    // 寻找e或E
    int e_idx = 0;
    for (;e_idx < s.size(); ++e_idx) {
      if (s[e_idx] == 'e' || s[e_idx] == 'E') {
        break;
      }
    }
    if (e_idx != 0 && e_idx < s.size()) {    
      return check_base(s.substr(0, e_idx)) // 判断底数
          && check_exp(s.substr(e_idx + 1));// 判断指数
    } else { 
      return check_base(s); 
    }
  }
  // 判断底数 
  bool check_base(string s) {
    bool res = false; 
    bool pointed = false;
    for (int i = 0; i < s.size(); i++) {
      if(s[i] == '+' || s[i] == '-') {
        if(i != 0) {
          // +或-只能出现在第一位
          return false;
        }
      } else if (s[i] == '.') {
        if (pointed) {
          // 只能有一个小数点
          return false; 
        }
        pointed = true;
      } else if (s[i] < '0' || s[i] > '9')  {
        return false;
      } else { 
        res = true; 
      }
    }
    return res;
  }
  // 判断指数
  bool check_exp(string s) {
    bool res = false;
    for (int i = 0; i < s.size(); i++) {
      if(s[i] == '-' || s[i] == '+') {
        if(i != 0) { 
          return false; 
        }
      } else if(s[i] < '0' || s[i] > '9') { 
        return false; 
      } else { 
        res = true; 
      }
    }
    return res;
  }
};
