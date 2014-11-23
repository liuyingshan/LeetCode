/*
  Write a program to solve a Sudoku puzzle by filling the empty cells.
  Empty cells are indicated by the character '.'.
  You may assume that there will be only one unique solution.
*/

class Solution {
public:

    bool isValid(vector<vector<char> > &board, int x, int y) {
        for (int i=0; i<9; i++) {
            if (i != x && board[i][y] == board[x][y]) return false;
        }
        for (int j=0; j<9; j++) {
            if (j != y && board[x][j] == board[x][y]) return false;
        }
        int sx = x / 3 * 3, sy = y / 3 * 3;
        for (int i=sx; i<sx+3; i++) {
            for (int j=sy; j<sy+3; j++) {
                if (i != x && j != y && board[i][j] == board[x][y]) return false;
            }
        }
        return true;
    }
    
    bool solveSudokuDFS(vector<vector<char> > &board, int x, int y) {
        x = x + y / 9;
        y = y % 9;
        if (x == 9) return true;

        if (board[x][y] == '.') {
            for (char k='1'; k<='9'; k++) {
                board[x][y] = k;
                if (isValid(board, x, y) && solveSudokuDFS(board, x, y+1)) return true;
                board[x][y] = '.';
            }
            return false;
        }
        return solveSudokuDFS(board, x, y+1);
    }
    
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuDFS(board, 0, 0);
    }
};
