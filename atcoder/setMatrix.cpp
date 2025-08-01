#include <iostream>
#include <vector>

using namespace std;

class solution {
public:
  vector<vector<int>> setMatix(vector<vector<int>> matrix) {
    int fcol = 0;
    int frow = 0;

    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {
      if (matrix[i][0] == 0) {
        frow = 1;
      }
    }

    for (int i = 0; i < n; i++) {
      if (matrix[0][i] == 0) {
        fcol = 1;
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][j] == 0) {
          matrix[i][0] = 0;
          matrix[0][j] = 0;
        }
      }
    }

    for (int i = 1; i < m; i++) {
      for (int j = 1; j < n; j++) {
        if (matrix[i][0] == 0 || matrix[0][j] == 0) {
          matrix[i][j] = 0;
        }
      }
    }

    if (frow) {
      for (int i = 0; i < n; i++) {
        matrix[0][i] = 0;
      }
    }

    if (fcol) {
      for (int i = 0; i < m; i++) {
        matrix[i][0] = 0;
      }
    }
    return matrix;
  }
};
int main() {
  solution sol;
  vector<vector<int>> matrix = {{1, 1, 1}, {1, 0, 1}, {1, 1, 1}};
  matrix = sol.setMatix(matrix);
  for (const auto &row : matrix) {
    for (const auto &val : row) {
      cout << val << " ";
    }
    cout << endl;
  }
  return 0;
}
