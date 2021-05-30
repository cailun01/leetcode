#include "headers.h"
/*
编写一个程序，通过填充空格来解决数独问题。

数独的解法需 遵循如下规则：

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

 

示例：

输入：board = 
[["5","3",".",".","7",".",".",".","."],
 ["6",".",".","1","9","5",".",".","."],
 [".","9","8",".",".",".",".","6","."],
 ["8",".",".",".","6",".",".",".","3"],
 ["4",".",".","8",".","3",".",".","1"],
 ["7",".",".",".","2",".",".",".","6"],
 [".","6",".",".",".",".","2","8","."],
 [".",".",".","4","1","9",".",".","5"],
 [".",".",".",".","8",".",".","7","9"]]
输出：
[["5","3","4","6","7","8","9","1","2"],
 ["6","7","2","1","9","5","3","4","8"],
 ["1","9","8","3","4","2","5","6","7"],
 ["8","5","9","7","6","1","4","2","3"],
 ["4","2","6","8","5","3","7","9","1"], 
 ["7","1","3","9","2","4","8","5","6"],
 ["9","6","1","5","3","7","2","8","4"],
 ["2","8","7","4","1","9","6","3","5"],
 ["3","4","5","2","8","6","1","7","9"]]
解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
*/

class Solution {
public:
  bool isValid(vector<vector<char>>& board, int r, int c, char n) {
    for (int i = 0; i < 9; i++) {
      // 判断行是否存在重复
      if (board[r][i] == n) { 
        return false; 
      }
      // 判断列是否存在重复
      if (board[i][c] == n) { 
        return false; 
      }
      // 判断 3 x 3 方框是否存在重复
      if (board[(r/3)*3 + i/3][(c/3)*3 + i%3] == n) {
        return false;
      }
    }
    return true;
  }

  bool backtrack(vector<vector<char>>& board, int i, int j) {
    if (j == 9) {
      // 穷举到最后一列的话就换到下一行重新开始。
      return backtrack(board, i + 1, 0);
    }

    if (i == 9) {
      // 找到一个可行解
      return true;
    }

    if (board[i][j] != '.') {
      // 如果有预设数字，不用我们穷举
      return backtrack(board, i, j + 1);
    }

    for (char ch = '1'; ch <= '9'; ch++) {
      // 如果遇到不合法的数字，就跳过
      if (!isValid(board, i, j, ch)) {
        continue;
      }
      board[i][j] = ch;
      // 如果找到一个可行解，立即结束
      if (backtrack(board, i, j + 1)) {
        return true;
      }
      board[i][j] = '.';
    }
    // 穷举完 1~9，依然没有找到可行解，此路不通
    return false;
  }
  
  void solveSudoku(vector<vector<char>>& board) {
    backtrack(board, 0, 0);
  }
};