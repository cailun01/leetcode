#include "headers.h"
// 遍历一次
// https://leetcode-cn.com/problems/valid-sudoku/solution/you-xiao-de-shu-du-by-leetcode/
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 第i行，数字1~9的出现情况, row[i][1]表示
        vector<vector<int>> row (9, vector<int>(9,0)); 
        vector<vector<int>> col (9, vector<int>(9,0)); // 第j列，数字1~9的出现情况
        vector<vector<int>> box (9, vector<int>(9,0)); // 把9*9分为9个3*3的格子
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j] == '.'){
                    continue;
                }
                // 减'1'使得val比board[i][j]对应的数小1
                // 使val的值在0~8之间，与row, col, box的第2维索引一一对应
                int val = board[i][j] - '1'; 
                int box_index = (i/3) * 3 + j/3;
                if (row[i][val] == 0 && col[j][val] == 0 && box[box_index][val] == 0) {
                    row[i][val] = 1;
                    col[j][val] = 1;
                    box[box_index][val] = 1;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};