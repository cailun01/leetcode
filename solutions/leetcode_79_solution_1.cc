/* 79. 单词搜索
给定一个 m x n 二维字符网格 board 和一个字符串单词 word 。如果 word 存在于网格中，返回 true ；否则，返回 false 。
单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。
同一个单元格内的字母不允许被重复使用。

示例 1：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
输出：true

示例 2：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
输出：true

示例 3：
输入：board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
输出：false
*/

/* 方法一：回溯
思路与算法

设函数 check(i,j,k) 表示判断以网格的(i, j)位置出发，能否搜索到单词word[k..]，
其中word[k..] 表示字符串 word 从第 k 个字符开始的后缀子串。
如果能搜索到，则返回 true，反之返回false。函数check(i,j,k) 的执行步骤如下：

如果board[i][j] !=s[k]，当前字符不匹配，直接返回false。
如果当前已经访问到字符串的末尾，且对应字符依然匹配，此时直接返回true。
否则，遍历当前位置的所有相邻位置。如果从某个相邻位置出发，能够搜索到子串word[k+1..]，
则返回true，否则返回 false。
这样，我们对每一个位置 (i,j) 都调用函数check(i,j,0) 进行检查：只要有一处返回 true，
就说明网格中能够找到相应的单词，否则说明不能找到。

为了防止重复遍历相同的位置，需要额外维护一个与 board 等大的visited 数组，
用于标识每个位置是否被访问过。每次遍历相邻位置时，需要跳过已经被访问的位置。
*/

class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, 
               int i, int j, string& s, int k) {
      if (board[i][j] != s[k]) {
        return false;
      } else if (k == s.length() - 1) {
        return true;
      }
      visited[i][j] = true;
      vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
      bool result = false;
      for (const auto& dir: directions) {
        int newi = i + dir.first, newj = j + dir.second;
        if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
          if (!visited[newi][newj]) {
            bool flag = check(board, visited, newi, newj, s, k + 1);
            if (flag) {
              result = true;
              break;
            }
          }
        }
      }
      visited[i][j] = false;
      return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
      int h = board.size(), w = board[0].size();
      vector<vector<int>> visited(h, vector<int>(w));
      for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
          bool flag = check(board, visited, i, j, word, 0);
          if (flag) {
            return true;
          }
        }
      }
      return false;
    }
};
