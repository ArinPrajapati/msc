#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
  bool isValid(const vector<string> &board, int row, int col) {

    if (row >= board.size() || col >= board.size())
      return false;
    for (int i = 0; i < row; i++) {
      if (board[i][col] == 'Q')
        return false;
    }
    for (int i = 0; i < row; i++) {
      if (col - (row - i) >= 0 && board[i][col - (row - i)] == 'Q')
        return false;
      if (col + (row - i) < board.size() && board[i][col + (row - i)] == 'Q')
        return false;
    }

    for (int i = 0; i < row; i++) {
      if (board[row][i] == 'Q')
        return false;
    }
    return true;
  }

  void backtrack(vector<vector<string>> &result, int n, int row, int col,
                 vector<string> board) {
    if (row == n) {
      result.push_back(board);
      return;
    }

    for (int i = 0; i < n; ++i) {

      if (isValid(board, row, i)) {
        board[row][i] = 'Q';
        backtrack(result, n, row + 1, 0, board);
        board[row][i] = '.';
      }
    }
  };

public:
  vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> result;
    vector<string> board(n, string(n, '.'));
    backtrack(result, n, 0, 0, board);
    return result;
  }
};
