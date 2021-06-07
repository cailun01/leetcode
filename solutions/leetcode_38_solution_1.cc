/* 解释题意：
1
11
21
1211
111221

一步一步来
给一个数，这个数是1
描述上一步的数，这个数是 1 即一个1，故写作11
描述上一步的数，这个数是11即两个1，故写作21
描述上一步的数，这个数是21即一个2一个1，故写作12-11
描述上一步的数，这个数是1211即一个1一个2两个1，故写作11-12-21
*/

/*思路：
比较相邻两个数是否相同，进而决定是移动下标，还是描述该项内容。

变量名含义:
re（result）：最后的结果
current：当前的结果

非递归解法

对re进行遍历
此时有count=1 个re[i]
继续在里面进行遍历查看是否后面是是否还有与re[i]相同的值（即数有几个re[i])
有则将count++
数完之后将几个re[i]连接到current 之后
最后将current赋给re并进行下一次循环
因为已经知道了第一项所以直接将n-1, 只需循环n-1次


https://leetcode-cn.com/problems/count-and-say/solution/cjie-fa-di-gui-yu-fei-di-gui-xiang-xi-ti-ujlu/
*/

class Solution {
public:
  string countAndSay(int n) {
    if(n == 0)  return "";
    string re = "1";
    while(--n) {
      string current = "";
      for (int i = 0;i < re.size(); ++i) {
        char cur = re[i];
        int count = 1;
        //继续在里面进行遍历查看是否后面还有与`re[i]`相同的值（即数有几个re[i])
        while(i < re.size() && cur == re[i+1]){
          ++i;
          ++count;
        }
        current += to_string(count) + cur;
      }
      re = current;
    }
    return re;
  }
};
