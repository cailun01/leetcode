/* 752 打开转盘索
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。

锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。


示例 1:
输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。

示例 2:
输入: deadends = ["8888"], target = "0009"
输出：1
解释：
把最后一位反向旋转一次即可 "0000" -> "0009"。

示例 3:
输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：
无法旋转到目标数字且不被锁定。

示例 4:
输入: deadends = ["0000"], target = "8888"
输出：-1
 
提示：
死亡列表 deadends 的长度范围为 [1, 500]。
目标数字 target 不会在 deadends 之中。
每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
*/

class Solution {
public:
  string plus_one(string s, int j) {
    char& current_char = s[j];
    if (current_char == '9') {
      current_char = '0';
    } else {
      int integer = current_char - '0';
      integer += 1;
      current_char = integer + '0';
    }
    return s;
  }

  string minus_one(string s, int j) {
    char& current_char = s[j];
    if (current_char == '0') {
      current_char = '9';
    } else {
      int integer = current_char - '0';
      integer -= 1;
      current_char = integer + '0';
    }
    return s;
  }

  int openLock(vector<string>& deadends, string target) {
    // 记录需要跳过的死亡密码
    set<string> deads;
    for (auto s : deadends) {
      deads.insert(s);
    }
    // 记录已经穷举过的密码，防止走回头路
    set<string> visited;
    queue<string> q;
    // 从起点开始启动广度优先搜索
    int step = 0;
    q.push("0000");
    visited.insert("0000");
    while(!q.empty()) {
      int size = q.size();
      /* 将当前队列中的所有节点向周围扩散 */
      for (int i = 0; i < size; ++i) {
        string cur = q.front();
        q.pop();
        /* 判断是否到达终点 */
        if (deads.find(cur) != deads.end()) {
          continue;
        }
        if (cur == target) {
          return step;
        }
        /* 将一个节点的未遍历相邻节点加入队列 */
        for (int j = 0; j < 4; ++j) {
          string up = plus_one(cur, j);
          if (visited.find(up) == visited.end()) {
            q.push(up);
            visited.insert(up);
          }
          string down = minus_one(cur, j);
          if (visited.find(down) == visited.end()) {
            q.push(down);
            visited.insert(down);
          }
        }
      }
      /* 在这里增加步数 */
      ++step;
    }
    // 如果穷举完都没找到目标密码，那就是找不到了
    return -1;
  }
};
