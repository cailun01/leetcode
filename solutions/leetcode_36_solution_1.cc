#include "headers.h"

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
                            if (num != 0) subgrid_3_3.insert(num);
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