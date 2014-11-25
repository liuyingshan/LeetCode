/*
  N-Queens

  The n-queens puzzle is the problem of placing n queens on an n¡Án chessboard
  such that no two queens attack each other.
  Given an integer n, return all distinct solutions to the n-queens puzzle.
  Each solution contains a distinct board configuration of the n-queens'
  placement, where 'Q' and '.' both indicate a queen and an empty space
  respectively.

  For example,
  There exist two distinct solutions to the 4-queens puzzle:

 [
  [".Q..",  // Solution 1
   "...Q",
   "Q...",
   "..Q."],

  ["..Q.",  // Solution 2
   "Q...",
   "...Q",
   ".Q.."]
  ]
*/
 
class Solution {
public:
    void generateBoard(vector<vector<string> > &result, vector<int> &place, int n) {
        vector<string> board;
        string row;
        for (int i=0; i<n; i++) {
            row = "";
            for (int j=0; j<n; j++) {
                if (j == place[i]) row += 'Q';
                else row += '.';
            }
            board.push_back(row);
        }
        result.push_back(board);
    }

    bool isValid(vector<int> &place, int last) {
        for (int i=0; i<last; i++) {
            // Check if they are in the same column.
            no two queens share the same row, column, or diagonal
            if (place[last] == place[i]) return false;
            // Check if they are in the same diagonal.
            if (place[last] - place[i] == last - i ||
                place[last] - place[i] == i - last) return false;
        }
        return true;
    }

    void solveQueensDFS(vector<vector<string> > &result,
                        vector<int> &place,
                        int row,
                        int n) {
        if (row == n) {
            generateBoard(result, place, n);
            return;
        }
        for (int column=0; column<n; column++) {
            place[row] = column;
            if (isValid(place, row))
                solveQueensDFS(result, place, row+1, n);
        }
    }

    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
        vector<int> place(n); // place[row] represents the index of column where 'Q' stands.
        solveQueensDFS(result, place, 0, n);
        return result;
    }
};