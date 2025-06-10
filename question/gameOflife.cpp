#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector<pair<int, int>> directions = {
            {-1, -1}, {-1, 0}, {-1, 1},
            { 0, -1},          { 0, 1},
            { 1, -1}, { 1, 0}, { 1, 1}
        };

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int ones = 0;
                for (auto [dx, dy] : directions) {
                    int ni = i + dx, nj = j + dy;
                    if (ni >= 0 && ni < n && nj >= 0 && nj < m) {
                        if (board[ni][nj] == 1 || board[ni][nj] == 3) {
                            ones++;
                        }
                    }
                }

                if (board[i][j] == 1) {
                    if (ones < 2 || ones > 3) {
                        board[i][j] = 3;
                    }
                } else {
                    if (ones == 3) {
                        board[i][j] = 2;  
                    }
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 2) board[i][j] = 1;
                else if (board[i][j] == 3) board[i][j] = 0;
            }
        }
    }
};


int main() { return 0; }
