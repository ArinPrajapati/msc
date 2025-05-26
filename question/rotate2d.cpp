#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void tryrotate(vector<vector<int>> &matrix) {
    int m = matrix.size();
    int n = matrix[0].size();

    int i = 0;

    while (i < n) {
      if (i == 0) {
        int temp1 = matrix[0][0], temp2 = matrix[0][m - 1],
            temp3 = matrix[m - 1][m - 1], temp4 = matrix[m - 1][0];

        matrix[0][0] = temp4;
        matrix[0][m - 1] = temp1;
        matrix[m - 1][m - 1] = temp2;
        matrix[m - 1][0] = temp3;

      } else {
        int temp1 = matrix[0][1], temp2 = matrix[m - 2][m - 1],
            temp3 = matrix[m - 1][m - 2], temp4 = matrix[m - 2][0];

        matrix[0][1] = temp4;
        matrix[m-2][m-1] = temp1;
      }
      i++;
      m--;
    }
  }

  void rotate(vector<vector<int>> &matrix){

    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    for(int i = 0;i < n ;++i){
      reverse(matrix[i].begin(),matrix[i].end());
    }
  }

};

int main() {
  vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

  Solution s;
  s.rotate(matrix);

  for (int i = 0; i < matrix.size(); ++i) {
    for (int j = 0; j < matrix[i].size(); ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}
