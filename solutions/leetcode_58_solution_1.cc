/* 58. 最后一个单词的长度
给你一个字符串 s，由若干单词组成，单词之间用空格隔开。返回字符串中最后一个单词的长度。
如果不存在最后一个单词，请返回 0 。

单词 是指仅由字母组成、不包含任何空格字符的最大子字符串。

示例 1：
输入：s = "Hello World"
输出：5

示例 2：
输入：s = " "
输出：0
*/

/*
倒序遍历每一个字符，遇到第一个字母时，把meet_a_letter设置为true。再遇到空格，停止循环。
*/
class Solution {
public:
  int lengthOfLastWord(string s) {
    int size = s.size();
    if (size == 0) {
      return 0;
    }
    bool meet_a_letter = false;
    int length = 0;
    for (int i = size - 1; i >= 0; --i) {
      if (isalpha(s[i])) {
        meet_a_letter = true;
        length++;
      } else if (s[i] == ' ') {
        if (meet_a_letter) {
          break;
        }
      }
    }
    return length;
  }
};
