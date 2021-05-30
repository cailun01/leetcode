/*
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回 n 皇后问题 不同的解决方案的数量。
与51相比，只需要求解方案的数量，不需要给出具体方案。

示例1：
["*" "N" "*" "*"] ["*" "*" "N" "*"]
["*" "*" "*" "N"] ["N" "*" "*" "*"]
["N" "*" "*" "*"] ["*" "*" "*" "N"]
["*" "*" "N" "*"] ["*" "N" "*" "*"]
输入：n = 4
输出：2
解释：
示例 2：

输入：n = 1
输出：1
*/


/*
为了判断一个位置所在的列和两条斜线上是否已经有皇后，使用三个集合 columns、diagonals1和diagonals2
​	
分别记录每一列以及两个方向的每条斜线上是否有皇后。
列的表示法很直观，一共有N列，每一列的下标范围从0到N−1，使用列的下标即可明确表示每一列。

如何表示两个方向的斜线呢？对于每个方向的斜线，需要找到斜线上的每个位置的行下标与列下标之间的关系。

方向一的斜线为从左上到右下方向，同一条斜线上的每个位置满足"行下标与列下标之差"相等，
例如 (0,0) 和 (3,3) 在同一条方向一的斜线上。因此使用行下标与列下标之差即可明确表示每一条方向一的斜线。

方向二的斜线为从右上到左下方向，同一条斜线上的每个位置满足"行下标与列下标之和"相等，
例如 (3,0) 和 (1,2)在同一条方向二的斜线上。因此使用行下标与列下标之和即可明确表示每一条方向二的斜线。

每次放置皇后时，对于每个位置判断其是否在三个集合中，如果三个集合都不包含当前位置，则当前位置是可以放置皇后的位置。
*/
class Solution {
public:
  int totalNQueens(int n) {
    unordered_set<int> columns, diagonals1, diagonals2;
    return backtrack(n, 0, columns, diagonals1, diagonals2);
  }
  int backtrack(int n, int row, unordered_set<int>& columns, 
                unordered_set<int>& diagonals1, 
                unordered_set<int>& diagonals2) {
    if (row == n) {
      return 1;
    } else {
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (columns.find(i) != columns.end()) {
          continue;
        }
        // 从左上到右下，同一条斜线上的每个位置满足"行下标与列下标之差"相等
        int diagonal1 = row - i;
        if (diagonals1.find(diagonal1) != diagonals1.end()) {
          continue;
        }
        // 从右上到左下，同一条斜线上的每个位置满足"行下标与列下标之和"相等
        int diagonal2 = row + i;
        if (diagonals2.find(diagonal2) != diagonals2.end()) {
          continue;
        }
        columns.insert(i);
        diagonals1.insert(diagonal1);
        diagonals2.insert(diagonal2);
        count += backtrack(n, row + 1, columns, diagonals1, diagonals2);
        columns.erase(i);
        diagonals1.erase(diagonal1);
        diagonals2.erase(diagonal2);
      }
      return count;
    }
  }
};
