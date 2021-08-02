#include <iostream>
#include <vector>
#include <cassert>
using namespace std;

class Solution {
public:
    void print(vector<vector<char>>& board) {
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cout << board[i][j] << ' ';
            }
            cout << '\n';
        }
    }

    bool isValid(vector<vector<char>>& board, int r, int c, char ch) {
        for(int i = 0; i < 9; i++){
            if(board[i][c] == ch || board[r][i] == ch)
                return false;
            if(board[3*(r/3)+i/3][3*(c/3)+i%3] == ch)
                return false;
        }
        return true;
    }
    
    bool backtrack(vector<vector<char>>& board) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] != '.') continue;
                for(char c = '1'; c <= '9'; c++) {
                    if(!isValid(board,i,j,c)) continue;
                    board[i][j] = c;
                    if(backtrack(board)) return true;
                    board[i][j] = '.';
                }
                return false;
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};

int main() {
    Solution s;
    vector<vector<char>> board;
    board = 
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    s.solveSudoku(board);
    s.print(board);
}