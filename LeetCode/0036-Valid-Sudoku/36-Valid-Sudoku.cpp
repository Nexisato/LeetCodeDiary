/*
Description:
Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated 
according to the following rules:
Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.

Note:
A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.
 

*/
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution {

public:
    //思路：类似于桶排序：
    //对于每一行，每个元素只能出现一次
    //对于每一列，每个元素只能出现一次
    //对于每个3阶小方块，每个元素只能出现一次；编码位置为 3*(i/3)+j/3
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0},col[9][9]={0},Matrix[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    int num=board[i][j]-'0'-1;//1-9->0-8
                    row[i][num]++;
                    col[num][j]++;
                    Matrix[j/3+(i/3)*3][num]++;
                    if(row[i][num]==2 || col[num][j]==2 || Matrix[j/3+(i/3)*3][num]==2) return false;
                }
            }
        }
        return true;
    }
};

int main(){
   vector<vector<char>> board={{'8','3','.','.','7','.','.','.','.'},
                                {'6','.','.','1','9','5','.','.','.'},
                                {'.','9','8','.','.','.','.','6','.'},
                                {'8','.','.','.','6','.','.','.','3'},
                                {'4','.','.','8','.','3','.','.','1'},
                                {'7','.','.','.','2','.','.','.','6'},
                                {'.','6','.','.','.','.','2','8','.'},
                                {'.','.','.','4','1','9','.','.','5'},
                                {'.','.','.','.','8','.','.','7','9'}};

    Solution ss;
    cout<<ss.isValidSudoku(board)<<endl;
    return 0;
}