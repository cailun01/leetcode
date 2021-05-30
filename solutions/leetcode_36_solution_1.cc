#include "headers.h"
/* 36 有效的数独
请你判断一个 9x9 的数独是否有效。只需要 根据以下规则 ，验证已经填入的数字是否有效即可。

数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

注意：

一个有效的数独（部分已被填充）不一定是可解的。
只需要根据以上规则，验证已经填入的数字是否有效即可。

示例1：
输入：board = 
[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：true

示例 2：
输入：board = 
[["8","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
输出：false
解释：除了第一行的第一个数字从 5 改为 8 以外，空格内其他数字均与 示例1 相同。 
但由于位于左上角的 3x3 宫内有两个 8 存在, 因此这个数独是无效的。
*/
class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    unordered_set<int> rows;
    int num = 0;
    for (int row = 0; row < 9; ++row) {
      for (int col = 0; col < 9; ++col) {
        char element = board[row][col];
        if (element != '.') {
          num = element - '0';
        } else {
          num = 0;
        }
        // 检查同一行的数
        if (rows.find(num) == rows.end()) {
          if (num != 0) {
            rows.insert(num);
          }
        } else {
          return false;
        }
      }
      rows.clear();
    }
    unordered_set<int> cols;
    for (int col = 0; col < 9; ++col) {
      for (int row = 0; row < 9; ++row) {
        char element = board[row][col]; 
        if (element != '.') {
          num = element - '0';
        } else {
          num = 0;
        }
        // 检查同一列的数
        if (cols.find(num) == cols.end()) {
          if (num != 0) cols.insert(num);
        } else {
          return false;
        }
      }
      cols.clear();
    }
    unordered_set<int> subgrid_3_3; // 3 * 3 subgrid
    for (int row = 0; row < 9; row += 3) {
      for (int col = 0; col < 9; col += 3) {
        for (int i = 0; i < 3; i++) {
          for (int j = 0; j < 3; j++) {
            char element = board[row + i][col + j];
            if (element != '.') {
              num = element - '0';
            } else {
              num = 0;
            }
            if (subgrid_3_3.find(num) == subgrid_3_3.end()) {
              if (num != 0) {
                subgrid_3_3.insert(num);
              }
            } else {
              return false;
            }
          }
        }
        subgrid_3_3.clear();
      }
      subgrid_3_3.clear();
    }
    return true;
  }
};