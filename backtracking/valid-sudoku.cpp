#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m, n;
        vector<bool> colcheck, rowcheck, blockcheck;
        for(int i = 0; i < 9; i++) {
            colcheck.assign(9, 0);
            rowcheck.assign(9, 0);
            blockcheck.assign(9, 0);
            for(int j = 0; j < 9; j++) {
                if(board[i][j] == '.') {}
                else if(colcheck[board[i][j]-'1']) return false;
                else colcheck[board[i][j]-'1'] = true;
                
                if(board[j][i] == '.') {}
                else if(rowcheck[board[j][i]-'1']) return false;
                else rowcheck[board[j][i]-'1'] = true;
                
                m = i / 3 * 3 + j / 3;
                n = i % 3 * 3 + j % 3;
                if(board[m][n] == '.') {}
                else if(blockcheck[board[m][n]-'1']) return false;
                else blockcheck[board[m][n]-'1'] = true;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<vector<char>> board;
    board = 
    {{'8','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    cout << s.isValidSudoku(board) << '\n';
}